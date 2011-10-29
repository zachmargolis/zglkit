//
//  ZGLKVector4.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/15/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef ZGLKit_ZGLKVector4_h
#define ZGLKit_ZGLKVector4_h

union _GLKVector4
{
    struct { float x, y, z, w; };
    struct { float r, g, b, a; };
    struct { float s, t, p, q; };
    float v[4];
};
typedef union _GLKVector4 ZGLKVector4;

#endif
