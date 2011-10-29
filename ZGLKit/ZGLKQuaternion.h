//
//  ZGLKQuaternion.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/15/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef ZGLKit_ZGLKQuaternion_h
#define ZGLKit_ZGLKQuaternion_h

union _GLKQuaternion
{
    struct { ZGLKVector3 v; float s; };
    struct { float x, y, z, w; };
    float q[4];
}
typedef union _GLKQuaternion ZGLKQuaternion;

extern const ZGLKQuaternion ZGLKQuaternionIdentity;

#endif
