//
//  NSString+Ex.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 字符串位置枚举
typedef NS_ENUM(NSUInteger, MStringPosition) {
    /// 全部
    MStringPositionAll = UINT_MAX - 1,
    /// 单词首位
    MStringPositionWordsFirst = UINT_MAX - 2
};

@interface NSString (Ex)
/// 字符串截取
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @param range 截取范围
/// range 不在字符串范围内返回原始字符串
/// @return 截取后的字符串
+ (NSString *)MStringSubString:(NSString *)string Range:(NSRange)range;

/// 字符串截取
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @param from 截取起始位置
/// @param to 截取结束位置
/// 不在字符串范围内返回原始字符串
/// @return 截取后的字符串
+ (NSString *)MStringSubString:(NSString *)string From:(NSUInteger)from To:(NSUInteger)to;

/// 字符串截取
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @param from 截取起始位置
/// @param len 截取长度
/// 不在字符串范围内返回原始字符串
/// @return 截取后的字符串
+ (NSString *)MStringSubString:(NSString *)string From:(NSUInteger)from Length:(NSUInteger)len;

/// 字符串替换
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @param searchstr 被替换的字符串
/// 被替换的字符串为空返回原始字符串
/// @param bystr 替换的字符串
/// 替换的字符串为nil、Null或非NSString类及子类返回原始字符串
/// @param replaceall 是否全部替换匹配的字符串
/// @return 替换后的字符串
+ (NSString *)MStringReplaceString:(NSString *)string SearchString:(NSString *)searchstr ByString:(NSString *)bystr ReplaceAll:(BOOL)replaceall;

/// 字符串替换
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @param range 要替换的范围
/// 超出原始字符串范围返回原始字符串
/// @param bystr 替换的字符串
/// 替换的字符串为nil、Null或非NSString类及子类返回原始字符串
/// @return 替换后的字符串
+ (NSString *)MStringReplaceString:(NSString *)string Range:(NSRange)range ByString:(NSString *)bystr;

/// 字符串转换为大写
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @param position 要转换的字符串位置
/// 超出原始字符串范围返回原始字符串
/// @return 转换后的字符串
+ (NSString *)MStringUpperString:(NSString *)string Position:(MStringPosition)position;

/// 字符串转换为小写
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @param position 要转换的字符串位置
/// 超出原始字符串范围返回原始字符串
/// @return 转换后的字符串
+ (NSString *)MStringLowerString:(NSString *)string Position:(MStringPosition)position;

/// 字符串大小写互换
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @return 转换后的字符串
+ (NSString *)MStringUpLowString:(NSString *)string;

/// 字符串大小写互换
/// @param string 原始字符串
/// 原始字符串为空返回 M_EmptyString
/// @param position 要转换的字符串位置
/// 超出原始字符串范围返回原始字符串
/// @return 转换后的字符串
+ (NSString *)MStringUpLowString:(NSString *)string Position:(NSUInteger)position;

/// 字符串转换为拼音
/// @param string 字符串
/// 字符串为空返回 M_EmptyString
/// @param flag 是否带音标
+ (NSString *)MStringToPinyin:(NSString *)string WithYinBiao:(BOOL)flag;
@end

@interface NSString (Parse)
/// 字符串解析
/// 传入的字符串是否可解析为整形
/// @param string 字符串
/// 字符串为空返回 NO
+ (BOOL)MStringParseInt:(NSString *)string;

/// 字符串解析
/// 传入的字符串是否可解析为整形
/// @param string 字符串
/// 字符串为空返回 0
/// @return 返回解析的数值，不能解析返回 0
+ (NSInteger)MStringParseIntEx:(NSString *)string;

/// 字符串解析
/// 传入的字符串是否可解析为浮点型
/// @param string 字符串
/// 字符串为空返回 NO
+ (BOOL)MStringParseFloat:(NSString *)string;

/// 字符串解析
/// 传入的字符串是否可解析为浮点型
/// @param string 字符串
/// 字符串为空返回 0.0f
/// @return 返回解析的数值，不能解析返回 0.0f
+ (CGFloat)MStringParseFloatEx:(NSString *)string;
@end

NS_ASSUME_NONNULL_END
