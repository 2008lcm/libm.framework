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
(!STRING || ![STRING isKindOfClass:[NSString class]] || \
![STRING stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet].length)
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
static CLASS *instance_##CLASS = nil;                   \
                                                        \
+ (instancetype)shared##CLASS {                         \
static dispatch_once_t onceToken;                       \
dispatch_once(&onceToken, ^{                            \
instance_##CLASS = [self new];                          \
});                                                     \
return instance_##CLASS;                                \
}                                                       \
                                                        \
+ (instancetype)allocWithZone:(struct _NSZone *)zone {  \
static dispatch_once_t onceToken;                       \
dispatch_once(&onceToken, ^{                            \
instance_##CLASS = [super allocWithZone:zone];          \
});                                                     \
return instance_##CLASS;                                \
}                                                       \
                                                        \
- (instancetype)copyWithZone:(NSZone *)zone {           \
return instance_##CLASS;                                \
}                                                       \
                                                        \
- (instancetype)mutableCopyWithZone:(NSZone *)zone {    \
return instance_##CLASS;                                \
}

/* 引用定义 */
/// 弱引用
#ifndef M_weakify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define M_weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
        #define M_weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define M_weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
        #define M_weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif
/// 强引用
#ifndef M_strongify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define M_strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
        #define M_strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define M_strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
        #define M_strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif

/* 输出定义 */
/// 默认开启所在方法和行号打印
#define M_LogCode 1
#ifdef DEBUG
/// Debug 打印
#if !M_LogCode
#define MLogFile     NSLog(@"%s", __FILE__)
#define MLogFunc     NSLog(@"%s", __FUNCTION__)
#define MLogLine     NSLog(@"%s", __LINE__)
#define MLogCode     NSLog(@"Func:%s, Line:%d", __FUNCTION__, __LINE__)
/// 不打印方法和行号打印
#define MLog(...)    NSLog(__VA_ARGS__)
#define MLogP(obj)   NSLog(@"%p", (obj))
#define MLog0X(obj)  NSLog(@"%lld:%#llX", ((long long)obj), ((long long)obj))
#define MLog08(obj)  NSLog(@"%lld:%#llO", ((long long)obj), ((long long)obj))
#else
/// 打印方法和行号打印
#define MLog(...)    NSLog(__VA_ARGS__); MLogCode
#define MLogP(obj)   NSLog(@"%p", (obj)); MLogCode
#define MLog0X(obj)  NSLog(@"%lld:%#llX", ((long long)obj), ((long long)obj)); MLogCode
#define MLog08(obj)  NSLog(@"%lld:%#llO", ((long long)obj), ((long long)obj)); MLogCode
#endif
#else
/// Release 不打印
#define MLog(...)
#define MLogP(x)
#define MLog0X(x)
#define MLog08(x)
#define MLogFile
#define MLogFunc
#define MLogLine
#define MLogCode
#endif

#endif /* MCoreBaseMacro_h */
