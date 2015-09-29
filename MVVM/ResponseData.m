//
//  ResponseData.m
//  licai
//
//  Created by develop on 15/1/5.
//  Copyright (c) 2015年 jihc. All rights reserved.
//

#import "ResponseData.h"

@implementation ResponseData

+(NSDictionary *)replacedKeyFromPropertyName {
    return @{ @"success" : @"Success",
              @"errorCode" : @"ErrorCode",
              @"message" : @"Message",
              @"data" : @"Data",
              @"page" : @"Page"};
}

- (NSError *)error {
    return [NSError errorWithDomain:@"ERROR" code:self.errorCode userInfo:@{@"Success":@(self.success), @"ErrorCode": @(self.errorCode), @"Message":self.message}];
}

@end
