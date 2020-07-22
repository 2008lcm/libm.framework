//
//  MLoginError.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#ifndef MLoginError_h
#define MLoginError_h
#import <Foundation/Foundation.h>
/// 登录模块错误定义
static NSString *const M_LoginErrorDomain = @"com.ming.error.login";
static NSInteger const M_LoginErrorCode_CallFunction = 1000001;
static NSString *const M_LoginErrorDesc_CallFunction = @"方法调用不正确";
#endif /* MLoginError_h */
