//
//  ZZGLKMatrix3.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/15/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef ZGLKit_ZGLKMatrix3_h
#define ZGLKit_ZGLKMatrix3_h

#import "ZGLKQuaternion.h"

union _GLKMatrix2
{
    struct
    {
        float m00, m01;
        float m10, m11;
    };
    float m2[2][2];
    float m[4];
};
typedef union _GLKMatrix2 GLKMatrix2;

union _ZGLKMatrix3
{
    struct
    {
        float m00, m01, m02;
        float m10, m11, m12;
        float m20, m21, m22;
    };
    float m[9];
};
typedef union _ZGLKMatrix3 ZGLKMatrix3;

extern const ZGLKMatrix3 ZGLKMatrix3Identity;


ZGLKMatrix3 ZGLKMatrix3Make(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
ZGLKMatrix3 ZGLKMatrix3MakeAndTranspose(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
ZGLKMatrix3 ZGLKMatrix3MakeRotation(float radians, float x, float y, float z);
ZGLKMatrix3 ZGLKMatrix3MakeScale(float sx, float sy, float sz);
ZGLKMatrix3 ZGLKMatrix3MakeWithArray(float values[9]);
ZGLKMatrix3 ZGLKMatrix3MakeWithArrayAndTranspose(float values[9]);
ZGLKMatrix3 ZGLKMatrix3MakeWithColumns(ZGLKVector3 column0, ZGLKVector3 column1, ZGLKVector3 column2);
ZGLKMatrix3 ZGLKMatrix3MakeWithQuaternion(ZGLKQuaternion quaternion);
ZGLKMatrix3 ZGLKMatrix3MakeWithRows(ZGLKVector3 row0, ZGLKVector3 row1, ZGLKVector3 row2);
ZGLKMatrix3 ZGLKMatrix3MakeXRotation(float radians);
ZGLKMatrix3 ZGLKMatrix3MakeYRotation(float radians);
ZGLKMatrix3 ZGLKMatrix3MakeZRotation(float radians);
ZGLKMatrix3 ZGLKMatrix3Multiply(ZGLKMatrix3 matrixLeft, ZGLKMatrix3 matrixRight);
ZGLKVector3 ZGLKMatrix3MultiplyVector3(ZGLKMatrix3 matrixLeft, ZGLKVector3 vectorRight);
void ZGLKMatrix3MultiplyVector3Array(ZGLKMatrix3 matrix, ZGLKVector3 *vectors, size_t vectorCount);
ZGLKMatrix3 ZGLKMatrix3Rotate (ZGLKMatrix3 matrix, float radians, float x, float y, float z);
ZGLKMatrix3 ZGLKMatrix3RotateWithVector3(ZGLKMatrix3 matrix, float radians, ZGLKVector3 axisVector);
ZGLKMatrix3 ZGLKMatrix3RotateWithVector4(ZGLKMatrix3 matrix, float radians, ZGLKVector4 axisVector);
ZGLKMatrix3 ZGLKMatrix3RotateX(ZGLKMatrix3 matrix, float radians);
ZGLKMatrix3 ZGLKMatrix3RotateY(ZGLKMatrix3 matrix, float radians);
ZGLKMatrix3 ZGLKMatrix3RotateZ(ZGLKMatrix3 matrix, float radians);
ZGLKMatrix3 ZGLKMatrix3Scale(ZGLKMatrix3 matrix, float sx, float sy, float sz);
ZGLKMatrix3 ZGLKMatrix3ScaleWithVector4(ZGLKMatrix3 matrix, ZGLKVector4 scaleVector);
ZGLKMatrix3 ZGLKMatrix3SetColumn(ZGLKMatrix3 matrix, int column, ZGLKVector3 vector);
ZGLKMatrix3 ZGLKMatrix3SetRow(ZGLKMatrix3 matrix, int row, ZGLKVector3 vector);
ZGLKMatrix3 ZGLKMatrix3Subtract(ZGLKMatrix3 matrixLeft, ZGLKMatrix3 matrixRight);
ZGLKMatrix3 ZGLKMatrix3Transpose(ZGLKMatrix3 matrix);


#endif
