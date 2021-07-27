//
//  PL2_ShadowManagerDelegate.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/7/12.
//

#ifndef PL2_ShadowManagerDelegate_h
#define PL2_ShadowManagerDelegate_h

#import "PL2_UserInfoModel.h"
#import "PL2_GroupInfoModel.h"
#import "PL2_RTCLvbTools.h"

NS_ASSUME_NONNULL_BEGIN
@class PL2_MeetingShadowManager;
@protocol PL2_ShadowManagerDelegate <NSObject>

@optional
- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager RoomStatusChangedWithState:(PL2_WBMessageCategoryType)state;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager DidUserJoinTheSystemWithInfo:(PL2_UserInfoModel *)user_model;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager RemoteUserDidLoginWithMessage:(NSString *)message;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager DidLeaveTheSystemWithUserId:(NSInteger)userId;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager DidUserUpdateInfoWithAttrName:(NSString *)attr_name Value:(NSString *)value UserId:(NSInteger)userId;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager DidRecoverBreakoutInfo:(NSDictionary<NSNumber *, PL2_GroupInfoModel *> * _Nullable)info WithState:(NSString *)state;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager DidRecoverDissolvedNoticeWithSendId:(NSInteger)senderId;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager DidRecoverBoardcastMessage:(NSString *)message SenderId:(PL2_UserInfoModel *)sender_id;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager DidRecoverSubroom:(NSInteger)subroom_id CallHostWithSenderId:(PL2_UserInfoModel *)senderId;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager DidRecoverMoveSubroom:(PL2_GroupInfoModel *)subroom_info RequestWithSenderId:(PL2_UserInfoModel *)senderId TargetUsers:(NSArray<NSNumber *> *)users;

- (void)PL2_MeetingShadowManager:(PL2_MeetingShadowManager *)manager UserBreakoutStateDidChanged:(PL2_UserInfoModel *)info FromOriSubroomId:(NSInteger)ori_lvb_id;

@end
NS_ASSUME_NONNULL_END
#endif /* PL2_ShadowManagerDelegate_h */
