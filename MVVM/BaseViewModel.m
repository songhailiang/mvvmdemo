//
//  BaseViewModel.m
//  MVVM
//
//  Created by develop on 15/9/23.
//  Copyright © 2015年 songhailiang. All rights reserved.
//

#import "BaseViewModel.h"

@implementation BaseViewModel

- (instancetype)init {
    self = [super init];
    if (self) {
        _errors = [RACSubject subject];
        
        _cancelCommand = [[RACCommand alloc]initWithSignalBlock:^RACSignal *(id input) {
            return [RACSignal empty];
        }];
    }
    
    return self;
}

- (void)dealloc {
    [_errors sendCompleted];
}

@end
