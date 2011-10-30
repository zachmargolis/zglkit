//
//  ZGLKMatrix4.c
//  ZGLKit
//
//  Created by Zach Margolis on 10/29/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "ZGLKMatrix4.h"
#import <assert.h>

const ZGLKMatrix4 ZGLKMatrix4Identity = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
};

ZGLKMatrix4 ZGLKMatrix4Invert(ZGLKMatrix4 matrix, bool *isInvertible) {
    // unimplemented
    assert(false);
    return ZGLKMatrix4Identity;
}

ZGLKMatrix4 ZGLKMatrix4InvertAndTranspose(ZGLKMatrix4 matrix, bool *isInvertible) {
    return ZGLKMatrix4Transpose(ZGLKMatrix4Invert(matrix, isInvertible));
}
