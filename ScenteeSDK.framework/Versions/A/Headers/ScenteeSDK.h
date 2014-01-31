//
//  Scentee.h
//
//  Created by chatperf on 2013/08/15.
//  Copyright (c) 2013 chatperf. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AdSupport/AdSupport.h>
#import "TankId.h"

@interface ScenteeSDK : NSObject <UIAlertViewDelegate>

+ (ScenteeSDK *)scentee;
- (void)initialize;
- (bool)checkDeviceState;
- (unsigned int)checkDetailedDeviceState;
- (void)puffAndFlashLedWithRed:(Byte)red Green:(Byte)green Blue:(Byte)blue Special:(Byte)special Time:(short int)time;
- (void)flashLedWithRed:(Byte)red Green:(Byte)green Blue:(Byte)blue Special:(Byte)special Time:(short int)time;
- (TankId*)getTankId;
- (unsigned int)echo:(unsigned int)number;

@end