//
//  animdata.h
//  skeletal_animation
//
//  Created by 王柏鈞 on 7/12/2021.
//

#ifndef animdata_h
#define animdata_h

#include <glm/glm.hpp>

struct BoneInfo {
    /* id is index in finalBoneMatrices */
    int id;
    
    /* offset matrix transforms vertex from model space to bone space */
    glm::mat4 offset;
};

#endif /* animdata_h */
