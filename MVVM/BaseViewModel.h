//
//  BaseViewModel.h
//  MVVM
//
//  Created by develop on 15/9/23.
//  Copyright © 2015年 songhailiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>

@interface BaseViewModel : NSObject

@property (nonatomic) RACSubject *errors;

/**
 *  取消请求Command
 */
@property (nonatomic, strong, readonly) RACCommand *cancelCommand;

@end
