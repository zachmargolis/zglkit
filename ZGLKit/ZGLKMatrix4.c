//
//  ZGLKMatrix4.c
//  ZGLKit
//
//  Created by Zach Margolis on 10/29/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "ZGLKMatrix4.h"
#import <assert.h>

ZGLKMatrix4 ZGLKMatrix4Invert(ZGLKMatrix4 matrix, bool *isInvertible) {
    // unimplemented
    assert(false);
    return ZGLKMatrix4Identity;
}

ZGLKMatrix4 ZGLKMatrix4InvertAndTranspose(ZGLKMatrix4 matrix, bool *isInvertible) {
    return ZGLKMatrix4Transpose(ZGLKMatrix4Invert(matrix, isInvertible));
}
