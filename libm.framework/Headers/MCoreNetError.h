//
//  MCoreNetError.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#ifndef MCoreNetError_h
#define MCoreNetError_h
/// 网络模块错误定义
static NSString *const M_NetErrorDomain = @"com.ming.error.core.net";
static NSInteger const M_NetErrorCode_NoData = 300001;
static NSString *const M_NetErrorDesc_NoData = @"无数据";
static NSInteger const M_NetErrorCode_NotJson = 300002;
static NSString *const M_NetErrorDesc_NotJson = @"数据格式不正确";
#endif /* MCoreNetError_h */
