//
//  ZGLKViewController.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol ZGKLViewControllerDelegate;


@interface ZGLKViewController : UIViewController

@property (nonatomic, assign) id <ZGKLViewControllerDelegate> delegate;
@property (nonatomic, readonly) NSInteger framesDisplayed;
@property (nonatomic, readonly) NSInteger framesPerSecond;
@property (nonatomic, getter=isPaused) BOOL paused;
@property (nonatomic) BOOL pauseOnWillResignActive;
@property (nonatomic) NSInteger preferredFramesPerSecond;
@property (nonatomic) BOOL resumeOnDidBecomeActive;
@property (nonatomic, readonly) NSTimeInterval timeSinceFirstResume;
@property (nonatomic, readonly) NSTimeInterval timeSinceLastDraw;
@property (nonatomic, readonly) NSTimeInterval timeSinceLastResume;
@property (nonatomic, readonly) NSTimeInterval timeSinceLastUpdate;

@end


@protocol ZGKLViewControllerDelegate <NSObject>

- (void)glkViewControllerUpdate:(ZGLKViewController *)controller;

@optional

- (void)glkViewController:(ZGLKViewController *)controller willPause:(BOOL)pause;

@end
