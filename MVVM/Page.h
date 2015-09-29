//
//  Page.h
//  MVVM
//
//  Created by develop on 15/9/28.
//  Copyright © 2015年 songhailiang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  分页实体
 */
@interface Page : NSObject

/**
 *  总页数
 */
@property (nonatomic, assign) NSInteger PageCount;

/**
 *  当前页码
 */
@property (nonatomic, assign) NSInteger PageIndex;

/**
 *  总记录数
 */
@property (nonatomic, assign) NSInteger RecordCount;

@end
