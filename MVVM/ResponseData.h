//
//  ResponseData.h
//  licai
//
//  Created by develop on 15/1/5.
//  Copyright (c) 2015年 jihc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MJExtension/MJExtension.h>
#import "Page.h"

typedef NS_ENUM(NSInteger, ErrorCode){
    
    kErrorCodeSucess =    1, //成功
    kErrorCodeFail   =    2, //失败
    kErrorCodeAppIdInvalid = 3, //AppId无效
};

@interface ResponseData : NSObject

@property (assign, nonatomic) BOOL success;
@property (assign, nonatomic) int errorCode;
@property (strong, nonatomic) NSString *message;
@property (strong, nonatomic) NSObject *data;
@property (strong, nonatomic) Page *page;

- (NSError *)error;

@end
