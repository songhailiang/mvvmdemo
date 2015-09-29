//
//  ProductListModel.h
//  MVVM
//
//  Created by develop on 15/9/25.
//  Copyright © 2015年 songhailiang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  产品列表实体
 */
@interface ProductListModel : NSObject

/**
 *  产品代码
 */
@property (strong,nonatomic) NSString *ProductNo;
/**
 *  产品名称
 */
@property (strong,nonatomic) NSString *ProductName;
/**
 *  预期收益率
 */
@property (assign,nonatomic) float ProductProfit;
/**
 *  期限
 */
@property (assign,nonatomic) int ProductTerm;
/**
 *  起购金额
 */
@property (assign,nonatomic) float ProductAmt;
/**
 *  收益类型
 */
@property (strong,nonatomic) NSString *ProductClassCn;
/**
 *  发行银行
 */
@property (strong,nonatomic) NSString *ProductBank;
/**
 *  发行地区
 */
@property (strong,nonatomic) NSString *ProductArea;
/**
 *  币种
 */
@property (strong,nonatomic) NSString *ProductCurrency;
/**
 *  销售状态
 */
@property (assign,nonatomic) int SaleStatus;
/**
 *  销售状态名称
 */
@property (strong,nonatomic) NSString *SaleStatusCn;
/**
 *  起售时间
 */
@property (assign,nonatomic) double SaleStartDateLong;
/**
 *  终售时间
 */
@property (assign,nonatomic) double SaleEndDateLong;

@end
