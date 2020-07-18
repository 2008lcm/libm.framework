//
//  MCoreFile.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCoreBaseMacro.h"

NS_ASSUME_NONNULL_BEGIN

/// 路径字符串
static NSString *const M_Dir_Path_Line  = @"/";            /// 路径斜线
static NSString *const M_Dir_Path_Line2 = @"//";           /// 路径双斜线
static NSString *const M_Dir_Null       = @"";             /// 空路径
static NSString *const M_Dir_Documents  = @"Documents";    /// Documents 路径
static NSString *const M_Dir_Library    = @"Library";      /// Library 路径
static NSString *const M_Dir_tmp        = @"tmp";          /// tmp 路径

@interface MCoreFile : NSFileManager
/// 获取系统路径
@property (nonatomic, copy, readonly) NSString *homeDirectory;      /// 获取 Home 路径
@property (nonatomic, copy, readonly) NSString *documentsDirectory; /// 获取 Documents 路径
@property (nonatomic, copy, readonly) NSString *cachesDirectory;    /// 获取 Caches 路径
@property (nonatomic, copy, readonly) NSString *tmpDirectory;       /// 获取 tmp 路径

/// 单例定义
__M_Shared_DEF(MCoreFile);

/// 路径操作
+ (BOOL)fileExistsAtPath:(NSString *)path isDirectory:(nullable BOOL *)isDirectory;
+ (BOOL)fileExistsAtPath:(NSString *)path;
+ (BOOL)createDirectory:(NSString *)path;
+ (BOOL)deleteDirectory:(NSString *)path;

/// 获取路径
+ (nullable NSString *)getFullFileName:(NSString *)path;
+ (nullable NSString *)getFileName:(NSString *)path;
+ (nullable NSString *)getFileExtension:(NSString *)path;
+ (nullable NSString *)getPathNoFullFileName:(NSString *)path;
+ (nullable NSString *)getPathNoExtension:(NSString *)path;
+ (nullable NSString *)getPathNoHome:(NSString *)path;
+ (nullable NSArray<NSString *> *)getSubPathsAtPath:(NSString *)path;

/// 获取包中路径
+ (nullable NSString *)getPathWithBundle:(NSBundle *)bundle fileName:(NSString *)name fileExt:(NSString *)ext;
+ (nullable NSString *)getPathWithFileName:(NSString *)name fileExt:(NSString *)ext;
+ (nullable NSString *)getPathWithBundle:(NSBundle *)bundle fullFileName:(NSString *)name;
+ (nullable NSString *)getPathWithFullFileName:(NSString *)name;

/// 文件操作
+ (nullable NSData *)getDataAtPath:(NSString *)path;
+ (BOOL)deleteFile:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
