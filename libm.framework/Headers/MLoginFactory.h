//
//  MLoginFactory.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MCoreBaseMacro.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MLoginFactory

/// 登录类型枚举
typedef NS_ENUM(NSInteger, LoginType) {
    LoginTypeWeixin
};

/// 前导声明
@class MLoginFactory;

/// 抽象别名
typedef MLoginFactory MLogin;

/// 三方登录工场类
/// 单例模式，工场模式
@interface MLoginFactory : NSObject
/// 实体对象属性
@property (nonatomic, assign) BOOL isInstall;   /// 是否安装
@property (nonatomic, assign) BOOL isSupport;   /// 是否支持
@property (nonatomic, assign) BOOL isRegister;  /// 是否注册

/// 单例定义
__M_Shared_DEF(MLoginFactory);
__M_Shared_DEF(MLogin);

#pragma mark - Factory

/// 工场创建登录对象
/// 一个类型对象只创建一次。
/// 创建相同类型时，返回已创建的对象。
/// @param loginType 登录类型
- (MLogin *)createLoginWithType:(LoginType)loginType;

/// 获取登录对象
/// @param loginType 登录类型
- (MLogin *)getLoginWithType:(LoginType)loginType;

#pragma mark - Abstract & Manage

/// 获取版本号
- (NSString *)getVersion;

/// 检查是否安装与支持
/// 返回NO，判断需要用登录对象的方法或属性。
- (BOOL)checkInstallAndSupport;

/// 注册AppId
/// 返回NO，判断需要用登录对象的方法或属性。
- (BOOL)registerApp;

/// 打开App
/// 需要子类对象调用
/// 返回NO，判断需要用登录对象的方法或属性。
- (BOOL)openApp;

/// URL支持
/// @param url AppDelegate返回
/// 如果有登录对象成功，则返回YES。
- (BOOL)openURL:(NSURL *)url;

/// UniversalLink支持
/// @param userActivity AppDelegate返回
/// 如果有登录对象成功，则返回YES。
- (BOOL)openUniversalLink:(NSUserActivity *)userActivity;

/// 登录授权
/// @param result 结果回调，成功返回Code，失败返回nil。
/// 返回YES，表示可以登录。
/// 返回NO，表示不可登录，可能原因：未安装，版本不支持，SDK未注册成功。
/// 需要用登录对象调用此方法。
- (BOOL)loginAuth:(nullable void(^)(NSString * _Nullable code))result;

/// 通过登录对象登录
/// 不支持使用者自己服务端登录
/// @param vc 载入的VC
/// @param result 结果回调
/// 成功返回object，error为nil。
/// 失败返回error，object为nil。
/// 需要用登录对象调用此方法。
- (void)loginWithViewController:(UIViewController *)vc result:(nullable void(^)(id _Nullable object, NSError * _Nullable error))result;

@end

#pragma mark - MLoginParamModel

@interface MLoginParamModel : NSObject
@property (nonatomic, copy) NSString *APP_ID;
@property (nonatomic, copy) NSString *SECRET_KEY;
@property (nonatomic, copy) NSString *UNIVERSAL_LINK;
__M_Shared_DEF(MLoginParamModel);
@end

NS_ASSUME_NONNULL_END
