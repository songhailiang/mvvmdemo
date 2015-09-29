//
//  ProductListViewModel.m
//  MVVM
//
//  Created by develop on 15/9/17.
//  Copyright (c) 2015年 songhailiang. All rights reserved.
//

#import "ProductListViewModel.h"

@interface ProductListViewModel ()

@property (nonatomic, strong) Page *page;

@end

@implementation ProductListViewModel

#pragma mark - init

- (instancetype)init {
    if (self = [super init]) {
        
        [self initCommand];
        
        [self initSubscribe];
    }
    return self;
}

- (void)initCommand {
    
    _fetchProductCommand = [[RACCommand alloc]initWithSignalBlock:^RACSignal *(id input) {
        
        return [[[APIClient sharedClient]
                 fetchProductWithPageIndex:@(1)]
                 takeUntil:self.cancelCommand.executionSignals];
    }];
    
    _fetchMoreProductCommand = [[RACCommand alloc]initWithSignalBlock:^RACSignal *(id input) {
        return [[[APIClient sharedClient] fetchProductWithPageIndex:@(self.page.PageIndex+1)] takeUntil:self.cancelCommand.executionSignals];
    }];
    
    _hasMoreData = [RACObserve(self, page) map:^id(Page *p) {
        if (p!= nil && p.PageIndex < p.PageCount) {
            return @YES;
        }
        return @NO;
    }];
}

- (void)initSubscribe {
    
    @weakify(self);
    [[_fetchProductCommand.executionSignals switchToLatest] subscribeNext:^(ResponseData *response) {
        @strongify(self);
        if (!response.success) {
            [self.errors sendNext:response.error];
        }
        else {
            self.items = [ProductListModel objectArrayWithKeyValuesArray:response.data];
            self.page = response.page;
        }
    }];
    
    [[_fetchMoreProductCommand.executionSignals switchToLatest] subscribeNext:^(ResponseData *response) {
        @strongify(self);
        if (!response.success) {
            [self.errors sendNext:response.error];
        }
        else {
            NSMutableArray *arr = [NSMutableArray arrayWithArray:self.items];
            [arr addObjectsFromArray:[ProductListModel objectArrayWithKeyValuesArray:response.data]];
            self.items = arr;
            self.page = response.page;
        }
    }];
    
    [[RACSignal merge:@[_fetchProductCommand.errors, self.fetchMoreProductCommand.errors]] subscribe:self.errors];
}

#pragma mark - method

- (ProductListCellViewModel *)itemViewModelForIndex:(NSInteger)index {
    
    return [[ProductListCellViewModel alloc]initWithModel:[_items objectAtIndex:index]];
}

@end
