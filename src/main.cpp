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

#include <shader.h>
#include <animator.h>
#include <camera.h>
#include <model_animation.h>

#include <iostream>

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

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
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    
    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
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
    Shader animShader("../src/anim_model.vs", "../src/anim_model.fs");
    
    // load models
    Model animModel("../resources/dog.dae");
    Animation animation("../resources/dog.dae", &animModel);
    Animator animator(&animation);
    

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    int testid = animModel.GetBoneInfoMap()["Armature_Bone_front_left_leg2"].id;

    /*
    // DEBUG
    */
    int debug_flag = 1;
    std::ofstream outfile;
    outfile.open("debug.txt", std::ios::trunc | std::ios::out);


    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        // deltaTime = 0.05;
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
        // std::cout << glm::to_string(transforms[testid]) << std::endl;
        if (debug_flag < 100)
        {
            
            for (int i = 0; i < 16; i++)
                outfile << transforms[testid][(int) i/4][i%4] << std::endl;
            debug_flag++;
        }   
        else
        {
            outfile.close();
            // std::cout << "debug write finished" << std::endl;
        }

        for (int i = 0; i < transforms.size(); ++i)
        {
        //     if (i == testid)
        //     {
        //         transforms[i] *= glm::rotate(transforms[i], (float) glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
        //         std::cout << glm::to_string(transforms[i]) << std::endl;
        //     }
        
            animShader.setMat4("finalBonesMatrices[" + std::to_string(i) + "]", transforms[i]);    
            
        }
//
        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.4f, 0.0f));
        model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
    //    model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
        
        animShader.setMat4("model", model);
        animModel.Draw(animShader);
        
        // glfw: swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
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
