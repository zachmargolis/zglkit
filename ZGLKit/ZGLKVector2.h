//
//  ZGLKVector2.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/15/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef ZGLKit_ZGLKVector2_h
#define ZGLKit_ZGLKVector2_h

union _GLKVector2
{
    struct { float x, y; };
    struct { float s, t; };
    float v[2];
};
typedef union _GLKVector2 ZGLKVector2;

#endif
