//
//  PL2_WBMessageModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/5/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PL2_WBMessageModel : NSObject

@property (copy, nonatomic) NSString *MsgType;
@property (copy, nonatomic) NSString *Category;
@property (assign, nonatomic) NSInteger RoomId;
@property (copy, nonatomic) NSString *SenderId;
@property (assign, nonatomic) NSInteger RecvType; // 0:未知 1:用户 2:房间
@property (copy, nonatomic) NSString *RecvId;
@property (copy, nonatomic) NSString *Message;

@end

NS_ASSUME_NONNULL_END
