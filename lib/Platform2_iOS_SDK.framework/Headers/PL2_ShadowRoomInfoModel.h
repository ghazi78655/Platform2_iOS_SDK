//
//  PL2_ShadowRoomInfoModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/7/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PL2_ShadowRoomInfoModel : NSObject

@property (assign, nonatomic) BOOL is_host;
@property (assign, nonatomic) BOOL room_breakout;
@property (assign, nonatomic) NSInteger breakout_id;
@property (assign, nonatomic) NSInteger user_id;
@property (assign, nonatomic) NSInteger home_id;
@property (assign, nonatomic) NSInteger sub_id;
@property (copy, nonatomic) NSString *room_token;
@property (copy, nonatomic) NSString *app_key;

@end

NS_ASSUME_NONNULL_END
