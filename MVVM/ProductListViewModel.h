//
//  ProductListViewModel.h
//  MVVM
//
//  Created by develop on 15/9/17.
//  Copyright (c) 2015年 songhailiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ProductListCellViewModel.h"
#import "BaseViewModel.h"
#import "APIClient.h"

@interface ProductListViewModel : BaseViewModel

/**
 *  数据
 */
@property (nonatomic, strong) NSArray *items; //这里不能用NSMutableArray，因为NSMutableArray不支持KVO，不能被RACObserve
/**
 *  是否有更多数据
 */
@property (nonatomic, strong) RACSignal *hasMoreData;

/**
 *  获取数据Command
 */
@property (nonatomic, strong, readonly) RACCommand *fetchProductCommand;

/**
 *  获取更多数据
 */
@property (nonatomic, strong, readonly) RACCommand *fetchMoreProductCommand;


- (ProductListCellViewModel *)itemViewModelForIndex:(NSInteger)index;

@end
