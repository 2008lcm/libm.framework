//
//  MCoreBaseMacro.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#ifndef MCoreBaseMacro_h
#define MCoreBaseMacro_h

/* 字符串定义 */
/// 空字符串
#define M_EmptyString   @""
#define M_NullString(STRING) \
(!STRING || ![STRING isKindOfClass:[NSString class]] || [STRING isEqualToString:M_NullString] || \
![STRING stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet].length )
/// 本地化字符串获取
#define M_LT(X)   NSLocalizedString(X, nil)

/* 错误定义 */
#define M_ErrorDomain @"com.ming.error"
#define M_ErrorCode   @"ErrorCode"
#define M_ErrorDesc   @"ErrorDesc"
#define M_DError(DOMAIN, CODE, DESC) \
([NSError errorWithDomain:DOMAIN code:CODE userInfo:@{M_ErrorCode:@(CODE), M_ErrorDesc:DESC}])
#define M_Error(CODE, DESC) \
([NSError errorWithDomain:M_ErrorDomain code:CODE userInfo:@{M_ErrorCode:@(CODE), M_ErrorDesc:DESC}])

/* 单例定义 */
/// 获取实例
#define M_Shared(CLASS) [CLASS shared##CLASS]
/// 单例头文件
#define __M_Shared_DEF(CLASS) + (instancetype)shared##CLASS
/// 单例实现文件
#define __M_Shared_IMP(CLASS)                           \
                                                        \
static CLASS *instance##_CLASS = nil;                   \
                                                        \
+ (instancetype)shared##CLASS {                         \
static dispatch_once_t onceToken;                       \
dispatch_once(&onceToken, ^{                            \
instance##_CLASS = [self new];                          \
});                                                     \
return instance##_CLASS;                                \
}                                                       \
                                                        \
+ (instancetype)allocWithZone:(struct _NSZone *)zone {  \
static dispatch_once_t onceToken;                       \
dispatch_once(&onceToken, ^{                            \
instance##_CLASS = [super allocWithZone:zone];          \
});                                                     \
return instance##_CLASS;                                \
}                                                       \
                                                        \
- (instancetype)copyWithZone:(NSZone *)zone {           \
return instance##_CLASS;                                \
}                                                       \
                                                        \
- (instancetype)mutableCopyWithZone:(NSZone *)zone {    \
return instance##_CLASS;                                \
}

/* 引用定义 */
/// 弱引用
#ifndef M_Weakify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define M_Weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
        #define M_Weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define M_Weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
        #define M_Weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif
/// 强引用
#ifndef M_Strongify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define M_Strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
        #define M_Strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define M_Strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
        #define M_Strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif

#endif /* MCoreBaseMacro_h */
