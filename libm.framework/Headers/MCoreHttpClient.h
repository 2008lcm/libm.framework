//
//  MCoreHttpClient.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCoreBaseMacro.h"

NS_ASSUME_NONNULL_BEGIN

/// 请求方法枚举
typedef NS_ENUM(NSInteger, HTTPMethod) {
    HTTP_GET,   /// Get 方法
    HTTP_POST   /// Post 方法
};

/// 响应键
static NSString *const M_Net_RESP_KEY_ERROR_CODE = @"respErrorCode";    /// ErrorCode 响应键
static NSString *const M_Net_RESP_KEY_ERROR_DESC = @"respErrorDesc";    /// ErrorDesc 响应键
static NSString *const M_Net_RESP_KEY_DATA       = @"respData";         /// Data 响应键

/// 回调
typedef void(^BeforeRequestBlock)(void);                /// 请求前回调
typedef void(^AfterRequestBlock)(void);                 /// 请求后回调
typedef void(^RequestSuccessBlock)(NSDictionary *dic);  /// 成功回调
typedef void(^RequestFailureBlock)(NSError *error);     /// 失败回调

/// 网络封装
/// 基于AFNetworking
@interface MCoreHttpClient : NSObject
@property (nonatomic, readonly) NSString *respErrorCode;                /// 获取响应键
@property (nonatomic, readonly) NSString *respErrorDesc;                /// 获取响应键
@property (nonatomic, readonly) NSString *respData;                     /// 获取响应键
@property (nonatomic, copy)     BeforeRequestBlock beforeRequestBlock;  /// 请求前回调
@property (nonatomic, copy)     AfterRequestBlock  afterRequestBlock;   /// 请求后回调

/// 单例定义
__M_Shared_DEF(MCoreHttpClient);

/// 设置Response字段关联
/// @param keys 关联字段
/// 错误码：respErrorCode
/// 错误描述：respErrorDesc
/// 数据段：respData
- (void)setRespKeys:(NSDictionary *)keys;

/// GET 请求
/// @param URLString 请求地址
/// @param parameters 请求参数
/// @param success 成功回调
/// @param failure 失败回调
- (void)GET:(NSString *)URLString
 parameters:(nullable NSDictionary *)parameters
    success:(nullable RequestSuccessBlock)success
    failure:(nullable RequestFailureBlock)failure;

/// POST 请求
/// @param URLString 请求地址
/// @param parameters 请求参数
/// @param success 成功回调
/// @param failure 失败回调
- (void)POST:(NSString *)URLString
  parameters:(nullable NSDictionary *)parameters
     success:(nullable RequestSuccessBlock)success
     failure:(nullable RequestFailureBlock)failure;

/// 请求
/// @param URLString 请求地址
/// @param method 请求方法
/// @param parameters 请求参数
/// @param success 成功回调
/// @param failure 失败回调
- (void)request:(NSString *)URLString
         method:(HTTPMethod)method
     parameters:(nullable NSDictionary *)parameters
        success:(nullable RequestSuccessBlock)success
        failure:(nullable RequestFailureBlock)failure;

/// 取消所有请求
- (void)cancelRequest;

@end

NS_ASSUME_NONNULL_END
