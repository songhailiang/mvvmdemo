//
//  ProductListCell.h
//  MVVM
//
//  Created by develop on 15/9/18.
//  Copyright (c) 2015年 songhailiang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ProductListCellViewModel.h"

@interface ProductListCell : UITableViewCell

@property (nonatomic, strong) ProductListCellViewModel *viewModel;

@end
