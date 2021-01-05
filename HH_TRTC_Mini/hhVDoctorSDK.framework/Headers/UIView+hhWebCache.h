/*
 * This file is part of the HHWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "HHWebImageCompat.h"

#if HH_UIKIT || HH_MAC

#import "HHWebImageManager.h"
#import "HHWebImageTransition.h"

/**
 A Dispatch group to maintain setImageBlock and completionBlock. This key should be used only internally and may be changed in the future. (dispatch_group_t)
 */
FOUNDATION_EXPORT NSString * _Nonnull const HHWebImageInternalSetImageGroupKey;
/**
 A HHWebImageManager instance to control the image download and cache process using in UIImageView+WebCache category and likes. If not provided, use the shared manager (HHWebImageManager)
 */
FOUNDATION_EXPORT NSString * _Nonnull const HHWebImageExternalCustomManagerKey;
/**
 The value specify that the image progress unit count cannot be determined because the progressBlock is not been called.
 */
FOUNDATION_EXPORT const int64_t HHWebImageProgressUnitCountUnknown; /* 1LL */

typedef void(^HHSetImageBlock)(UIImage * _Nullable image, NSData * _Nullable imageData);

@interface UIView (hhWebCache)

/**
 * Get the current image URL.
 *
 * @note Note that because of the limitations of categories this property can get out of sync if you use setImage: directly.
 */
- (nullable NSURL *)HH_imageURL;

/**
 * The current image loading progress associated to the view. The unit count is the received size and excepted size of download.
 * The `totalUnitCount` and `completedUnitCount` will be reset to 0 after a new image loading start (change from current queue). And they will be set to `HHWebImageProgressUnitCountUnknown` if the progressBlock not been called but the image loading success to mark the progress finished (change from main queue).
 * @note You can use Key-Value Observing on the progress, but you should take care that the change to progress is from a background queue during download(the same as progressBlock). If you want to using KVO and update the UI, make sure to dispatch on the main queue. And it's recommand to use some KVO libs like KVOController because it's more safe and easy to use.
 * @note The getter will create a progress instance if the value is nil. You can also set a custom progress instance and let it been updated during image loading
 * @note Note that because of the limitations of categories this property can get out of sync if you update the progress directly.
 */
@property (nonatomic, strong, null_resettable) NSProgress *HH_imageProgress;

/**
 * Set the imageView `image` with an `url` and optionally a placeholder image.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see HHWebImageOptions for the possible values.
 * @param operationKey   A string to be used as the operation key. If nil, will use the class name
 * @param setImageBlock  Block used for custom set image code
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)HH_internalSetImageWithURL:(nullable NSURL *)url
                  placeholderImage:(nullable UIImage *)placeholder
                           options:(HHWebImageOptions)options
                      operationKey:(nullable NSString *)operationKey
                     setImageBlock:(nullable HHSetImageBlock)setImageBlock
                          progress:(nullable HHWebImageDownloaderProgressBlock)progressBlock
                         completed:(nullable HHExternalCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url` and optionally a placeholder image.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see HHWebImageOptions for the possible values.
 * @param operationKey   A string to be used as the operation key. If nil, will use the class name
 * @param setImageBlock  Block used for custom set image code
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 * @param context        A context with extra information to perform specify changes or processes.
 */
- (void)HH_internalSetImageWithURL:(nullable NSURL *)url
                  placeholderImage:(nullable UIImage *)placeholder
                           options:(HHWebImageOptions)options
                      operationKey:(nullable NSString *)operationKey
                     setImageBlock:(nullable HHSetImageBlock)setImageBlock
                          progress:(nullable HHWebImageDownloaderProgressBlock)progressBlock
                         completed:(nullable HHExternalCompletionBlock)completedBlock
                           context:(nullable NSDictionary<NSString *, id> *)context;

/**
 * Cancel the current image load
 */
- (void)HH_cancelCurrentImageLoad;

#pragma mark - Image Transition

/**
 The image transition when image load finished. See `HHWebImageTransition`.
 If you specify nil, do not do transition. Defautls to nil.
 */
@property (nonatomic, strong, nullable) HHWebImageTransition *HH_imageTransition;

#if HH_UIKIT

#pragma mark - Activity indicator

/**
 *  Show activity UIActivityIndicatorView
 */
- (void)HH_setShowActivityIndicatorView:(BOOL)show;

/**
 *  set desired UIActivityIndicatorViewStyle
 *
 *  @param style The style of the UIActivityIndicatorView
 */
- (void)HH_setIndicatorStyle:(UIActivityIndicatorViewStyle)style;

- (BOOL)HH_showActivityIndicatorView;
- (void)HH_addActivityIndicator;
- (void)HH_removeActivityIndicator;

#endif

@end

#endif
