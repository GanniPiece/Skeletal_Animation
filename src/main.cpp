//
//  main.cpp
//  skeletal_animation
//
//  Created by 王柏鈞 on 3/12/2021.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <Utils/Global.hpp>
#include <Utils/Compilers.hpp>
#include <Utils/StringFormat/StringFormat.hpp>

#include <shader.h>
#include <animator.h>
#include <camera.h>
#include <model_animation.h>

#include <iostream>

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void initializeImgui(GLFWwindow*);
void windowImguiGeneralSetting();
const char* const* convert_vector_to_cstr_array(std::vector<std::string>);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// animation
bool isPlayingAnimation = false;
bool isPlayingSingleBone = false;
std::vector<std::string> single_animation_items;
const char* const* cstr_animation_items = nullptr;
int item_current = 0;


int main(int argc, const char * argv[]) {
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hw3 Skeleton Animation", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    
    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    stbi_set_flip_vertically_on_load(true);
    
    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    // build and compile shaders
    Shader animShader
                ("../../../src/anim_model.vs",
                 "../../../src/anim_model.fs");
    
    // load models
    Model animModel("../../..//resources/dog.dae");
    Animation animation("../../../resources/dog.dae", &animModel);
    Animator animator(&animation);
        
    // imgui
    initializeImgui(window);
    single_animation_items = animation.GetKeyframeBones();
    cstr_animation_items = convert_vector_to_cstr_array(single_animation_items);
    std::cout << cstr_animation_items[0] << std::endl;

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        float currentFrame = glfwGetTime();
        
        if (!isPlayingAnimation)
        {
            deltaTime = 0.0f;
        }
        else
        {
            if (single_animation_items[item_current] != "None")
            {
                isPlayingSingleBone = true;
                animator.setCurrentPlayedBone(single_animation_items[item_current]);
            }
            else
                isPlayingSingleBone = false;
            
            deltaTime = currentFrame - lastFrame;
        }
        lastFrame = currentFrame;
        
        
        processInput(window);
        animator.UpdateAnimation(deltaTime);
        
        // render
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //enable shader before setting uniforms
        animShader.use();
        
        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float) SCR_WIDTH / (float) SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        animShader.setMat4("projection", projection);
        animShader.setMat4("view", view);
        
        auto transforms = animator.GetFinalBoneMatrices();

        for (int i = 0; i < transforms.size(); ++i)
        {
            animShader.setMat4("finalBonesMatrices[" + std::to_string(i) + "]", transforms[i]);    
        }

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.4f, 0.0f));
        model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
        
        animShader.setMat4("model", model);
        animModel.Draw(animShader);
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        windowImguiGeneralSetting();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // glfw: swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

const char* const* convert_vector_to_cstr_array(std::vector<std::string> s)
{
    int length = s.size();
    char** p = new char*[length];
    for (int i = 0; i < length; i++)
    {
        p[i] = new char[s[i].size()+1];
        std::strcpy(p[i], s[i].c_str());
    }
    return p;
}

void windowImguiGeneralSetting()
{
    ImGui::Begin("Setting");
    if(ImGui::Button("Play animation"))
    {
        isPlayingAnimation = !isPlayingAnimation;
    }
    
    ImGui::Combo("Select Single Bone", &item_current, cstr_animation_items, single_animation_items.size());
    
//    ImGui::Combo("test", &item_current, t, 3);
    ImGui::End();
}


void initializeImgui(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGui::StyleColorsDark();
    
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void processInput(GLFWwindow* window)
{
    // should exit
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    
    lastX = xpos;
    lastY = ypos;
    
    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}
