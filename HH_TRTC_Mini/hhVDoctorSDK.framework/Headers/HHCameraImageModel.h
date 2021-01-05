//
//  HHCameraImage.h
//  camera_Demo
//
//  Created by shmily on 15/10/20.
//  Copyright © 2015年 shmilyAshen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface HHCameraImageModel : NSObject

/// 全尺寸图像
@property(nonatomic,strong)NSString *fullPath;

@property(nonatomic,strong)NSString *scalledPath;

+ (instancetype)cameraImageWithFullPath:(NSString *)fullPath scalledPath:(NSString *)scalledPath;

- (bool)isMp4;


@end
