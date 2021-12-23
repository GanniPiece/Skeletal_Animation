//
//  animator.h
//  skeletal_animation
//
//  Created by 王柏鈞 on 3/12/2021.
//

#ifndef animator_h
#define animator_h

#include <glm/glm.hpp>
#include <map>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include "animation.h"
#include "bone.h"

extern int item_current;
extern bool isPlayingAnimation;
extern bool isPlayingSingleBone;
extern const char* const* cstr_animation_items;

class Animator
{
public:
    Animator (Animation* animation)
    {
        m_CurrentTime = 0.0;
        m_CurrentAnimation = animation;
        
        m_FinalBoneMatrices.reserve(100);
        
        for (int i = 0; i < 100; i++)
            m_FinalBoneMatrices.push_back(glm::mat4(1.0f));
    }
    
    void UpdateAnimation(float dt)
    {
        m_DeltaTime = dt;
        if (m_CurrentAnimation)
        {
            m_CurrentTime += m_CurrentAnimation->GetTicksPerSecond() * dt;
            m_CurrentTime = fmod(m_CurrentTime, m_CurrentAnimation->GetDuration());
            CalculateBoneTransform(&m_CurrentAnimation->GetRootNode(), glm::mat4(1.0f));
        }
    }
    
    void PlayAnimation(Animation* pAnimation)
    {
        m_CurrentAnimation = pAnimation;
        m_CurrentTime = 0;
    }
    
    void CalculateBoneTransform(const AssimpNodeData* node, glm::mat4 parentTransform)
    {
        std::string nodeName = node->name;
        glm::mat4 nodeTransform = node->transformation;
        
        Bone* bone = m_CurrentAnimation->FindBone(nodeName);
        if (bone)
        {
            if (isPlayingAnimation)
            {
                if ((!isPlayingSingleBone) || (isPlayingSingleBone && currentPlayedBone == bone->GetBoneName()))
                {
                    bone->Update(m_CurrentTime);
                    nodeTransform = bone->GetLocalTransform();
                }
            }
        }

        glm::mat4 globalTransformation = parentTransform * nodeTransform;

        auto boneInfoMap = m_CurrentAnimation->GetBoneIDMap();
        if (boneInfoMap.find(nodeName) != boneInfoMap.end())
        {
            std::string newNode = nodeName;
            int index = boneInfoMap[newNode].id;
            glm::mat4 offset = boneInfoMap[newNode].offset;

            m_FinalBoneMatrices[index] = globalTransformation * offset;
        }

        for (int i = 0; i < node->childrenCount; i++)
        {
            CalculateBoneTransform(&node->children[i], globalTransformation);
        }
        
    }
    std::vector<glm::mat4>& GetFinalBoneMatrices()
    {
        return m_FinalBoneMatrices;
    }
     
    void setCurrentPlayedBone(std::string bone)
    {
        currentPlayedBone = bone;
    }
    
private:
    std::vector<glm::mat4> m_FinalBoneMatrices;
    std::string currentPlayedBone;
    Animation* m_CurrentAnimation;
    float m_CurrentTime;
    float m_DeltaTime;
};

#endif /* animator_h */
