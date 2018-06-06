Welcome to the Mojoc wiki, follow these steps for quick start.

## Step 1.
Get the source code, have three options.

* Git from [https://github.com/scottcgi/Mojoc.git](https://github.com/scottcgi/Mojoc.git)
* Download git master zip file [https://github.com/scottcgi/Mojoc/archive/master.zip](https://github.com/scottcgi/Mojoc/archive/master.zip)
* Download released version [https://github.com/scottcgi/Mojoc/releases](https://github.com/scottcgi/Mojoc/releases)

## Step 2.
Running samples, [Super Little Red](https://github.com/scottcgi/Mojoc/tree/master/Samples/SuperLittleRed), playing on phone.

  * [IOS Folder](https://github.com/scottcgi/Mojoc/tree/master/Samples/SuperLittleRed/IOS) is XCode project that all set up well, just open it with XCode. The only thing need to be set is switch Mojoc platform macro in [Platform.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Platform/Platform.h).
    ```c
    #define PLATFORM_TARGET PLATFORM_IOS
    ```

  * [Android Folder](https://github.com/scottcgi/Mojoc/tree/master/Samples/SuperLittleRed/Android) is AndroidStudio project that all set up well, just open it with AndroidStudio. The only thing need to be set is switch Mojoc platform macro in [Platform.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Platform/Platform.h).
    ```c
    #define PLATFORM_TARGET PLATFORM_ANDROID
    ```

  * [Code Folder](https://github.com/scottcgi/Mojoc/tree/master/Samples/SuperLittleRed/Code) is sample code shared between android and ios.

The AndroidStudio and XCode already config sample source code reference [engine code](https://github.com/scottcgi/Mojoc/tree/master/Engine). So any engine code changes will present in sample game.

## Step 3.
Understanding source code.

* [Code Style](https://github.com/scottcgi/Mojoc/wiki/Code-Style) is unified code writing style, all source code following.
* [OOC (Object Oriented C)](https://github.com/scottcgi/Mojoc/wiki/OOC-(Object-Oriented-C)) is the OOP(Object Oriented Programming) model of C language. Mojoc use extremely lightweight OOC model, very easy to understanding and using. Following this rules make C language can build complex project that organize and reuse large amounts of code.
* [Component Architecture](https://github.com/scottcgi/Mojoc/wiki/Component-Architecture) is code architecture support gameplay logic. Sample [code](https://github.com/scottcgi/Mojoc/tree/master/Samples/SuperLittleRed/Code) reflecting this function.

## Step 4.
[Code Details](https://github.com/scottcgi/Mojoc/wiki/Code-Details) are introduced the engine modules and functions of each code file. Through this can understand all the code of Mojoc.

## Step 5.
The sample [Super Little Red](https://github.com/scottcgi/Mojoc/tree/master/Samples/SuperLittleRed) give an aspect of using Mojoc. Modify and debug the source code helps understand all about Mojoc.