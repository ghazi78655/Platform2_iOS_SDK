//
//  PL2_HTTPRequest.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/5/7.
//

#import <Foundation/Foundation.h>
#import "PL2_GroupInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface PL2_HTTPRequest : NSObject

+ (instancetype)shareRequestManager;

- (void)updateRequestAuthToken:(NSString *)token;

+ (void)get:(NSString *)url
     params:(NSDictionary *)params
    headers:(NSDictionary *)headers
    success:(void (^ _Nullable)(id responseObj))success
    failure:(void (^ _Nullable)(NSError *error))failure;

+ (void)post:(NSString *_Nonnull)url
      params:(NSDictionary *_Nullable)params
     headers:(NSDictionary *)headers
     success:(void (^)(id responseObj))success
     failure:(void (^)(NSError *error))failure;

/// 发送RTM针对房间的消息
/// @param roomId 房间id
/// @param jsonMessage 消息体的jsonString
/// @param handler 回调函数
+ (void)sendMessageRoomId:(NSString *_Nullable)roomId
                LvbRoomId:(NSNumber *_Nullable)lvbRoomId
          SenderUserLvbId:(NSNumber *_Nullable)senderId
           ContentMessage:(NSString *)jsonMessage
         CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 发送聊天消息
/// @param userId 目标用户id
/// @param room_id 房间id
/// @param json_content 消息体的jsonString
/// @param handler 回调函数
+ (void)sendChatContentMessageToUser:(NSNumber *_Nullable)userId
                      OrToRoomWithId:(NSString *_Nullable)room_id
                           RoomLvbId:(NSNumber *_Nullable)roomLvbId
                        SenderUserId:(NSNumber *_Nullable)senderId
                   ContentJsonString:(NSString *)json_content
                    CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 发送RTM消息到某用户
/// @param userId 用户id
/// @param jsonMessage 消息体的jsonString
/// @param handler 回调函数
+ (void)sendMessageToUser:(NSInteger)userId
           ContentMessage:(NSString *)jsonMessage
         CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 设置房间属性
/// @param room_id 房间id
/// @param attr_map 设置的属性内容
/// @param handler 回调函数
+ (void)settingRoomAttributeWithRoomId:(NSString *_Nullable)room_id
                             RoomLvbId:(NSNumber *_Nullable)roomLvbId
                          SenderUserId:(NSNumber *_Nullable)senderId
                    TargetAttributeMap:(NSDictionary *)attr_map
                      CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler ;

/// 设置用户属性
/// @param roomId 房间id
/// @param userId 用户id
/// @param attr_map 设置的属性内容
/// @param handler 回调函数
+ (void)settingUserAttributeWithRoomId:(NSString *_Nullable)roomId
                             LvbRoomId:(NSNumber *_Nullable)lvbRoomId
                              SenderId:(NSNumber *_Nullable)senderId
                          TargetUserId:(NSNumber *_Nullable)userId
                          AttributeMap:(NSDictionary *)attr_map
                      CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 设置用户初始化属性
/// @param roomId 房间id
/// @param attr_map 属性内容
/// @param handler 回调函数
+ (void)settingDefaultUserAttributeWithRoomId:(NSString *_Nullable)roomId
                                    RoomLvbId:(NSNumber *_Nullable)roomLvbId
                                 SenderUserId:(NSNumber *_Nullable)senderId
                                 AttributeMap:(NSDictionary *)attr_map
                             CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 同步白板信息
/// @param room_id 房间id
/// @param handler 回调函数
+ (void)syncWhiteBoardHistoryDataWithRoomId:(NSString *_Nullable)room_id
                                  LvbRoomId:(NSNumber *_Nullable)lvbRoomId
                           CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 发送推流请求
/// @param roomId 房间id
/// @param handler 回调函数
+ (void)startPushRequestWithRoomId:(NSString *_Nullable)roomId
                         RoomLvbId:(NSNumber *_Nullable)lvbRoomId
                  CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 发送停止推流请求
/// @param roomId 房间id
/// @param handler 回调函数
+ (void)stopPushWithRoomId:(NSString *_Nullable)roomId
                 RoomLvbId:(NSNumber *_Nullable)lvbRoomId
          CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 发送提出某用户的接口请求
/// @param roomId 房间id
/// @param userId 被踢用户id
/// @param handler 回调函数
+ (void)kickOutUserWithRoomId:(NSString *_Nullable)roomId
                   KickUserId:(NSNumber *_Nullable)userId
             CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 发送开始/结束分组消息
/// @param breakType 分组消息类型
/// @param roomId 房间id
/// @param groups 分组信息数组
/// @param handler 回调函数
+ (void)groupBreakActionWithType:(PL2_GroupBreakActionType)breakType
                          RoomId:(NSString *_Nullable)roomId
                          Groups:(NSArray<PL2_GroupInfoModel *> * _Nullable)groups
                CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

+ (void)groupBreakoutBackHomeWithUsers:(NSArray <NSNumber *>*)users
                            RoomHashId:(NSString *)room_id
                      CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

+ (void)confirmBreakoutWithTargetLvbRoomId:(NSInteger)lvb_room_id
                            MainRoomHashId:(NSString *)mainRoomId
                          CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

+ (void)RoomInfoWithCode:(NSString *)room_code
        CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

+ (void)JoinShadowRoom:(NSString *)roomHashId
              Password:(NSString *_Nullable)password
      CompletedHandler:(void (^ _Nullable)(BOOL isSuccess, NSError *_Nullable error, id _Nullable responseObj))handler;

/// 销毁该对象
+ (void)destory;

@end

NS_ASSUME_NONNULL_END
