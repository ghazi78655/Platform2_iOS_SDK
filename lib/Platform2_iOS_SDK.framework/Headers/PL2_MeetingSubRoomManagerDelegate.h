//
//  PL2_MeetingSubRoomManagerDelegate.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/6/21.
//

#ifndef PL2_MeetingSubRoomManagerDelegate_h
#define PL2_MeetingSubRoomManagerDelegate_h

#import "RoomUserInfoModel.h"
#import "PL2_SubRoomInfoDataModel.h"
#import "ChatMessageModel.h"
#import "PL2_MeetingShareStateModel.h"
#import "PL2_MeetingRoomAttrModel.h"
#import "PL2_ControlInfoModel.h"
#import "PL2_RTCLvbTools.h"

@class PL2_MeetingSubRoomManager;
@protocol PL2_MeetingSubRoomManagerDelegate <NSObject>

/// 用户已经加入了某个子房间
/// @param subRoomManager 房间管理者对象
/// @param room_id 目标房间的中台Id
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidJoinedSubRoom:(NSInteger)room_id;

/// 某用户加入到了该房间
/// @param subRoomManager 房间管理者对象
/// @param info 用户信息model
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager UserDidJoinedRoom:(RoomUserInfoModel *)info;

/// 房间的会议状态已更新
/// @param subRoomManager 房间管理者对象
/// @param state 会议开始/结束
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager MeetingRoomStateDidChanged:(PL2_WBMessageCategoryType)state;

/// 某用户离开了该房间
/// @param subRoomManager 房间管理者对象
/// @param info 离开者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager UserDidLeavedRoom:(RoomUserInfoModel *)info;

/// 某用户被踢出了房间
/// @param subRoomManager 房间管理者对象
/// @param info 被踢出者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidRecoverKickoutNotice:(RoomUserInfoModel *)info;

/// 房间内的某个用户开始推流了
/// @param subRoomManager 房间管理者对象
/// @param info_model 推流者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager MeetingMemberDidPublishedStream:(RoomUserInfoModel *)info_model;

/// 屏幕共享的相关数据
/// @param subRoomManager 房间管理者对象
/// @param share_model 共享数据的model(使用的共享id与appkey等参数)
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager ShareScreenInfo:(PL2_SubRoomInfoDataModel *)share_model;

/// 当前用户获取到打开音频的请求
/// @param subRoomManager 房间管理者对象
/// @param control_message 请求体消息结构
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager RecoverOpenAudioRequest:(PL2_ControlInfoModel *)control_message;

/// 当前用户获取到自己的举手请求的回应
/// @param subRoomManager 房间管理者对象
/// @param control_message 回应消息的消息结构
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager RecoverHandAckMessage:(PL2_ControlInfoModel *)control_message;

/// 获取房间内传输的自定义消息
/// @param subRoomManager 房间管理者对象
/// @param json_message 自定义消息的json字符串结构
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager RecoverCustomMessage:(NSString *)json_message;

/// 获取当前账号在远端被登录的消息
/// @param subRoomManager 房间管理者对象
/// @param device_message 远端反馈的设备信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager RemoteUserDidLoginWithDeviceMessage:(NSString *)device_message;

/// 获取到广播消息
/// @param subRoomManager 房间管理者对象
/// @param message 广播消息内容
/// @param info 发送广播消息者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager RecoverBroatcastMessage:(NSString *)message SenderUserInfo:(PL2_UserInfoModel *)info;

/// 房间内权限变更等消息事件

/// 获取到用户权限更改消息
/// @param subRoomManager 房间管理者对象
/// @param power_enum 权限类型枚举
/// @param info 用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidRecoverUserPowerChanged:(PL2_UserPowerChangedEnum)power_enum UserInfo:(RoomUserInfoModel *)info;

/// 获取到房间内属性更改消息
/// @param subRoomManager 房间管理者对象
/// @param type_name 属性名
/// @param room_attr 房间属性值
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidUpdateRoomAttrWithType:(NSString *)type_name RoomAttrValue:(PL2_MeetingRoomAttrModel *)room_attr;

/// 获取到房间自定义属性更新消息
/// @param subRoomManager 房间管理者对象
/// @param updateAttr 自定义房间属性值
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidRecoverCustomRoomAttrUpdateMessage:(NSDictionary *)updateAttr;

/// 在当前房间获取到聊天数据
/// @param subRoomManager 房间管理者对象
/// @param message 聊天数据结构体
/// @param rec_type 消息类型(1:针对用户,2:针对房间)
/// @param senderUserInfo 发送者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidRecoverChatMessage:(ChatMessageModel *)message RecoverType:(NSInteger)rec_type SenderUserInfo:(RoomUserInfoModel *)senderUserInfo;

/// 获取到用户的共享状态更改
/// @param subRoomManager 房间管理者对象
/// @param share_info 共享状态model
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidRecoverUserShareStateChanged:(PL2_MeetingShareStateModel *)share_info;

/// 获取当前房间正在讲话者声音最大的信息回调
/// @param subRoomManager 房间管理者对象
/// @param speaker_info 声音最大者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager MeetingCurrentSpeakerInfo:(RoomUserInfoModel *)speaker_info;

//收到邀请加入子房间

/// 获取邀请到其他子房间的请求
/// @param subRoomManager 房间管理者对象
/// @param target_lvb_room_id 目标房间
/// @param users 被邀请者的用户list
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager RecoverSubroomChangedRequest:(NSInteger)target_lvb_room_id TargetUsers:(NSArray<NSNumber *> *)users;

/// 获取到某房间呼叫host的消息
/// @param subRoomManager 房间管理者对象
/// @param lvb_room_id 目标房间
/// @param info 发送者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager RecoverSubroomCallHostFromRoomWithId:(NSInteger)lvb_room_id SenderUserInfo:(PL2_UserInfoModel *)info;

/// 获取到取消分组的消息
/// @param subRoomManager 房间管理者对象
/// @param lvb_room_id 当前所在的分组
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidBeenDissolved:(NSInteger)lvb_room_id;

@optional

/// 获取到某用户从某子房间移动到另一个房间
/// @param subRoomManager 房间管理者对象
/// @param user_info 移动者的用户信息
/// @param breakoutId 原所在房间的中台Id
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager RemoteUserDidChangedBreakout:(PL2_UserInfoModel *)user_info LastBreakoutId:(NSInteger)breakoutId;

/// 获取到某房间内的用户信息更新
/// @param subRoomManager 房间管理者对象
/// @param update_type 更新信息枚举(name,avatar,role等)
/// @param info 修改者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidRecoverSystemMessageWithUserInfoUpdate:(PL2_UserPowerChangedEnum)update_type WithUserInfo:(PL2_UserInfoModel *)info;

/// 获取到某房间内用户已离开当前会议
/// @param subRoomManager 房间管理者对象
/// @param info 离开者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidRecoverUserLeaveTheSystemWithUserInfo:(PL2_UserInfoModel *)info;

/// 获取到某用户加入到该会议
/// @param subRoomManager 房间管理者对象
/// @param info 加入者的用户信息
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager DidRecoverUserJoinTheSystemWithUserInfo:(PL2_UserInfoModel *)info;

/// 白板会话事件

/// 当前白板绘画的内容
/// @param subRoomManager 房间管理者对象
/// @param json_message 绘画内容的json数据
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager WhiteboardDrawInfoWithJson:(NSString *)json_message;

/// 获取到房间其他人的绘画数据
/// @param subRoomManager 房间管理者对象
/// @param json_message 绘画内容的json数据
- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager WhiteboardDidRecoverDrawInfoJson:(NSString *)json_message;

@end

@protocol PL2_MeetingSubRoomConnectDelegate <NSObject>

- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager SubroomCallHostToSubroom:(NSInteger)subroom_lvb_id;

- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager ManageSendBroatcaseMessageFromSubroom:(NSInteger)lvb_room_id Message:(NSString *)message SenderUserInfo:(RoomUserInfoModel *)info;

- (void)PL2_MeetingSubRoomManager:(PL2_MeetingSubRoomManager *)subRoomManager StarBreakoutWithInfo:(NSArray<PL2_GroupInfoModel *> *)breakout_info;

@end

#endif /* PL2_MeetingSubRoomManagerDelegate_h */
