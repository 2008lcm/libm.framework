//
//  MCoreVideo.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 倍速枚举
typedef NS_ENUM(NSInteger, VideoSpeed) {
    VideoSpeedX1 = 1,
    VideoSpeedX2 = 2,
    VideoSpeedX4 = 4,
    VideoSpeedX8 = 8
};

@interface MCoreVideo : NSObject

/// 视频合并
/// @param files 输入视频列表
/// @param outPut 输出视频
/// 回调 error 对象不为空失败。
+ (void)combine:(NSArray<NSString *> *)files
         outPut:(NSString *)outPut
     completion:(void (^)(NSError * _Nullable error))completion;

/// 视频倍速
/// @param speed 倍速枚举
/// @param file 输入视频
/// @param outPut 输出视频
/// 回调 error 对象不为空失败。
+ (void)speed:(VideoSpeed)speed
         file:(NSString *)file
       outPut:(NSString *)outPut
   completion:(void (^)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
