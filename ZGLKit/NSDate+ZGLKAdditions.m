//
//  NSDate+ZGLKAdditions.m
//  ZGLKit
//
//  Created by Zach Margolis on 10/13/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "NSDate+ZGLKAdditions.h"

@implementation NSDate (ZGLKAdditions)

+ (NSTimeInterval)timeIntervalSinceDate:(NSDate *)date;
{
    if (!date) {
        return 0.0;
    }
    
    return -1.0 * [NSDate timeIntervalSinceDate:date];
}

@end
