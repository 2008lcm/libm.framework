//
//  MWXLogin.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import "MLoginFactory.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MWXLogin

/// 前导声明
@class BaseReq;
@class BaseResp;

@protocol WeChatDelegate <NSObject>
@required
- (void)onReq:(BaseReq *)req;
- (void)onResp:(BaseResp *)resp;
@end

@interface MWXLogin : MLogin

/// 设置代理
/// @param delegate WeChatLoginDelegate
- (void)setDelegate:(id<WeChatDelegate>)delegate;

/// 登录授权
/// @param vc 当前界面对象
/// @param result 结果回调，成功返回Code，失败返回nil。
/// 返回YES，表示可以登录。
/// 返回NO，表示不可登录，可能原因：未安装，版本不支持，SDK未注册成功。
- (BOOL)loginAuthWithViewController:(UIViewController *)vc result:(nullable void(^)(NSString * _Nullable code))result;

@end

#pragma mark - MWXLoginAPIs

/// 前导声明
@class WeChatAuthModel;
@class WeChatUserInfoModel;
/// 请求结果回调
typedef void(^APIResult)(id object);

@interface MWXLoginAPIs : MLogin
@property (nonatomic, strong, readonly) WeChatAuthModel *authModel;         /// 授权模型
@property (nonatomic, strong, readonly) WeChatUserInfoModel *userInfoModel; /// 用户信息模型
__M_Shared_DEF(MWXLoginAPIs);
+ (void)API_access_token:(NSString *)code in:(UIView *)view result:(APIResult)result;
+ (void)API_auth:(UIView *)view result:(APIResult)result;
+ (void)API_refresh_token:(UIView *)view result:(APIResult)result;
+ (void)API_userinfo:(UIView *)view result:(APIResult)result;
@end

#pragma mark - WeChatModels

@interface WeChatAuthModel : NSObject
@property (nonatomic, copy) NSString *access_token;         /// 接口调用凭证
@property (nonatomic, assign) NSInteger expires_in;         /// access_token 接口调用凭证超时时间，单位（秒）
@property (nonatomic, copy) NSString *refresh_token;        /// 用户刷新 access_token
@property (nonatomic, copy) NSString *openid;               /// 授权用户唯一标识
@property (nonatomic, copy) NSString *scope;                /// 用户授权的作用域，使用逗号（,）分隔
@property (nonatomic, copy) NSString *unionid;              /// 当且仅当该移动应用已获得该用户的 userinfo 授权时，才会出现该字段
@property (nonatomic, assign) NSInteger errcode;            /// 错误码
@property (nonatomic, copy) NSString *errmsg;               /// 错误信息
@end

@interface WeChatUserInfoModel : NSObject
@property (nonatomic, copy) NSString *openid;               /// 普通用户的标识，对当前开发者帐号唯一
@property (nonatomic, copy) NSString *nickname;             /// 普通用户昵称
@property (nonatomic, assign) NSInteger sex;                /// 普通用户性别，1 为男性，2 为女性
@property (nonatomic, copy) NSString *province;             /// 普通用户个人资料填写的省份
@property (nonatomic, copy) NSString *city;                 /// 普通用户个人资料填写的城市
@property (nonatomic, copy) NSString *country;              /// 国家，如中国为 CN
@property (nonatomic, copy) NSString *headimgurl;           /// 用户头像，最后一个数值代表正方形头像大小（有 0、46、64、96、132 数值可选，0 代表 640*640 正方形头像），用户没有头像时该项为空
@property (nonatomic, copy) NSArray<NSString *> *privilege; /// 用户特权信息，json 数组，如微信沃卡用户为（chinaunicom）
@property (nonatomic, copy) NSString *unionid;              /// 用户统一标识。针对一个微信开放平台帐号下的应用，同一用户的 unionid 是唯一的。
@property (nonatomic, assign) NSInteger errcode;            /// 错误码
@property (nonatomic, copy) NSString *errmsg;               /// 错误信息
@end

NS_ASSUME_NONNULL_END
