//
//  ProductListCellViewModel.m
//  MVVM
//
//  Created by develop on 15/9/18.
//  Copyright (c) 2015年 songhailiang. All rights reserved.
//

#import "ProductListCellViewModel.h"

@interface ProductListCellViewModel ()

@property (nonatomic, strong) ProductListModel *model;

@end

@implementation ProductListCellViewModel

#pragma mark - init

- (instancetype)initWithModel:(ProductListModel *)model {
    self = [super init];
    if (self) {
        self.model = model;
    }
    return self;
}

#pragma mark - public method

- (NSString *)ProductName {
    return _model.ProductName;
}

- (NSString *)ProductBank {
    return _model.ProductBank;
}

- (NSString *)ProductProfit {
    return [NSString stringWithFormat:@"%.2f%%",_model.ProductProfit];
}

- (NSString *)ProductTerm {
    return [NSString stringWithFormat:@"%d天", _model.ProductTerm];
}

- (NSString *)ProductAmt {
    return [NSString stringWithFormat:@"%.0f万起", _model.ProductAmt/10000];
}

- (NSString *)ProductClassCn {
    return _model.ProductClassCn;
}

- (NSString *)SaleStatusCn {
    return _model.SaleStatusCn;
}

@end
