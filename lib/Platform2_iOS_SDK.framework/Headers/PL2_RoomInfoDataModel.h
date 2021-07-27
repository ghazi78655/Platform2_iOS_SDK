//
//  PL2_RoomInfoDataModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/7/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PL2_RoomInfoDataModel : NSObject

@property (copy, nonatomic) NSString *owner;
@property (copy, nonatomic) NSString *owner_id;
@property (assign, nonatomic) BOOL has_password;
@property (copy, nonatomic) NSString *has_poll;
@property (copy, nonatomic) NSString *media_urls;
@property (assign, nonatomic) NSInteger lvb_room_id;
@property (assign, nonatomic) NSInteger meeting_id;
@property (assign, nonatomic) NSInteger status; // 0,1,2
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *plan_begin_at;
@property (copy, nonatomic) NSString *plan_end_at;
@property (assign, nonatomic) NSInteger mute_type;
@property (copy, nonatomic) NSString *actually_begin_at;
@property (copy, nonatomic) NSString *actually_end_at;
@property (copy, nonatomic) NSString *password;
@property (copy, nonatomic) NSString *attr;
@property (copy, nonatomic) NSString *room_id; // room hash id
@property (copy, nonatomic) NSString *close_by;

@end

NS_ASSUME_NONNULL_END
