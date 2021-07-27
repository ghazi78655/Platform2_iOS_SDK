//
//  PL2_WBRoomAttrDataModel.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/5/10.
//

#import "PL2_WBMessageModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface PL2_WBRoomAttrDataModel : PL2_WBMessageModel

@property (strong, nonatomic, nullable) NSMutableDictionary<NSString *, NSObject<NSCopying> *> *Attrs;

@end

NS_ASSUME_NONNULL_END
