ScenteeSDK for iOS
==================

This SDK is for iOS application to emit a fragrant spray via Scentee device.

HOW TO USE IT
-------------

### Register Applications To Scentee Developer Site ###

You need to register your Scentee developer account at http://developer.scentee.com/.  
When logging in, you can get *App Key* as long as you register your application.

### Register App Key To Xcode###

Add program to `Target` > `Info` > `Custom iOS Target Properties` as below.

+   Key :
    `ScenteeAppKey`

+   Type :
    `String`

+   Value :
    App Key (ex)  `000000100:ABCDEFGHIJKLMNOPQRSTUVWXYZ`

### Import ScenteeSDK.framework ###

Choose the `ScenteeSDK.framework` you downloaded from  
`Target` > `General` > `Linked frameworks and Libraries` > `+` > `Add Other...` 

`ScenteeSDK.framework` is a directory, not a file.

###How To Activation Of ScenteeSDK  ###

**AppDelegate.h**

    #import <ScenteeSDK/ScenteeSDK.h>

**AppDelegate.m**

    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        ...
        [[ScenteeSDK scentee] initialize];
        ...
        return YES;
    }

### How To Emit Fragrant Spray ###

    @try {
        [[ScenteeSDK scentee] puffAndFlashLedWithRed:127 Green:127 Blue:127 Special:0 Time:1000];
    }
    @catch (ScenteeException *exception) {
        NSLog(@"Failure！");
    }

Reference
---------

    [[ScenteeSDK scentee] initialize];

Activate ScenteeSDK 

-----

    bool result = [[ScenteeSDK checkDeviceState];

It judges the condition of connection of Scentee device

+ `result` :
   + `true` :
     Connected correct
   + `false` :
     Connected wrong

-----

    int state = [[ScenteeSDK checkDetailedDeviceState]];

It judges the condition of Scentee device in detail。

+ `state` :
   + `0` :
     OK
   + `1` :
     NO DEVICE
   + `2` :
     COMMUNICATION ERROR
   + `3` :
     NETWORK ERROR
   + `17` :
     NO TANK
   + `18` :
     ERROR TANK
   + `111` :
     MIC INITIALIZATION ERROR

-----

    [[ScenteeSDK scentee] puffAndFlashLedWithRed:(Byte)red Green:(Byte)green Blue:(Byte)blue Special:(Byte)special Time:(short int)time];

Emitting

+   `red` :
    LED Color of Scentee device (RGB  Red 0〜255)

+   `blue` :
    LED Color of Scentee device  (RGB Blue 0〜255)

+   `green` :
    LED Color of Scentee device  (RGB Green 0〜255)

+   `special` :
   + `0` :
     Lighting Scentee device For The LED Color by RGB
   + `1` :
     Lighting Scentee device For Rainbow

+   `time` :
  Term of emitting (millisecond)

-----

    [[ScenteeSDK scentee] flashLedWithRed:(Byte)red Green:(Byte)green Blue:(Byte)blue Special:(Byte)special Time:(short int)time];

Only Lighting Without Emitting

+   `red` :
    LED Color of Scentee device (RGB  Red 0〜255)

+   `blue` :
    LED Color of Scentee device  (RGB Blue 0〜255)

+   `green` :
    LED Color of Scentee device  (RGB Green 0〜255)

+   `special` :
   + `0` :
     Lighting Scentee device For The LED Color by RGB
   + `1` :
     Lighting Scentee device For Rainbow

+   `time` :
    Term of emitting (millisecond)

-----

    TankId* tankId = [[ScenteeSDK scentee] getTankId];

Get The Information of Scentee cartridge ID

-------------------

Copyright &copy; 2013 Scentee. All rights reserved.
