//
//  LvbRTCStatsModel.h
//  DXZLVBLib
//
//  Created by FoxDog on 2020/4/26.
//  Copyright © 2020 DXZVideoGroup. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LvbRTCUserInfoModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *external_id;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *role;

@end

@interface LvbRTCSystemInfoModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *device;
@property (nonatomic, copy) NSString *deviceVersion;
@property (nonatomic, copy) NSString *os;
@property (nonatomic, copy) NSString *language;
@property (nonatomic, copy) NSString *onVersion;

@end

@interface LvbRTCRemoteVideoStatsModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *packetLossRate;
@property (nonatomic, copy) NSString *width;
@property (nonatomic, copy) NSString *height;
@property (nonatomic, copy) NSString *receivedBitrate;
@property (nonatomic, copy) NSString *decoderOutputFrameRate;
@property (nonatomic, copy) NSString *rendererOutputFrameRate;
@property (nonatomic, copy) NSString *totalFrozenTime;
@property (nonatomic, copy) NSString *frozenRate;

@end

@interface LvbRTCRemoteAudioStatsModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *packetLossRate;
@property (nonatomic, copy) NSString *receivedBitrate;
@property (nonatomic, copy) NSString *totalFrozenTime;
@property (nonatomic, copy) NSString *frozenRate;
@property (nonatomic, copy) NSString *networkTransportDelay;

@end

@interface LvbRTCLocalVideoStatsModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *sentBitrate;
@property (nonatomic, copy) NSString *sentFrameRate;
@property (nonatomic, copy) NSString *targetBitrate;
@property (nonatomic, copy) NSString *width;
@property (nonatomic, copy) NSString *height;
@property (nonatomic, copy) NSString *codecType;

@end

@interface LvbRTCLocalAudioStatsModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *sampleRate;
@property (nonatomic, copy) NSString *sentBitrate;

@end

@interface LvbRTCNetworkStatsModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *upLinkQuality;
@property (nonatomic, copy) NSString *downLinkQuality;

@end

@interface LvbRTCClientStatsModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *duration;
@property (nonatomic, copy) NSString *recvBitrate;
@property (nonatomic, copy) NSString *recvBytes;
@property (nonatomic, copy) NSString *sendBitrate;
@property (nonatomic, copy) NSString *sendBytes;
@property (nonatomic, copy) NSString *userCount;

@end

@interface LvbRTCAppStatsModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *cpuAppUsage;
@property (nonatomic, copy) NSString *cpuTotalUsage;
@property (nonatomic, copy) NSString *memoryAppUsageRatio;
@property (nonatomic, copy) NSString *memoryTotalUsageRatio;

@end

@interface LvbRTCStatsModel : NSObject

@property (nonatomic, copy) LvbRTCUserInfoModel *userInfo;
@property (nonatomic, copy) LvbRTCSystemInfoModel *systemInfo;
@property (nonatomic, copy) NSArray<LvbRTCRemoteVideoStatsModel *> *remoteVideoState;
@property (nonatomic, copy) NSArray<LvbRTCRemoteAudioStatsModel *> *remoteAudioState;
@property (nonatomic, copy) NSArray<LvbRTCLocalVideoStatsModel *> *localVideoState;
@property (nonatomic, copy) NSArray<LvbRTCLocalAudioStatsModel *> *localAudioState;
@property (nonatomic, copy) LvbRTCNetworkStatsModel *networkState;
@property (nonatomic, copy) LvbRTCClientStatsModel *clientState;
@property (nonatomic, copy) NSString *networkType;
@property (nonatomic, copy) NSString *rtt;
@property (nonatomic, copy) LvbRTCAppStatsModel *appState;
@property (nonatomic, copy) NSString *roomId;
@property (copy, nonatomic) NSString *appKey;

- (instancetype)initWithUserInfo:(LvbRTCUserInfoModel *)userModel SystemInfo:(LvbRTCSystemInfoModel *)systemInfo RoomId:(NSString *)roomId;

@end

NS_ASSUME_NONNULL_END
