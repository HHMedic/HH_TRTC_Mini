/*
 * This file is part of the HHWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "HHWebImageCompat.h"

#if HH_MAC

// A subclass of `NSBitmapImageRep` to fix that GIF loop count issue because `NSBitmapImageRep` will reset `NSImageCurrentFrameDuration` by using `kCGImagePropertyGIFDelayTime` but not `kCGImagePropertyGIFUnclampedDelayTime`.
// Built in GIF coder use this instead of `NSBitmapImageRep` for better GIF rendering. If you do not want this, only enable `HHWebImageImageIOCoder`, which just call `NSImage` API and actually use `NSBitmapImageRep` for GIF image.

@interface HHAnimatedImageRep : NSBitmapImageRep

@end

#endif
