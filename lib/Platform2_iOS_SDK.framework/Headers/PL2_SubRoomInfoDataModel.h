//
//  PL2_SubRoomInfoDataModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PL2_SubRoomInfoDataModel : NSObject

@property (copy, nonatomic) NSString *app_id;
@property (copy, nonatomic) NSString *app_provider;
@property (copy, nonatomic) NSString *app_key;
@property (copy, nonatomic) NSString *rtc_token;
@property (assign, nonatomic) NSInteger user_id;
@property (copy, nonatomic) NSString *start_at;

@end

NS_ASSUME_NONNULL_END
