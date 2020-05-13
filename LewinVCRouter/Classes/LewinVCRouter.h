//
//  LewinVCRouter.h
//  Pods
//
//  Created by lewin on 2020/5/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum
{
    LVRouterURLType_invalid,                     // 无效
    LVRouterURLType_push,                        // 在当前目录push               : ./
    LVRouterURLType_pushAfterPop,                // 在上一个目录push             : ../
    LVRouterURLType_pushAfterGotoRoot,           // 在根目录根push               : /
    // LVRouterURLType_push,                     // 在当前目录push               : 空
}LVRouterType;

typedef UIViewController *  (^LVRouterBlock)();

@interface LewinVCRouter : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, copy, readonly) NSString *currentPath;
@property (nonatomic, strong) UIViewController *rootViewController;     // windows.rootViewController

- (void)mapKey:(NSString *)key toControllerClassName:(NSString *)className;
- (void)mapKey:(NSString *)key toControllerInstance:(UIViewController *)viewController;
- (void)mapKey:(NSString *)key toBlock:(LVRouterBlock)block;

// 当取出ViewController的时候, 如果有单例[ViewController sharedInstance], 默认返回单例, 如果没有, 返回[[ViewController alloc] init].
- (id)viewControllerForKey:(NSString *)key;

- (void)openURLString:(NSString *)URLString;

#pragma mark - override
/// 默认有个返回实际显示navigationController的方法. 你也可以在重写这个方法,以返回你期望的 navigationController
+ (UINavigationController *)currentNavigationController;

- (void)showViewController:(NSString *)viewControllerName param:(NSDictionary *)param;

- (void)showViewController:(NSString *)viewControllerName param:(NSDictionary *)param animation:(BOOL)animation;


@end

#pragma mark - UIViewController (LewinVCRouter)

@interface UIViewController (LewinVCRouter)

@property (nonatomic, copy, readonly) NSString *uxy_URLPath;

@end
