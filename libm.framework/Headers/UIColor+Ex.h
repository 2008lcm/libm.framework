//
//  UIColor+Ex.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Ex)

/// 十六进制颜色值转 UIColor
/// @param hex 十六进制颜色值
/// 在 0x000000 和 0xFFFFFF 区间
+ (UIColor *)colorWithHex:(UInt32)hex;

/// 十六进制颜色值转 UIColor
/// @param hex 十六进制颜色值
/// 在 0x000000 和 0xFFFFFF 区间
/// @param alpha 透明度
/// 在 0.0f 和 1.0f 区间
+ (UIColor *)colorWithHex:(UInt32)hex Alpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_END
