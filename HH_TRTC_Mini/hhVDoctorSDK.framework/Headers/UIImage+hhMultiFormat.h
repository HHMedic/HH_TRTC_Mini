/*
 * This file is part of the HHWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "HHWebImageCompat.h"
#import "NSData+hhImageContentType.h"

@interface UIImage (hhMultiFormat)

/**
 * UIKit:
 * For static image format, this value is always 0.
 * For animated image format, 0 means infinite looping.
 * Note that because of the limitations of categories this property can get out of sync if you create another instance with CGImage or other methods.
 * AppKit:
 * NSImage currently only support animated via GIF imageRep unlike UIImage.
 * The getter of this property will get the loop count from GIF imageRep
 * The setter of this property will set the loop count from GIF imageRep
 */
@property (nonatomic, assign) NSUInteger HH_imageLoopCount;

+ (nullable UIImage *)HH_imageWithData:(nullable NSData *)data;
- (nullable NSData *)HH_imageData;
- (nullable NSData *)HH_imageDataAsFormat:(HHImageFormat)imageFormat;

@end
