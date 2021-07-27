//
//  PL2_MeetingShadowManager.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/7/10.
//

#import <Foundation/Foundation.h>
#import "PL2_ShadowRoomInfoModel.h"
#import "PL2_WBRoomAttrDataModel.h"
#import "PL2_ShadowManagerDelegate.h"
#import "PL2_MeetingSubRoomManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^PL_ShadowLoadCompleted)(BOOL isSuccess, NSError *error, NSInteger currentRoomId);

@interface PL2_MeetingShadowManager : NSObject

@property (strong, nonatomic, readonly) NSMutableOrderedSet<PL2_UserInfoModel *> *room_members;
@property (strong, nonatomic, readonly) PL2_MeetingRoomAttrModel *room_attrs;
@property (strong, nonatomic, readonly) PL2_RoomInfoDataModel *roomInfo;
@property (strong, nonatomic, readonly) PL2_ShadowRoomInfoModel *shadow_room_info;
@property (strong, nonatomic, readonly) PL2_UserInfoModel *user_info;
@property (weak, nonatomic) id<PL2_ShadowManagerDelegate> delegate;

/// 便利构造器初始化manager
+ (instancetype)shadowManager;

/// 加入影子房间
/// @param user_info 当前用户的信息
/// @param room_id 房间的9位房间号
/// @param token 用户登录的权限Token
/// @param handlerCompleted 加入完成后的回调(BOOL:是否加入成功, NSError:如果失败返回错误信息, NSInteger:当前所在房间的lvb_room_id)
- (void)joinShadowRoomWithUserInfo:(PL2_UserInfoModel *)user_info
                          RoomCode:(NSString *)room_id
                         AuthToken:(NSString *)token
                         Completed:(PL_ShadowLoadCompleted)handlerCompleted;

/// 读取当前所有分组房间信息
- (NSDictionary<NSNumber *, PL2_GroupInfoModel *> *)readSubroomInfo;

/// 创建用于加入其他房间的manager对象(主房间/子房间)
/// @param userInfo 带有用户音视频等信息的用户信息
- (PL2_MeetingSubRoomManager *)gotoRoomWithUserInfo:(RoomUserInfoModel *)userInfo;

/// 发送呼叫Host的消息
/// @param lvb_room_id 当前所在的房间的中台id
/// @param sender_id 发送人的中台id
- (void)CallTheHostIntoSubroomWithId:(NSInteger)lvb_room_id
                           SenderUid:(NSInteger)sender_id;

/// 发送全局广播消息
/// @param message 广播消息内容
- (void)NoticeBroadcastMessage:(NSString *)message;

/// 发送开始分组内容
/// @param groups 分组目标值list
/// @param completed 分组返回值(带有每个分组房间的中台id)
- (void)StartBreakOutWithSubroomInfo:(NSArray<PL2_GroupInfoModel *> *)groups
                           Completed:(void (^)(BOOL isSuccess, NSArray<PL2_GroupInfoModel *> *rooms, NSError *error))completed;

/// 释放资源
- (void)destory;

@end

NS_ASSUME_NONNULL_END
