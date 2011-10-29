//
//  ZGLKMathTypes.h
//  ZGLKit
//
//  Based directly on GLKMathTypes.h from Apple, Inc.
//

#ifndef ZGLKit_ZGLKMathTypes_h
#define ZGLKit_ZGLKMathTypes_h

#ifdef __cplusplus
extern "C" {
#endif
    
#if defined(__STRICT_ANSI__)
struct _GLKMatrix2
{
    float m[4];
};
typedef struct _GLKMatrix2 ZGLKMatrix2;
#else
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
typedef union _GLKMatrix2 ZGLKMatrix2;
#endif

#if defined(__STRICT_ANSI__)
struct _GLKMatrix3
{
    float m[9];
};
typedef struct _GLKMatrix3 ZGLKMatrix3; 
#else
union _GLKMatrix3
{
    struct
    {
        float m00, m01, m02;
        float m10, m11, m12;
        float m20, m21, m22;
    };
    float m[9];
};
typedef union _GLKMatrix3 ZGLKMatrix3;
#endif

/*
 m30, m31, and m32 correspond to the translation values tx, ty, and tz, respectively.
 m[12], m[13], and m[14] correspond to the translation values tx, ty, and tz, respectively.
 */
#if defined(__STRICT_ANSI__)
struct _GLKMatrix4
{
    float m[16];
} __attribute__((aligned(16)));
typedef struct _GLKMatrix4 ZGLKMatrix4;    
#else
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
} __attribute__((aligned(16)));
typedef union _GLKMatrix4 ZGLKMatrix4;
#endif

#if defined(__STRICT_ANSI__)
struct _GLKVector2
{
    float v[2];
};
typedef struct _GLKVector2 ZGLKVector2;
#else
union _GLKVector2
{
    struct { float x, y; };
    struct { float s, t; };
    float v[2];
};
typedef union _GLKVector2 ZGLKVector2;
#endif

#if defined(__STRICT_ANSI__)
struct _GLKVector3
{
    float v[3];
};
typedef struct _GLKVector3 ZGLKVector3;   
#else
union _GLKVector3
{
    struct { float x, y, z; };
    struct { float r, g, b; };
    struct { float s, t, p; };
    float v[3];
};
typedef union _GLKVector3 ZGLKVector3;
#endif

#if defined(__STRICT_ANSI__)
struct _GLKVector4
{
    float v[4];
} __attribute__((aligned(16)));
typedef struct _GLKVector4 ZGLKVector4;  
#else
union _GLKVector4
{
    struct { float x, y, z, w; };
    struct { float r, g, b, a; };
    struct { float s, t, p, q; };
    float v[4];
} __attribute__((aligned(16)));
typedef union _GLKVector4 ZGLKVector4;
#endif

/*
 x, y, and z represent the imaginary values.
 Vector v represents the imaginary values.
 q[0], q[1], and q[2] represent the imaginary values.
 */
#if defined(__STRICT_ANSI__)
struct _GLKQuaternion
{
    float q[4];
} __attribute__((aligned(16)));
typedef struct _GLKQuaternion ZGLKQuaternion;
#else
union _GLKQuaternion
{
    struct { ZGLKVector3 v; float s; };
    struct { float x, y, z, w; };
    float q[4];
} __attribute__((aligned(16)));
typedef union _GLKQuaternion ZGLKQuaternion;    
#endif

#ifdef __cplusplus
}
#endif

#endif // ZGLKit_ZGLKMathTypes_h
