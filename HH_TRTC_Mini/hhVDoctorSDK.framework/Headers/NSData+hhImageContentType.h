/*
 * This file is part of the HHWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Fabrice Aneche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "HHWebImageCompat.h"

typedef NS_ENUM(NSInteger, HHImageFormat) {
    HHImageFormatUndefined = -1,
    HHImageFormatJPEG = 0,
    HHImageFormatPNG,
    HHImageFormatGIF,
    HHImageFormatTIFF,
    HHImageFormatWebP,
    HHImageFormatHEIC
};

@interface NSData (hhImageContentType)

/**
 *  Return image format
 *
 *  @param data the input image data
 *
 *  @return the image format as `HHImageFormat` (enum)
 */
+ (HHImageFormat)HH_imageFormatForImageData:(nullable NSData *)data;

/**
 Convert HHImageFormat to UTType

 @param format Format as HHImageFormat
 @return The UTType as CFStringRef
 */
+ (nonnull CFStringRef)HH_UTTypeFromHHImageFormat:(HHImageFormat)format;

@end
