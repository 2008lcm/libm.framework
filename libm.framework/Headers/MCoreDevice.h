//
//  MCoreDevice.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <UIKit/UIDevice.h>

#define Is_AirPods          [self.model containsString:@"AirPods"]          /// 是否是 AirPods
#define Is_AppleTV          [self.model containsString:@"Apple TV"]         /// 是否是 Apple TV
#define Is_SiriRemote       [self.model containsString:@"Siri Remote"]      /// 是否是 Siri Remote
#define Is_AppleWatch       [self.model containsString:@"Apple Watch"]      /// 是否是 Apple Watch
#define Is_HomePod          [self.model containsString:@"HomePod"]          /// 是否是 HomePod
#define Is_iPad             [self.model containsString:@"iPad"]             /// 是否是 iPad
#define Is_ApplePencil      [self.model containsString:@"Apple Pencil"]     /// 是否是 Apple Pencil
#define Is_SmartKeyboard    [self.model containsString:@"Smart Keyboard"]   /// 是否是 Smart Keyboard
#define Is_iPadAir          [self.model containsString:@"iPad Air"]         /// 是否是 iPad Air
#define Is_iPadPro          [self.model containsString:@"iPad Pro"]         /// 是否是 iPad Pro
#define Is_iPadMini         [self.model containsString:@"iPad mini"]        /// 是否是 iPad mini
#define Is_iPhone           [self.model containsString:@"iPhone"]           /// 是否是 iPhone
#define Is_iPodTouch        [self.model containsString:@"iPod touch"]       /// 是否是 iPod touch

@interface MCoreDevice : UIDevice
/// 获取设备 Identifier
/// e.g. @"iPhone1,1"
+ (NSString *)identifier;
/// 获取设备 Generation
/// e.g. @"iPhone", @"iPhone SE (1st generation)", @"Simulator"
+ (NSString *)generation;
/// 获取设备 Short Generation
/// e.g. @"iPhone", @"iPhone SE", @"Simulator"
+ (NSString *)shortGeneration;
@end
