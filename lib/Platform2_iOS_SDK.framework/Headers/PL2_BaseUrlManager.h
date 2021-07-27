//
//  PL2_BaseUrlManager.h
//  platform_2_ios_sdk
//
//  Created by Fox Doggy on 2021/6/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PL2_BaseUrlManager : NSObject

@property (copy, nonatomic) NSString *PL2_RequestURLDomain;
@property (copy, nonatomic) NSString *PL_WSHOSTURL;

+ (instancetype)shareManager;

+ (void)destory;

@end

NS_ASSUME_NONNULL_END
