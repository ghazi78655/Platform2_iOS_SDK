//
//  PL2_UserInfoModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/5/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PL2_UserInfoModel : NSObject

@property (assign, nonatomic) long UserId;
@property (copy, nonatomic) NSString *extId;
@property (copy, nonatomic) NSString *avatar;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *role; // host, co-host, attendee
@property (copy, nonatomic, nullable) NSString *breakoutId; // 房间的中台lvb_id
@property (assign, nonatomic) NSInteger needWait;

- (BOOL)checkProperty:(NSString *)propertyName;

- (void)setUndefinePropertyValue:(id)value WithPropertyName:(NSString *)p_name;

@end

NS_ASSUME_NONNULL_END
