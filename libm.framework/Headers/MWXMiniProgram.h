//
//  MWXMiniProgram.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MWXMiniProgram : NSObject

/// 启动小程序
/// @param userName 小程序名
/// @param path 指定的地址
+ (void)launchWithUserName:(NSString *)userName path:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
