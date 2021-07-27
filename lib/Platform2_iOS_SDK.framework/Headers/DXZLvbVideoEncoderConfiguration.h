//
//  DXZLvbVideoEncoderConfiguration.h
//  DXZLVBLib
//
//  Created by FoxDog on 2020/4/26.
//  Copyright © 2020 DXZVideoGroup. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DXZLvbVideoEncoderConfiguration : NSObject

@property (nonatomic, assign, readonly) CGSize video_size;
@property (nonatomic, assign, readonly) NSUInteger frameRate;
@property (nonatomic, assign, readonly) NSUInteger bitrate;

- (instancetype)initWithEncoderType:(DXZLvbVideoEncodeType)encodeType;

@end

NS_ASSUME_NONNULL_END
