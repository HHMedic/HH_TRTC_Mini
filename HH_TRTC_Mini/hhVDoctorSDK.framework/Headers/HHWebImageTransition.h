/*
 * This file is part of the HHWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "HHWebImageCompat.h"

#if HH_UIKIT || HH_MAC
#import "HHImageCache.h"

// This class is used to provide a transition animation after the view category load image finished. Use this on `sd_imageTransition` in UIView+WebCache.h
// for UIKit(iOS & tvOS), we use `+[UIView transitionWithView:duration:options:animations:completion]` for transition animation.
// for AppKit(macOS), we use `+[NSAnimationContext runAnimationGroup:completionHandler:]` for transition animation. You can call `+[NSAnimationContext currentContext]` to grab the context during animations block.
// These transition are provided for basic usage. If you need complicated animation, consider to directly use Core Animation or use `HHWebImageAvoidAutoSetImage` and implement your own after image load finished.

#if HH_UIKIT
typedef UIViewAnimationOptions HHWebImageAnimationOptions;
#else
typedef NS_OPTIONS(NSUInteger, HHWebImageAnimationOptions) {
    HHWebImageAnimationOptionAllowsImplicitAnimation = 1 << 0, // specify `allowsImplicitAnimation` for the `NSAnimationContext`
};
#endif

typedef void (^HHWebImageTransitionPreparesBlock)(__kindof UIView * _Nonnull view, UIImage * _Nullable image, NSData * _Nullable imageData, HHImageCacheType cacheType, NSURL * _Nullable imageURL);
typedef void (^HHWebImageTransitionAnimationsBlock)(__kindof UIView * _Nonnull view, UIImage * _Nullable image);
typedef void (^HHWebImageTransitionCompletionBlock)(BOOL finished);

@interface HHWebImageTransition : NSObject

/**
 By default, we set the image to the view at the beginning of the animtions. You can disable this and provide custom set image process
 */
@property (nonatomic, assign) BOOL avoidAutoSetImage;
/**
 The duration of the transition animation, measured in seconds. Defaults to 0.5.
 */
@property (nonatomic, assign) NSTimeInterval duration;
/**
 The timing function used for all animations within this transition animation (macOS).
 */
@property (nonatomic, strong, nullable) CAMediaTimingFunction *timingFunction NS_AVAILABLE_MAC(10_7);
/**
 A mask of options indicating how you want to perform the animations.
 */
@property (nonatomic, assign) HHWebImageAnimationOptions animationOptions;
/**
 A block object to be executed before the animation sequence starts.
 */
@property (nonatomic, copy, nullable) HHWebImageTransitionPreparesBlock prepares;
/**
 A block object that contains the changes you want to make to the specified view.
 */
@property (nonatomic, copy, nullable) HHWebImageTransitionAnimationsBlock animations;
/**
 A block object to be executed when the animation sequence ends.
 */
@property (nonatomic, copy, nullable) HHWebImageTransitionCompletionBlock completion;

@end

// Convenience way to create transition. Remember to specify the duration if needed.
// for UIKit, these transition just use the correspond `animationOptions`
// for AppKit, these transition use Core Animation in `animations`. So your view must be layer-backed. Set `wantsLayer = YES` before you apply it.

@interface HHWebImageTransition (Conveniences)

// class property is available in Xcode 8. We will drop the Xcode 7.3 support in 5.x
#if __has_feature(objc_class_property)
/// Fade transition.
@property (nonatomic, class, nonnull, readonly) HHWebImageTransition *fadeTransition;
/// Flip from left transition.
@property (nonatomic, class, nonnull, readonly) HHWebImageTransition *flipFromLeftTransition;
/// Flip from right transition.
@property (nonatomic, class, nonnull, readonly) HHWebImageTransition *flipFromRightTransition;
/// Flip from top transition.
@property (nonatomic, class, nonnull, readonly) HHWebImageTransition *flipFromTopTransition;
/// Flip from bottom transition.
@property (nonatomic, class, nonnull, readonly) HHWebImageTransition *flipFromBottomTransition;
/// Curl up transition.
@property (nonatomic, class, nonnull, readonly) HHWebImageTransition *curlUpTransition;
/// Curl down transition.
@property (nonatomic, class, nonnull, readonly) HHWebImageTransition *curlDownTransition;
#else
+ (nonnull instancetype)fadeTransition;
+ (nonnull instancetype)flipFromLeftTransition;
+ (nonnull instancetype)flipFromRightTransition;
+ (nonnull instancetype)flipFromTopTransition;
+ (nonnull instancetype)flipFromBottomTransition;
+ (nonnull instancetype)curlUpTransition;
+ (nonnull instancetype)curlDownTransition;
#endif

@end

#endif
