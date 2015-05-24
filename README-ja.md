ScenteeSDK for iOS
===============

iOS アプリから Scentee デバイスを通して香りを噴霧させるための SDK です。
 
使い方
----------

### 開発者サイトへのアプリ登録 ###

[Scentee 開発者サイト](http://developer.scentee.com/) から開発者登録を行います。  
ログイン後、アプリ登録を行い **App Key** を取得します。

### Xcode に App Key を登録 ###

`Target` > `Info` > `Custom iOS Target Properties` に次の1行を追加します。

+   Key :
    `ScenteeAppKey`
 
+   Type :
    `String`

+   Value :
    App Key (例)  `000000100:ABCDEFGHIJKLMNOPQRSTUVWXYZ`

### Xcode で他に必要な設定 ###

`Target` > `Linking` > `Other Linker Flags` > `+` で次の値を追加します。

    -ObjC

`Target` > `Architectures` > `Build Active Architecture Only` > `Debug` で次の値を追加します。

    No

`Target` > `Architectures` > `Valid Architectures` で arm64 を削除します。

    - armv7 armv7s arm64
    + armv7 armv7s

### ScenteeSDK.framework をインポート ###

`Target` > `General` > `Linked frameworks and Libraries` > `+` > `Add Other...` から  
ダウンロードした `ScenteeSDK.framework` を選択します。  

`ScenteeSDK.framework` はファイルではなくディレクトリです。
 
### ScenteeSDK 初期化処理を記述 ###

**AppDelegate.h**

    #import <ScenteeSDK/ScenteeSDK.h>
    #import <ScenteeSDK/ScenteeException.h>

**AppDelegate.m**

    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        ...
        [[ScenteeSDK scentee] initialize];
        ...
        return YES;
    }

### 噴霧させる処理を記述 ###

    @try {
        [[ScenteeSDK scentee] puffAndFlashLedWithRed:127 Green:127 Blue:127 Special:0 Time:1000 Misc:@"Test"];
    }
    @catch (ScenteeException *exception) {
        NSLog(@"噴霧失敗！");
    }
 
リファレンス
-------------------

    [[ScenteeSDK scentee] initialize];

ScenteeSDK の初期化を行います。

-----

    bool result = [[ScenteeSDK scentee] checkDeviceState];

Scentee デバイスが正しく接続されているかどうかを取得します。

+ `result` :
   + `true` :
     正しく接続されている
   + `false` :
     正しく接続されていない

-----

    int state = [[ScenteeSDK scentee] checkDetailedDeviceState]];

Scentee デバイスの詳細な接続状態を取得します。

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

    [[ScenteeSDK scentee] puffAndFlashLedWithRed:(Byte)red Green:(Byte)green Blue:(Byte)blue Special:(Byte)special Time:(short int)time Misc:(NSString*)misc];

噴霧を行います。

+   `red` :
    Scentee デバイスの LED 色 (RGB 値の Red 0〜255)

+   `blue` :
    Scentee デバイスの LED 色 (RGB 値の Blue 0〜255)

+   `green` :
    Scentee デバイスの LED 色 (RGB 値の Green 0〜255)
 
+   `special` :
   + `0` :
     Scentee デバイスの LED 色を RGB 値で指定した色で点灯させる
   + `1` :
     Scentee デバイスの LED 色を虹色に点灯させる

+   `time` :
    噴霧させる時間 (ミリ秒)

+   `misc` :
    追加情報 (40文字)

-----

    [[ScenteeSDK scentee] flashLedWithRed:(Byte)red Green:(Byte)green Blue:(Byte)blue Special:(Byte)special Time:(short int)time];

噴霧を行わず、LED の点灯のみ行います。

+   `red` :
    Scentee デバイスの LED 色 (RGB 値の Red 0〜255)

+   `blue` :
    Scentee デバイスの LED 色 (RGB 値の Blue 0〜255)

+   `green` :
    Scentee デバイスの LED 色 (RGB 値の Green 0〜255)
 
+   `special` :
   + `0` :
     Scentee デバイスの LED 色を RGB 値で指定した色で点灯させる
   + `1` :
     Scentee デバイスの LED 色を虹色に点灯させる

+   `time` :
    点灯させる時間 (ミリ秒)

-----

    TankId* tankId = [[ScenteeSDK scentee] getTankId];

Scentee  デバイスのカートリッジ情報を取得します。

-----

    (unsigned int)echo:(unsigned int)number;

Scentee デバイスへ echo 要求を行います。

-----

    (DEPRECATED) [[ScenteeSDK scentee] puffAndFlashLedWithRed:(Byte)red Green:(Byte)green Blue:(Byte)blue Special:(Byte)special Time:(short int)time];

噴霧を行います。(Deprecated. Call puffAndFlashLedWithRed:Green:Blue:Special:Time:Misc: instead)

+   `red` :
    Scentee デバイスの LED 色 (RGB 値の Red 0〜255)

+   `blue` :
    Scentee デバイスの LED 色 (RGB 値の Blue 0〜255)

+   `green` :
    Scentee デバイスの LED 色 (RGB 値の Green 0〜255)
 
+   `special` :
   + `0` :
     Scentee デバイスの LED 色を RGB 値で指定した色で点灯させる
   + `1` :
     Scentee デバイスの LED 色を虹色に点灯させる

+   `time` :
    噴霧させる時間 (ミリ秒)

-------------------

Copyright &copy; 2013 Scentee. All rights reserved.
