//
//  LEWINVCROUTERViewController.m
//  LewinVCRouter
//
//  Created by lizhiyu on 05/12/2020.
//  Copyright (c) 2020 lizhiyu. All rights reserved.
//

#import "LEWINVCROUTERViewController.h"
#import <LewinVCRouter/LewinVCRouter.h>

@interface LEWINVCROUTERViewController ()

@end

@implementation LEWINVCROUTERViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor=[UIColor whiteColor];
	// Do any additional setup after loading the view, typically from a nib.
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeSystem];
    btn.frame = CGRectMake(100, 150, 100, 45);
    [btn setTitle:@"跳转" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(toTest) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
}

-(void)toTest {
    [[LewinVCRouter sharedInstance] showViewController:@"Test1VC" param:nil];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
