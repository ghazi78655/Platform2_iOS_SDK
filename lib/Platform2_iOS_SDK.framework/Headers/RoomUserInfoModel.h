//
//  RoomUserInfoModel.h
//  DXZLVBLib
//
//  Created by FoxDog on 2020/4/20.
//  Copyright © 2020 DXZVideoGroup. All rights reserved.
//

#import "PL2_UserInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface RoomUserInfoModel : PL2_UserInfoModel<NSCopying>

@property (copy, nonatomic) NSNumber *video;

@property (copy, nonatomic) NSNumber *audio;

@property (copy, nonatomic) NSNumber *platform;

@property (copy, nonatomic) NSNumber *chat;

@property (copy, nonatomic) NSNumber *wb;

@property (copy, nonatomic) NSNumber *hand;

@property (copy, nonatomic) NSString *share; // none, whiteboard, desktop

@end

NS_ASSUME_NONNULL_END
