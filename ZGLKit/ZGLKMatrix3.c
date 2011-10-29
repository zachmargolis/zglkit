//
//  ZGLKMatrix3.c
//  ZGLKit
//
//  Created by Zach Margolis on 10/29/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "ZGLKMatrix3.h"
#include <assert.h>


ZGLKMatrix3 ZGLKMatrix3Invert(ZGLKMatrix3 matrix, bool *isInvertible) {
    // unimplemented
    assert(false);
    return ZGLKMatrix3Identity;
}

ZGLKMatrix3 ZGLKMatrix3InvertAndTranspose(ZGLKMatrix3 matrix, bool *isInvertible) {
    return ZGLKMatrix3Transpose(ZGLKMatrix3Invert(matrix, isInvertible));
}
