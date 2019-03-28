//
//  HQDefine.h
//  
//
//  Created by haoqi on 2018/9/6.
//
#import "UIColor+HQHex.h"

#ifndef HQDefine_h
#define HQDefine_h

// UI相关
//1. 各种高度宽度
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上
#define kHQSCREEN_WIDTH ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]? \
    [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale: \
    [UIScreen mainScreen].bounds.size.width)

#define kHQSCREENH_HEIGHT ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?\
    [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale: \
    [UIScreen mainScreen].bounds.size.height)

#define kHQSCREEN_SIZE ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]? \ CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale): \ [UIScreen mainScreen].bounds.size)
#else
#define kHQSCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define kHQSCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height
#define kHQSCREEN_SIZE [UIScreen mainScreen].bounds.size
#endif


#define kStatusLineHeight ([[UIApplication sharedApplication] statusBarFrame].size.height)
#define kNavBarHeight 44
#define kTabBarHeight (iPhone6P?(51):(49))
#define kIphoneXSafeBottomHeight 37

// 比例缩放尺寸
#define AutoSize(size) size*kScreenWidth/375

#define HQCellIdentifier(className)  NSStringFromClass([className class])

//2. 颜色 HQRGBColor  HQRGBAColor:alpha:  HQClearColor
#define HQRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define HQRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define HQClearColor [UIColor clearColor]

#define HQColorWithHexString(str) [UIColor colorWithHexString:str]


// 内存相关
#define WEAK_SELF __weak typeof(self)weakSelf = self
#define STRONG_SELF __strong typeof(weakSelf)self = weakSelf \
if (self == nil) return;


//调试相关
#ifdef DEBUG
#   define HQLog(fmt, ...) NSLog((@"\n\n 类:  <%s>  \n 第%d行，打印内容为: \n" fmt @"\n"), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define HQLog(...)
#endif


//设备版本
#define iPhone4S ([UIScreen mainScreen].bounds.size.height == 480 ? YES : NO)
#define iPhone5S ([UIScreen mainScreen].bounds.size.height == 568 ? YES : NO)
#define iPhone6 ([UIScreen mainScreen].bounds.size.height == 667 ? YES : NO)
#define iPhone6P ([UIScreen mainScreen].bounds.size.height ==736 ? YES : NO)
#define iPhoneX ([UIScreen mainScreen].bounds.size.height == 812 ? YES : NO)

#define iPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


//空 nil null NSNull
// 比例缩放尺寸
#define C_S_MACRO(macro) [NSString stringWithFormat:@"%s",macro]

#define STRINGNOTNIL(str) (str != nil && ![str isEqualToString:@""])

#define STRINGISNIL(str) (str == nil || [str isEqualToString:@""])

#define ARRAYNOTNIL(array) (array != nil && array.count > 0 )

#define ARRAYISNIL(array) (array == nil || array.count == 0 )

#define DICTSETSTRING(dict,str,key) if(STRINGNOTNIL(str)){[dict setObject:str forKey:key];}


##pragma mark - 单例
#define SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
shared##classname = [[classname alloc] init];\
}); \
return shared##classname;\
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
} \



#endif /* HQDefine_h */
