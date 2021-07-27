//
//  PL2_MeetingSubRoomManager.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/6/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PL2_MeetingSubRoomManagerDelegate.h"
#import "PL2_RoomInfoDataModel.h"
#import "PL2_MeetingRoomAttrModel.h"
#import "PL2_ShadowManagerDelegate.h"

NS_ASSUME_NONNULL_BEGIN
@class PL2_WebSocketManager;
typedef void(^PL_SubroomLoadCompleted)(BOOL isSuccess, NSArray<RoomUserInfoModel *> *_Nullable meetingUsers, PL2_MeetingRoomAttrModel *_Nullable roomAttrs);


@interface PL2_MeetingSubRoomManager : NSObject<PL2_ShadowManagerDelegate>

@property (weak, nonatomic) id<PL2_MeetingSubRoomManagerDelegate> delegate;
@property (strong, nonatomic, readonly) RoomUserInfoModel *user_info;
@property (strong, nonatomic, readonly) PL2_MeetingRoomAttrModel *subroom_attr;
@property (strong, nonatomic, readonly) PL2_SubRoomInfoDataModel *subroomInfo;
@property (strong, nonatomic, readonly) NSMutableDictionary<NSNumber *, RoomUserInfoModel *> *subRoomUsers;
@property (assign, nonatomic, readonly) NSInteger subroomId;

/// 初始化Manager
/// @param info 带有用户状态的用户信息
/// @param wb_manager WebSocketManager对象
/// @param mainRoomId 主房间的HashId
/// @param lvbId 目标房间的中台Id
/// @param delegate <PL2_MeetingSubRoomConnectDelegate>的代理执行对象
/// @param room_info 所创建的房间信息model
- (instancetype)initWithUserInfo:(RoomUserInfoModel *)info
                 WebsocketObject:(PL2_WebSocketManager *)wb_manager
                  MainRoomHashId:(NSString *)mainRoomId
                   MainRoomLvbId:(NSInteger)lvbId
                 ConnectDelegate:(id<PL2_MeetingSubRoomConnectDelegate>)delegate
                        RoomInfo:(PL2_RoomInfoDataModel *)room_info;

/// 加入目标房间
/// @param subRoomId 目标房间的中台Id
/// @param wbBaseView 小屏下的白板显示UI的承接View
/// @param screenView 大屏下的白板显示UI的承接View
/// @param isSpeaker 是否默认扬声器播放
/// @param handler 加入后回调(BOOL:是否加入成功, NSArray:当前房间内的成员, PL2_MeetingRoomAttrModel:当前房间的属性)
- (void)joinSubRoomWithId:(NSInteger)subRoomId
         WhiteBoardBaseUI:(__kindof UIView *_Nullable)wbBaseView
       WhiteBoardScreenUI:(__kindof UIView *_Nullable)screenView
                isSpeaker:(BOOL)isSpeaker
         CompletedHandler:(PL_SubroomLoadCompleted)handler;


/// 修改目标用户的权限
/// @param powerName 权限枚举
/// @param value 目标修改值
/// @param uid 目标用户的中台Id
- (void)PL2_SendPowerChangedMessageWithType:(PL2_UserPowerChangedEnum)powerName
                                      Value:(NSNumber *)value
                                 TargetUser:(NSInteger)uid;

/// 发送聊天消息给当前房间/指定用户
/// @param content 要发送的聊天内容
/// @param userId 目标用户的中台Id
- (void)PL2_SendChatMessageWithContentText:(NSString *)content
                              ToUserWithID:(NSNumber *_Nullable)userId;

/// 发送自定义的Control消息
/// @param jsonMessage control消息的json结构
/// @param userId 若该消息为ToUser->填入指定的目标用户的中台Id
/// @param lvb_room_id 若该消息为ToRoom->指定的目标房间的中台Id
- (void)PL2_SendControlCustomSignalJsonMessage:(NSString *)jsonMessage
                                        ToUser:(NSInteger)userId
                                      OrToRoom:(NSInteger)lvb_room_id;

/// 更新用户的基本信息
/// @param user_lvb_id 指定目标人的中台Id
/// @param type 修改类型的枚举(name,avatar)
/// @param value 修改后的值
- (void)PL2_UpdateUserInfoWithLvbUserId:(NSNumber *)user_lvb_id
                             UpdateType:(PL2_UserInfoUpdateType)type
                              WithValue:(NSString *)value;

/// 给某个用户co-host权限(仅host可用)
/// @param uid 目标用户的中台Id
- (void)PL2_GiveUserCoHostToUserWithId:(NSUInteger)uid;

/// 修改当前用户的分享状态(desktop/whiteboard)(仅host/co-host可用)
/// @param shareType 共享状态的字符串(desktop/whiteboard)
- (void)PL2_ShareStateChangedWithShareType:(NSString *)shareType;

/// 当前用户的举手/取消举手行为
/// @param handValue 0:取消举手,1:举手
- (void)PL2_HandUpOrDownAttrbuteChanged:(NSUInteger)handValue;

/// 对某用户的举手进行应答(仅host/co-host可用)
/// @param uid 目标用户的中台Id
- (void)PL2_HandUpAckMessageWithUserId:(NSUInteger)uid;

/// 修改房间状态的属性(仅host/co-host可用)
/// @param value <key:属性名, value:属性值>
- (void)PL2_ChangedRoomAttrWithValue:(NSDictionary<NSString *, NSString *> *)value;

/// 发送白板的绘制数据
/// @param jsonMessage 白板绘制数据的json字符串
/// @param room_lvb_id 发送到目标房间的中台Id
- (void)PL2_SendWhiteBoardDrawJsonMessage:(NSString *)jsonMessage
                          ToRoomWithLvbId:(NSInteger)room_lvb_id;

/// 踢出某用户(仅host/co-host可用)
/// @param userId 目标用户的中台Id
- (void)PL2_KickOutUserWithId:(NSInteger)userId;

/// 在当前房间呼叫Host
- (void)PL2_SubroomCallHost;

/// 对进入某个子房间进行应答回复
/// @param to_lvb_id 目标房间的中台Id
/// @param completed 响应后的回调(BOOL:可否进入,NSError:错误消息)
- (void)PL2_ConfirmAckIntoTargetSubroomWithId:(NSInteger)to_lvb_id
                             CompletedHandler:(nonnull void (^)(BOOL isSuccess, NSError *_Nullable error))completed;

/// 取消当前所有分组(仅host/co-host可用)
/// @param completed 回调函数
- (void)PL2_StopAllSubrooms:(void (^ _Nullable)(BOOL isSuccess, NSError *error))completed;

/// 发送全局广播消息(仅host/co-host可用)
/// @param message 广播消息内容
- (void)PL2_ManagerSendBroatcaseMessage:(NSString *)message;

/// 指定某些用户回到主房间(仅host/co-host可用)
/// @param users 目标用户的中台Id的list结构
- (void)PL2_ManagerBreakoutBackHomeWithUsers:(NSArray<NSNumber *> *)users;

/// 指定某个用户到某个子房间(仅host/co-host可用)
/// @param user_id 目标用户的中台Id
/// @param to_lvb_id 要到达的目标房间中台Id
- (void)PL2_SubroomSendMemberMoveRequestWithMemberId:(NSNumber *)user_id
                                ToTargetSubroomLvbId:(NSInteger)to_lvb_id;

///rtc 部分

/// 调转摄像头(默认开启前置摄像头)
- (void)switchCamera;

/// 修改扬声器模式(扬声器/听筒)
/// @param isSpeaker 是否为扬声器模式
- (void)changedSoundMode:(BOOL)isSpeaker;

/// 设置本地音频流可用状态
/// @param enable 是否可用(YES:可用, NO:不可用)
- (void)settingLocalAudioStreamState:(BOOL)enable;

/// 设置本地视频流可用状态
/// @param enable 是否可用(YES:可用, NO:不可用)
- (void)settingLocalVideoStreamState:(BOOL)enable;

/// 预览回显本地的视频流数据
/// @param displayUI 用于显示视频的UI
/// @param isFull 是否铺满显示(YES: 铺满显示, NO: 自适应显示)
- (void)previewLocalVideoWithUI:(__kindof UIView *_Nullable)displayUI isFullDisplay:(BOOL)isFull;

/// 显示远端用户的视频流数据
/// @param user_id 远端用户的中台Id
/// @param displayUI 用于显示视频的UI
/// @param isFull 是否铺满显示(YES: 铺满显示, NO: 自适应显示)
- (void)showRemoteUserWithId:(NSInteger)user_id DisplayUI:(__kindof UIView *_Nullable)displayUI isFullDisplay:(BOOL)isFull;

///whiteboard 部分

/// 设置白板颜色
/// @param color 颜色对象
- (void)whiteBoardSetColor:(UIColor *)color;

/// 设置白板输入文字
/// @param text 要显示的文字
- (void)whiteBoardSetText:(NSString *)text;

/// 设置白板笔的样式
/// @param trackStyle 笔样式枚举
- (void)whiteBoardSetDrawStyle:(DXZEducationWhiteboardTrackStyle)trackStyle;

/// 白板清屏
- (void)whiteBoardClearAction;

/// 白板撤销上一步
- (void)whiteBoardPreviousLastStep;

/// 离开房间
- (void)leaveSubroom;

@end

NS_ASSUME_NONNULL_END
