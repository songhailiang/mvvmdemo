//
//  APIClient.h
//  MVVM
//
//  Created by develop on 15/9/17.
//  Copyright (c) 2015年 songhailiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>
#import <ReactiveCocoa/ReactiveCocoa.h>
#import "ResponseData.h"

@interface APIClient : AFHTTPSessionManager

+ (APIClient *)sharedClient;

- (RACSignal *)httpGet:(NSString *)URLString parameters:(id)parameters;

@end

@interface APIClient (Product)

/**
 *  获取产品列表
 *
 *  @return http request signal
 */
- (RACSignal *)fetchProductWithPageIndex:(NSNumber *)page;

@end