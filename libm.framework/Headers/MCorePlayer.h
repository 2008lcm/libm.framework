//
//  MCorePlayer.h
//  libm
//
//  Created by 梁康亮 on 2020/1/1.
//  Copyright © 2020 Ming. All rights reserved.
//

#import <AVKit/AVKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MCorePlayer : NSObject

- (void)playerWithPath:(NSString *)path vc:(UIViewController *)vc;
- (void)play;
- (void)playWithPath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
