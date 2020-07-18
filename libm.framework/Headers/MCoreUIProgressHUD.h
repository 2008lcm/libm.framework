//
//  MCoreUIProgressHUD.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MCoreUIProgressHUD : NSObject

/// Loading
+ (void)showLoading:(UIView *)view;
+ (void)showLoadingMsg:(NSString *)message to:(UIView *)view;
+ (void)hideLoading:(UIView *)view;

/// Toast
+ (void)showToastMsg:(NSString *)message to:(UIView *)view;
+ (void)showToastErr:(NSError *)error to:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
