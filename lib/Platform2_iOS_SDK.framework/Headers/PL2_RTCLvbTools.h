//
//  PL2_RTCLvbTools.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/5/7.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

#define kDXZLvbWiteboardActiveNotificationName      @"kDXZLvbWiteboardActiveNotification"

struct PL2_RoomInfoStruct {
    NSInteger user_id;
    NSInteger room_id;
    NSString *_Nullable app_key;
    NSString *_Nullable token;
};
typedef struct CG_BOXABLE PL2_RoomInfoStruct PL2_RoomInfoStruct;

CG_INLINE PL2_RoomInfoStruct PL2_RoomInfoMake(NSInteger user_id, NSInteger room_id, NSString *_Nullable app_key, NSString *_Nullable token)
{
    PL2_RoomInfoStruct info;
    info.user_id = user_id;
    info.room_id = room_id;
    info.app_key = app_key;
    info.token = token;
    return info;
}

#define PL2_RoomInfoNULL PL2_RoomInfoMake(0, 0, nil, nil)
#define PL2_RoomInfoIsEqualToNULL(struct) ({\
struct.user_id == 0 && struct.room_id == 0 && struct.app_key == nil && struck.token == nil\
})

struct PL2_UserLocalLvbStateStruct {
    BOOL audioEnable;
    BOOL videoEnable;
};
typedef struct CG_BOXABLE PL2_UserLocalLvbStateStruct PL2_UserLocalLvbStateStruct;
CG_INLINE PL2_UserLocalLvbStateStruct PL2_UserLocalLvbStateMake(BOOL audioState, BOOL videoState)
{
    PL2_UserLocalLvbStateStruct lvbState;
    lvbState.audioEnable = audioState;
    lvbState.videoEnable = videoState;
    return lvbState;
}

typedef NS_ENUM(NSUInteger, RTCLvbRoleType) {
    RTCLvbRole_Host,
    RTCLvbRole_Audience
};

typedef NS_ENUM(NSUInteger, DXZLvbVideoEncodeType) {
    DXZLvbVideoEncode_High,
    DXZLvbVideoEncode_Middle,
    DXZLvbVideoEncode_Low
};

typedef NS_ENUM(NSUInteger, DXZLvbWhiteboardTypeEnum) {
    DXZLvbWhiteboardType_NULL,
    DXZLvbWhiteboardType_DRW_LINE,
    DXZLvbWhiteboardType_DRW_STRAIGHT_LINE,
    DXZLvbWhiteboardType_DRW_RECT,
    DXZLvbWhiteboardType_DRW_ROUND,
    DXZLvbWhiteboardType_DRW_TEXT,
    DXZLvbWhiteboardType_DRW_IMAGE,
    DXZLvbWhiteboardType_DRW_DEL_IMAGE,
    DXZLvbWhiteboardType_DRW_DELETE,
    DXZLvbWhiteboardType_DRW_CLEARALL,
    DXZLvbWhiteboardType_DRW_REVOKE,
    DXZLvbWhiteboardType_DRW_REVOKE_ON,
    DXZLvbWhiteboardType_DRW_REVOKE_OFF,
    DXZLvbWhiteboardType_DRW_PAGE,
    DXZLvbWhiteboardType_DRW_PAGE_CHANGE,
    DXZLvbWhiteboardType_DRW_PAGE_DELETE,
    DXZLvbWhiteboardType_DRW_HISTORY
};

typedef NS_ENUM(NSUInteger, DXZEducationWhiteboardTrackStyle) {
    DXZEducationWhiteboard_NULL,
    DXZEducationWhiteboard_Graffiti_Tool,
    DXZEducationWhiteboard_Line_Tool,
    DXZEducationWhiteboard_Rect_Tool,
    DXZEducationWhiteboard_Circle_Tool,
    DXZEducationWhiteboard_Text_Tool
};

typedef NS_ENUM(NSUInteger, PL2_WBMessageCategoryType) {
    WBMessageCategory_UNKNOWN,
    WBMessageCategory_ROOM_START,
    WBMessageCategory_ROOM_STOP,
    WBMessageCategory_USER_STATUS,
    WBMessageCategory_ROOM_ATTR,
    WBMessageCategory_USER_ATTR,
    WBMessageCategory_CONTROL_MESSAGE,
    WBMessageCategory_CHAT_MESSAGE,
    WBMessageCategory_WHITEBOARD_MESSAGE,
    WBMessageCategory_KICK_OUT
};

typedef NS_ENUM(NSUInteger, PL2_RTMServerConnectState) {
    PL2_RTMServerConnect_Empty,
    PL2_RTMServerConnect_New,
    PL2_RTMServerConnect_Connecting,
    PL2_RTMServerConnect_Loading,
    PL2_RTMServerConnect_FinishLoad,
    PL2_RTMServerConnect_Reconnect,
    PL2_RTMServerConnect_TimeOut,
    PL2_RTMServerConnect_Failure,
    PL2_RTMServerConnect_Close
};

typedef NS_ENUM(NSUInteger, DXZLvbControlType) {
    DXZLvb_CTL_NULL,
    DXZLvb_CTL_HAND,
    DXZLvb_CTL_KICK_OUT,
    DXZLvb_CTL_AUDIO,
    DXZLvb_CTL_PLATFORM,
    DXZLvb_CTL_CUSTOM,
    DXZLvb_CTL_BREAKOUT,
    DXZLvb_CTL_MOVEUSERTOSUBROOM,
    DXZLvb_CTL_CALLHOST,
    DXZLvb_CTL_BROADCAST,
    DXZLvb_CTL_REMOTECTL
};

typedef NS_ENUM(NSUInteger, PL2_UserPowerChangedEnum) {
    PL2_UserPowerEnum_Undefine,
    PL2_UserPowerEnum_Name,
    PL2_UserPowerEnum_Avatar,
    PL2_UserPowerEnum_Audio,
    PL2_UserPowerEnum_Video,
    PL2_UserPowerEnum_Whiteboard,
    PL2_UserPowerEnum_Hand,
    PL2_UserPowerEnum_Chat,
    PL2_UserPowerEnum_Platform,
    PL2_UserPowerEnum_Share,
    PL2_UserPowerEnum_Role,
    PL2_UserPowerEnum_Group
};

typedef NS_ENUM(NSUInteger, PL2_GroupBreakActionType) {
    PL2_GroupBreakAction_BreakOut,
    PL2_GroupBreakAction_Dissolve
};

typedef NS_ENUM(NSUInteger, PL2_GroupMemberMoveAction) {
    PL2_GroupMemberMoveAction_Request,
    PL2_GroupMemberMoveAction_Confirm
};

typedef NS_ENUM(NSUInteger, PL2_UserInfoUpdateType)  {
    PL2_UserInfoUpdate_Undefine,
    PL2_UserInfoUpdate_Name,
    PL2_UserInfoUpdate_Avatar
};

@interface PL2_RTCLvbTools : NSObject

DXZLvbWhiteboardTypeEnum dxzLvbWBDrwTypeTansform(NSString *drwType);

PL2_WBMessageCategoryType WebSocketMessageCatogoryEnum(NSString *category);

NSString *_Nullable translateWebSocketMessageCategory(PL2_WBMessageCategoryType categoryType);

DXZLvbControlType translateControlTypeEnum(NSString *type);

PL2_UserPowerChangedEnum translatePowerEnumName(NSString *powerName);

NSString *_Nullable translatePowerEnumToString(PL2_UserPowerChangedEnum powerName);

PL2_UserInfoUpdateType translateUserInfoUpdateType(NSString *updateItem);

NSString *_Nullable translateUserInfoUpdateTypeToString(PL2_UserInfoUpdateType updateType);

@end

NS_ASSUME_NONNULL_END
