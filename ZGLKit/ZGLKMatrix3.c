//
//  ZGLKMatrix3.c
//  ZGLKit
//
//  Created by Zach Margolis on 10/29/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "ZGLKMatrix3.h"
#include <assert.h>

const ZGLKMatrix3 ZGLKMatrix3Identity = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
};

ZGLKMatrix3 ZGLKMatrix3Invert(ZGLKMatrix3 matrix, bool *isInvertible) {
    GLfloat determinant = (matrix.m00 * (matrix.m11 * matrix.m22 - matrix.m12 * matrix.m21)) + (matrix.m01 * (matrix.m12 * matrix.m20 - matrix.m22 * matrix.m10)) + (matrix.m02 * (matrix.m10 * matrix.m21 - matrix.m11 *matrix.m20));
    bool canInvert = determinant != 0.0f;
    if (isInvertible) {
        *isInvertible = canInvert;
    }
    
    if (!canInvert) {
        return ZGLKMatrix3Identity;
    }
    
    return ZGLKMatrix3Scale(ZGLKMatrix3Transpose(matrix), determinant, determinant, determinant);
}

ZGLKMatrix3 ZGLKMatrix3InvertAndTranspose(ZGLKMatrix3 matrix, bool *isInvertible) {
    return ZGLKMatrix3Transpose(ZGLKMatrix3Invert(matrix, isInvertible));
}
