//
//  PL2_MeetingRoomAttrModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/5/14.
//

#import <Foundation/Foundation.h>
#import "PL2_GroupInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface PL2_MeetingRoomAttrModel : NSObject

@property (copy, nonatomic) NSNumber *audio;
@property (copy, nonatomic) NSNumber *enableAudioChange;
@property (strong, nonatomic) NSMutableArray<PL2_GroupInfoModel *> *subRooms;

- (PL2_GroupInfoModel *_Nullable)searchUserInWhichGroupWithUserId:(NSInteger)userId;

- (PL2_GroupInfoModel *_Nullable)searchSubroomInfoWithLvbId:(NSInteger)subroom_lvb_id;

@end

NS_ASSUME_NONNULL_END
