//
//  ZGLKVector3.h
//  ZGLKit
//
//  Based directly on GLKVector3.h from Apple, Inc.
//

#ifndef ZGLKit_ZGLKVector3_h
#define ZGLKit_ZGLKVector3_h

#include <stdbool.h>
#include <math.h>

#include <ZGLKit/ZGLKMathTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark -
#pragma mark Prototypes
#pragma mark -

static __inline__ ZGLKVector3 ZGLKVector3Make(float x, float y, float z);
static __inline__ ZGLKVector3 ZGLKVector3MakeWithArray(float values[3]);

static __inline__ ZGLKVector3 ZGLKVector3Negate(ZGLKVector3 vector);

static __inline__ ZGLKVector3 ZGLKVector3Add(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);
static __inline__ ZGLKVector3 ZGLKVector3Subtract(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);
static __inline__ ZGLKVector3 ZGLKVector3Multiply(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);
static __inline__ ZGLKVector3 ZGLKVector3Divide(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);

static __inline__ ZGLKVector3 ZGLKVector3AddScalar(ZGLKVector3 vector, float value);
static __inline__ ZGLKVector3 ZGLKVector3SubtractScalar(ZGLKVector3 vector, float value);
static __inline__ ZGLKVector3 ZGLKVector3MultiplyScalar(ZGLKVector3 vector, float value);
static __inline__ ZGLKVector3 ZGLKVector3DivideScalar(ZGLKVector3 vector, float value);

/*
 Returns a vector whose elements are the larger of the corresponding elements of the vector arguments.
 */
static __inline__ ZGLKVector3 ZGLKVector3Maximum(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);
/*
 Returns a vector whose elements are the smaller of the corresponding elements of the vector arguments.
 */
static __inline__ ZGLKVector3 ZGLKVector3Minimum(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);

/*
 Returns true if all of the first vector's elements are equal to all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector3AllEqualToVector3(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);
/*
 Returns true if all of the vector's elements are equal to the provided value.
 */
static __inline__ bool ZGLKVector3AllEqualToScalar(ZGLKVector3 vector, float value);
/*
 Returns true if all of the first vector's elements are greater than all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector3AllGreaterThanVector3(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);
/*
 Returns true if all of the vector's elements are greater than the provided value.
 */
static __inline__ bool ZGLKVector3AllGreaterThanScalar(ZGLKVector3 vector, float value);
/*
 Returns true if all of the first vector's elements are greater than or equal to all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector3AllGreaterThanOrEqualToVector3(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);
/*
 Returns true if all of the vector's elements are greater than or equal to the provided value.
 */
static __inline__ bool ZGLKVector3AllGreaterThanOrEqualToScalar(ZGLKVector3 vector, float value);

static __inline__ ZGLKVector3 ZGLKVector3Normalize(ZGLKVector3 vector);

static __inline__ float ZGLKVector3DotProduct(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);
static __inline__ float ZGLKVector3Length(ZGLKVector3 vector);
static __inline__ float ZGLKVector3Distance(ZGLKVector3 vectorStart, ZGLKVector3 vectorEnd);

static __inline__ ZGLKVector3 ZGLKVector3Lerp(ZGLKVector3 vectorStart, ZGLKVector3 vectorEnd, float t);

static __inline__ ZGLKVector3 ZGLKVector3CrossProduct(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight);

/*
 Project the vector, vectorToProject, onto the vector, projectionVector.
 */
static __inline__ ZGLKVector3 ZGLKVector3Project(ZGLKVector3 vectorToProject, ZGLKVector3 projectionVector);

#pragma mark -
#pragma mark Implementations
#pragma mark -

static __inline__ ZGLKVector3 ZGLKVector3Make(float x, float y, float z)
{
    ZGLKVector3 v = { x, y, z };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3MakeWithArray(float values[3])
{
    ZGLKVector3 v = { values[0], values[1], values[2] };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3Negate(ZGLKVector3 vector)
{
    ZGLKVector3 v = { -vector.v[0], -vector.v[1], -vector.v[2] };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3Add(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    ZGLKVector3 v = { vectorLeft.v[0] + vectorRight.v[0],
        vectorLeft.v[1] + vectorRight.v[1],
        vectorLeft.v[2] + vectorRight.v[2] };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3Subtract(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    ZGLKVector3 v = { vectorLeft.v[0] - vectorRight.v[0],
        vectorLeft.v[1] - vectorRight.v[1],
        vectorLeft.v[2] - vectorRight.v[2] };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3Multiply(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    ZGLKVector3 v = { vectorLeft.v[0] * vectorRight.v[0],
        vectorLeft.v[1] * vectorRight.v[1],
        vectorLeft.v[2] * vectorRight.v[2] };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3Divide(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    ZGLKVector3 v = { vectorLeft.v[0] / vectorRight.v[0],
        vectorLeft.v[1] / vectorRight.v[1],
        vectorLeft.v[2] / vectorRight.v[2] };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3AddScalar(ZGLKVector3 vector, float value)
{
    ZGLKVector3 v = { vector.v[0] + value,
        vector.v[1] + value,
        vector.v[2] + value };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3SubtractScalar(ZGLKVector3 vector, float value)
{
    ZGLKVector3 v = { vector.v[0] - value,
        vector.v[1] - value,
        vector.v[2] - value };
    return v;    
}

static __inline__ ZGLKVector3 ZGLKVector3MultiplyScalar(ZGLKVector3 vector, float value)
{
    ZGLKVector3 v = { vector.v[0] * value,
        vector.v[1] * value,
        vector.v[2] * value };
    return v;   
}

static __inline__ ZGLKVector3 ZGLKVector3DivideScalar(ZGLKVector3 vector, float value)
{
    ZGLKVector3 v = { vector.v[0] / value,
        vector.v[1] / value,
        vector.v[2] / value };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3Maximum(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    ZGLKVector3 max = vectorLeft;
    if (vectorRight.v[0] > vectorLeft.v[0])
        max.v[0] = vectorRight.v[0];
    if (vectorRight.v[1] > vectorLeft.v[1])
        max.v[1] = vectorRight.v[1];
    if (vectorRight.v[2] > vectorLeft.v[2])
        max.v[2] = vectorRight.v[2];
    return max;
}

static __inline__ ZGLKVector3 ZGLKVector3Minimum(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    ZGLKVector3 min = vectorLeft;
    if (vectorRight.v[0] < vectorLeft.v[0])
        min.v[0] = vectorRight.v[0];
    if (vectorRight.v[1] < vectorLeft.v[1])
        min.v[1] = vectorRight.v[1];
    if (vectorRight.v[2] < vectorLeft.v[2])
        min.v[2] = vectorRight.v[2];
    return min;
}

static __inline__ bool ZGLKVector3AllEqualToVector3(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    bool compare = false;
    if (vectorLeft.v[0] == vectorRight.v[0] &&
        vectorLeft.v[1] == vectorRight.v[1] &&
        vectorLeft.v[2] == vectorRight.v[2])
        compare = true;
    return compare;
}

static __inline__ bool ZGLKVector3AllEqualToScalar(ZGLKVector3 vector, float value)
{
    bool compare = false;
    if (vector.v[0] == value &&
        vector.v[1] == value &&
        vector.v[2] == value)
        compare = true;
    return compare;
}

static __inline__ bool ZGLKVector3AllGreaterThanVector3(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    bool compare = false;
    if (vectorLeft.v[0] > vectorRight.v[0] &&
        vectorLeft.v[1] > vectorRight.v[1] &&
        vectorLeft.v[2] > vectorRight.v[2])
        compare = true;
    return compare;
}

static __inline__ bool ZGLKVector3AllGreaterThanScalar(ZGLKVector3 vector, float value)
{
    bool compare = false;
    if (vector.v[0] > value &&
        vector.v[1] > value &&
        vector.v[2] > value)
        compare = true;
    return compare;
}

static __inline__ bool ZGLKVector3AllGreaterThanOrEqualToVector3(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    bool compare = false;
    if (vectorLeft.v[0] >= vectorRight.v[0] &&
        vectorLeft.v[1] >= vectorRight.v[1] &&
        vectorLeft.v[2] >= vectorRight.v[2])
        compare = true;
    return compare;
}

static __inline__ bool ZGLKVector3AllGreaterThanOrEqualToScalar(ZGLKVector3 vector, float value)
{
    bool compare = false;
    if (vector.v[0] >= value &&
        vector.v[1] >= value &&
        vector.v[2] >= value)
        compare = true;
    return compare;
}

static __inline__ ZGLKVector3 ZGLKVector3Normalize(ZGLKVector3 vector)
{
    float scale = 1.0f / ZGLKVector3Length(vector);
    ZGLKVector3 v = { vector.v[0] * scale, vector.v[1] * scale, vector.v[2] * scale };
    return v;
}

static __inline__ float ZGLKVector3DotProduct(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    return vectorLeft.v[0] * vectorRight.v[0] + vectorLeft.v[1] * vectorRight.v[1] + vectorLeft.v[2] * vectorRight.v[2];
}

static __inline__ float ZGLKVector3Length(ZGLKVector3 vector)
{
    return sqrt(vector.v[0] * vector.v[0] + vector.v[1] * vector.v[1] + vector.v[2] * vector.v[2]);
}

static __inline__ float ZGLKVector3Distance(ZGLKVector3 vectorStart, ZGLKVector3 vectorEnd)
{
    return ZGLKVector3Length(ZGLKVector3Subtract(vectorEnd, vectorStart));
}

static __inline__ ZGLKVector3 ZGLKVector3Lerp(ZGLKVector3 vectorStart, ZGLKVector3 vectorEnd, float t)
{
    ZGLKVector3 v = { vectorStart.v[0] + ((vectorEnd.v[0] - vectorStart.v[0]) * t),
        vectorStart.v[1] + ((vectorEnd.v[1] - vectorStart.v[1]) * t),
        vectorStart.v[2] + ((vectorEnd.v[2] - vectorStart.v[2]) * t) };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3CrossProduct(ZGLKVector3 vectorLeft, ZGLKVector3 vectorRight)
{
    ZGLKVector3 v = { vectorLeft.v[1] * vectorRight.v[2] - vectorLeft.v[2] * vectorRight.v[1],
        vectorLeft.v[2] * vectorRight.v[0] - vectorLeft.v[0] * vectorRight.v[2],
        vectorLeft.v[0] * vectorRight.v[1] - vectorLeft.v[1] * vectorRight.v[0] };
    return v;
}

static __inline__ ZGLKVector3 ZGLKVector3Project(ZGLKVector3 vectorToProject, ZGLKVector3 projectionVector)
{
    float scale = ZGLKVector3DotProduct(projectionVector, vectorToProject) / ZGLKVector3DotProduct(projectionVector, projectionVector);
    ZGLKVector3 v = ZGLKVector3MultiplyScalar(projectionVector, scale);
    return v;
}

#ifdef __cplusplus
}
#endif

#endif // ZGLKit_ZGLKVector3_h
