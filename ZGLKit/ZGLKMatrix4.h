//
//  ZGLKMatrix4.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/15/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef ZGLKit_ZGLKMatrix4_h
#define ZGLKit_ZGLKMatrix4_h

union _GLKMatrix4
{
    struct
    {
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
    };
    float m[16];
};
typedef union _GLKMatrix4 ZGLKMatrix4;

extern const ZGLKMatrix4 ZGLKMatrix4Identity;

#endif
