//
//  PL2_MeetingShareStateModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/5/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PL2_MeetingShareStateModel : NSObject<NSCopying>

@property (copy, nonatomic) NSString *shareType;
@property (assign, nonatomic) NSUInteger sharingUserId;

+ (instancetype)meetingShareModelWithType:(NSString *)shareType ShareUserId:(NSUInteger)userId;

@end

NS_ASSUME_NONNULL_END
