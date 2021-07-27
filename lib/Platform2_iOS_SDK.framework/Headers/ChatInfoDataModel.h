//
//  ChatInfoDataModel.h
//  AgoraEducation
//
//  Created by FoxDog on 2020/3/25.
//  Copyright © 2020 yangmoumou. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ChatInfoDataModel : NSObject<NSCopying>

@property (nonatomic, copy) NSString *content;
@property (nonatomic, copy) NSString *kind;
@property (nonatomic, copy) NSString *time;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSNumber *userId;
@property (nonatomic, copy) NSNumber *extUserId;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *userRole;

+ (instancetype)sendChatInfoWithUserId:(NSNumber *)uid UserName:(NSString *)userName ChatContent:(NSString *)content Role:(NSString *)role;

+ (instancetype)sendSystemMessageWithText:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
