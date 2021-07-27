//
//  ChatMessageModel.h
//  DXZLVBLib
//
//  Created by FoxDog on 2020/4/21.
//  Copyright © 2020 DXZVideoGroup. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ChatMessageModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *content;
@property (nonatomic, copy) NSString *roomId;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSNumber *userId;
@property (nonatomic, copy) NSString *role;
@property (nonatomic, copy) NSString *Id;
@property (nonatomic, copy) NSString *userRole;
@property (nonatomic, copy) NSString *type;
@property (copy, nonatomic) NSString *time;
@property (copy, nonatomic) NSString *avatar;

@end

NS_ASSUME_NONNULL_END
