//
//  HHPHAssetManager.h
//  CameraLibrary
//
//  Created by shmily on 16/3/16.
//  Copyright © 2016年 HHPacs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Photos/Photos.h>

@interface HHPHAssetManager : NSObject

- (void)tranformImage:(PHAsset *)asset finished:(void (^)(NSData *fullData,NSData *scaledData))finishBlock;

// 返回填充的缩略图
+ (UIImage *)image:(UIImage *)image fillSize: (CGSize)viewsize;

+ (NSString*)createFilePath:(NSString *)aFileName;

/// 是否有缓存
+ (BOOL)isWriteCache:(NSString *)aPath setData:(NSData *)aData;

+ (instancetype)shareManager;

@end
