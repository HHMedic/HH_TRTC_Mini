//
//  HHCameraUtil.h
//  CameraLibrary
//
//  Created by shmily on 16/5/25.
//  Copyright © 2016年 HHPacs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// 图片是否压缩临界点
#define HHImgReduceSize 1000000

@class AVAssetExportSession;

typedef enum : NSUInteger {
    ProTypePacs,
    ProTypeUser
} ProType;


@interface HHCameraUtil : NSObject

///  是否应该被压缩
@property(nonatomic,assign)BOOL shouldReduce;

/// 家庭医生使用
@property(nonatomic, assign)ProType type;

///  单例
+ (instancetype)shareInstance;

///  获取图片bundle
//+ (NSBundle *)getBundle;

///  根据图片名获取图片
//+ (UIImage *)getImage:(NSString *)imgName;

///  获取视频的缩略图
///  @param videoURL 视频的URL
///  @param time     截图时间
+ (UIImage *)thumbnailImageForVideo:(NSURL *)videoURL atTime:(NSTimeInterval)time;

///  根据视频路径获取对应缩略图
//+ (UIImage *)thumImageForVideo:(NSString *)videoPath;

///  能否被压缩(小于200k不被压缩)
+ (BOOL)isCanReduce:(UIImage *)image;

+ (BOOL)isCanReduceFile:(NSString *)imgPath;

///  压缩图像后覆盖原图
+ (BOOL)reduceImage:(UIImage *)img path:(NSString *)path;

+ (BOOL)isImage:(NSString *)path;

///  创建图片的本地路径
///
///  @param prefix 文件头
+ (NSString *)createDocumentPath:(NSString *)prefix;

// 获取图片(视频)缩略图路径
+ (NSString *)getScallPath:(NSString *)fullPath;

///  写入文件
+ (NSString *)writeImageToFile:(UIImage *)image;

+ (NSString *)writeImageToFile:(UIImage *)image scale:(CGSize)size fullPath:(NSString *)fullPath;

+ (NSString *)writeScaledImg:(UIImage *)image scale:(CGSize)size fullPath:(NSString *)fullPath;

///  压缩图片
+ (void)zipImages:(NSArray<NSString *> *)imgPaths;

+ (UIImage *)fixOrientation:(UIImage *)aImag;

+ (void)videoFixOrientation: (NSURL *)url path:(NSString *)path finished:(void (^)(AVAssetExportSession *))finishBlock;

+ (Boolean)isIPad;

@end
