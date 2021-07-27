//
//  PL2_ControlInfoModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/5/14.
//

#import <Foundation/Foundation.h>
#import "PL2_GroupInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface PL2_ControlInfoModel : NSObject

@property (copy, nonatomic) NSString *kind;
@property (copy, nonatomic) NSString *type;
@property (copy, nonatomic) NSString *handType;
@property (copy, nonatomic) NSNumber *roomId;
@property (nonatomic, copy) NSNumber *userId;
@property (copy, nonatomic) NSNumber *value;
@property (copy, nonatomic) NSString *state;
@property (copy, nonatomic) NSNumber *senderId;
@property (assign, nonatomic) NSInteger fromRoomId;
@property (assign, nonatomic) NSInteger toRoomId;
@property (copy, nonatomic) NSArray<PL2_GroupInfoModel *> *rooms;
@property (nonatomic, copy) NSArray<NSNumber *> *userIds;
@property (copy, nonatomic) NSString *message;

- (instancetype)initHandAckWithUserId:(NSUInteger)uid;

- (instancetype)initChangeUserAudioStateWithUid:(NSNumber *)uid RoomId:(NSNumber *)roomId TargetChangeValue:(NSNumber *)value;

- (instancetype)initChangeUserPlatformStateWithUid:(NSNumber *)uid RoomId:(NSNumber *)roomId TargetChangeValue:(NSNumber *)value;

- (instancetype)initStartGroupWithRoomId:(NSInteger)roomId BreakOutGroups:(NSArray<PL2_GroupInfoModel *> *)groups;

- (instancetype)initStopGroupWithRoomId:(NSInteger)roomId;

@end

NS_ASSUME_NONNULL_END
