//
//  MCoreUINavigationController.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define M_NavigationController          ((MCoreUINavigationController *)self.navigationController)
#define M_NavigationBarHidden(Hidden)   (Hidden ? [M_NavigationController setBarHidden] : [M_NavigationController setBarShow])
#define M_NavigationBarOpaque(Opaque) \
(Opaque ? [M_NavigationController setBarOpaque] : [M_NavigationController setBarTransparent])
#define M_NavigationBarTranslucent(Translucent) \
(Translucent ? [M_NavigationController setBarTranslucent] : [M_NavigationController setBarNotTranslucent])
#define M_NavigationReturnImage(Image)  ([M_NavigationController setReturnImage:Image])
#define M_NavigationReturnText(Text)    ([M_NavigationController setReturnText:Text])

@interface MCoreUINavigationController : UINavigationController
/// 透明
- (void)setBarTransparent;
/// 不透明
- (void)setBarOpaque;
/// 半透明
- (void)setBarTranslucent;
/// 非半透明
- (void)setBarNotTranslucent;
/// 隐藏
- (void)setBarHidden;
/// 显示
- (void)setBarShow;
/// 隐藏阴影
- (void)setBarShadowHidden;
/// 显示阴影
- (void)setBarShadowShow;
/// 设置返回按钮显示图片
/// 设置返回按钮显示文字之前必须调用返回按钮显示图片
/// @param image 显示图片
- (void)setReturnImage:(UIImage *)image;
/// 设置返回按钮显示文字
/// 设置返回按钮显示文字之前必须调用返回按钮显示图片
/// @param text 显示文字
- (void)setReturnText:(NSString *)text;
@end

NS_ASSUME_NONNULL_END
