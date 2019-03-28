//
//  UIColor+HQHex.h
//  HQImageBrowserDemo
//
//  Created by 郝琦 on 2018/9/7.
//  Copyright © 2018年 haoqi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (HQHex)
// 透明度固定为1，以0x开头的十六进制转换成的颜色
+ (UIColor *)colorWithHex:(long)hexColor;
// 0x开头的十六进制转换成的颜色,透明度可调整
+ (UIColor *)colorWithHex:(long)hexColor alpha:(float)opacity;
// 颜色转换三：iOS中十六进制的颜色（以#开头）转换为UIColor
+ (UIColor *) colorWithHexString: (NSString *)color;
@end
