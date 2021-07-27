//
//  PL2_GroupInfoModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/6/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PL2_GroupInfoModel : NSObject

@property (assign, nonatomic) NSInteger lvbRoomId;
@property (copy, nonatomic) NSString *name; //分组名
@property (copy, nonatomic) NSArray<NSNumber *> *users; // 组内成员

@end

@interface PL2_GroupBreakoutResponseModel : NSObject

@property (copy, nonatomic) NSArray<PL2_GroupInfoModel *> *rooms;

@end

NS_ASSUME_NONNULL_END
