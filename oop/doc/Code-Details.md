* [Mojoc Toolkit Module](#mojoc-toolkit-module)
* [Mojoc ThirdParty Module](#mojoc-thirdparty-module)
* [Mojoc Graphics Module](#mojoc-graphics-module)
* [Mojoc Physics Module](#mojoc-physics-module)
* [Mojoc Audio Module](#mojoc-audio-module)
* [Mojoc Extension Module](#mojoc-extension-module)
* [Mojoc Application Module](#mojoc-application-module)


## Mojoc Toolkit Module

[Toolkit](https://github.com/scottcgi/Mojoc/tree/master/Engine/Toolkit) module is development kit of C language. Provide basic data structure and algorithm support.

* [Utils](https://github.com/scottcgi/Mojoc/tree/master/Engine/Toolkit/Utils) provide basic data storage tools and algorithm structure.
    * [Array.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/Array.h), implement generic array.
    * [ArrayIntMap.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/ArrayIntMap.h), implement the int key dictionary.
    * [ArrayIntSet.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/ArrayIntSet.h), implement the int key set.
    * [ArrayList.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/ArrayList.h), implement generic array list.
    * [ArrayQueue.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/ArrayQueue.h), implement the generic queue by ArrayList.
    * [ArrayStrMap.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/ArrayStrMap.h), implement the string key dictionary.
    * [BufferReader.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/BufferReader.h), implement the byte stream read.
    * [Coroutine.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/Coroutine.h), implement the simple and effective coroutine for C.
    * [FileTool.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/FileTool.h), impement the cross-platfom file read and write.
    * [Json.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/Json.h), implement the independent json parser.
    * [Tween.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/Tween.h), implement the independent tween animation.
    * [TweenTool.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/TweenTool.h), implement the interface of tween animation chain calls.
    
* [Platform](https://github.com/scottcgi/Mojoc/tree/master/Engine/Toolkit/Platform) provide platform related tools implementation.
    * [File.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Platform/File.h), interface of native file operation.
        * [Android File.c](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Platform/Android/File.c), implement android file operation.
        * [IOS File.c](https://github.com/scottcgi/Mojoc/tree/master/Engine/Toolkit/Platform/IOS), implement ios file operation.

* [Math](https://github.com/scottcgi/Mojoc/tree/master/Engine/Toolkit/Math) provide mathematical related algorithm implementation.
    * [Math.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Math/Math.h), implement math formulas and define math constants.
    * [Matrix.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Math/Matrix.h), implement all the matrix operations .
    * [TweenEase.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Math/TweenEase.h), implement the standard tween algorithm.
    * [Vector.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Math/Vector.h), implement vector operations.

* [Head](https://github.com/scottcgi/Mojoc/tree/master/Engine/Toolkit/Head) provide simple structure definition and operation.


## Mojoc ThirdParty Module

[ThirdParty](https://github.com/scottcgi/Mojoc/tree/master/Engine/ThirdParty) module is prebuild third party libraries, that can direct called by Mojoc engine. So the third party need to provide different prebuild lib files for native platforms of Mojoc support. Currently only contains PNG library.


## Mojoc Graphics Module

[Graphics](https://github.com/scottcgi/Mojoc/tree/master/Engine/Graphics) module is draw layer implemented by OpenGLES3, and provide drawing tools and implementations.

* [Draw](https://github.com/scottcgi/Mojoc/tree/master/Engine/Graphics/Draw) provide basic abstract drawing layer.
    * [Drawable.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/Draw/Drawable.h), implement transform about translate, rotate, scale. Construct a recursive tree drawing structure. Also can extend own drawing object on Drawable.
    * [Quad.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/Draw/Quad.h), implement a abstract rect in texture.
    
* [OpenGL](https://github.com/scottcgi/Mojoc/tree/master/Engine/Graphics/OpenGL) provide OpenGLES rendering functions.
    * [Platform](https://github.com/scottcgi/Mojoc/tree/master/Engine/Graphics/OpenGL/Platform) provide OpenGLES cross-platform config.
        * [EGLTool.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/Platform/EGLTool.h), implement EGL configs and functions.
    * [Shader](https://github.com/scottcgi/Mojoc/tree/master/Engine/Graphics/OpenGL/Shader) provide build-in shader implementation.
    * [Camera.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/Camera.h), implement camera settings.
    * [GLInfo.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/GLInfo.h), record OpenGLES some attributes.
    * [GLPrimitive.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/GLPrimitive.h), implement OpenGLES draw primitives.
    * [GLTool.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/GLTool.h), implement coordinate system conversion between OpenGLES and screen.
    * [Mesh.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/Mesh.h) and [SubMesh.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/SubMesh.h), implement OpenGLES Mesh system. 
    * [Sprite.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/Sprite.h), implement usual Sprite drawing.
    * [Texture.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/Texture.h), implement usual Texture. 

* [Tween](https://github.com/scottcgi/Mojoc/tree/master/Engine/Graphics/Tween) provide tween animation implementation.
    * [TweenDrawable.c](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/Tween/TweenDrawable.c), implement interface ATweenActionValueGetSetImpl in [TweenTool.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Utils/TweenTool.h).

* [Utils](https://github.com/scottcgi/Mojoc/tree/master/Engine/Graphics/Utils) provide drawing support tools.
    * [Image.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/Utils/Image.h), implement texture data read from png file.

## Mojoc Physics Module
[Physics](https://github.com/scottcgi/Mojoc/tree/master/Engine/Physics) module provide simple physical simulation.

* [PhysicsBody.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Physics/PhysicsBody.h), implement abstract physical object.
* [PhysicsCollision.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Physics/PhysicsCollision.h), implement collision detection between various shapes.
* [PhysicsWorld.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Physics/PhysicsWorld.h), implement all PhysicsBody management.

## Mojoc Audio Module
This module provide cross-platform audio implementation.

* [Audio.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Audio/Platform/Audio.h), interface of auido API.
    * [Android Audio.c](https://github.com/scottcgi/Mojoc/blob/master/Engine/Audio/Platform/Android/Audio.c), implement android audio interface by OpenSLES.
    * [IOS Audio.m](https://github.com/scottcgi/Mojoc/blob/master/Engine/Audio/Platform/IOS/Audio.m), implement ios audio interface by OpenAL.


## Mojoc Extension Module
[Extension](https://github.com/scottcgi/Mojoc/tree/master/Engine/Extension) module is editor tools and related implementation.

* [Particle](https://github.com/scottcgi/Mojoc/tree/master/Engine/Extension/Particle) provide [2D-Particle-Editor](https://github.com/libgdx/libgdx/wiki/2D-Particle-Editor) implementation.
* [Spine](https://github.com/scottcgi/Mojoc/tree/master/Engine/Extension/Spine) provide 2D skeleton animation [Spine-Editor](http://esotericsoftware.com/) runtime implementation.

* [DrawAtlas.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Extension/DrawAtlas.h), implement draw texture atlas.
* [Font.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Extension/Font.h), implement texture font by Mesh and TextureAtlas.
* [TextureAtlas.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Extension/TextureAtlas.h), implement [Texture-packer-Editor](https://github.com/libgdx/libgdx/wiki/Texture-packer) which integrated into spine-editor.

## Mojoc Application Module
[Application](https://github.com/scottcgi/Mojoc/tree/master/Engine/Application) module is platform glue layer. Provide app lifecycle, input event, native glue, component architecture and so on.

* [JniTool.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Application/Platform/Android/JniTool.h), implement android jni tools, make Mojoc call java code easier.
* [NativeGlue.c](https://github.com/scottcgi/Mojoc/blob/master/Engine/Application/Platform/Android/NativeGlue.c), implement android native glue layer, not use the android_native_app_glue.h code, just directly build on ANativeActivity in NDK. But in IOS, the glue layer write in platform code swift, see [GameViewController.swift](https://github.com/scottcgi/Mojoc/blob/master/Samples/SuperLittleRed/IOS/GameViewController.swift) and [AppDelegate.swift](https://github.com/scottcgi/Mojoc/blob/master/Samples/SuperLittleRed/IOS/AppDelegate.swift).
* [Application.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Application/Application.h), implement app main entry, lifecycle event and callback interface.
* [Component.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Application/Component.h), implement Component-Based, State-Machine, Message-Driven.
* [Input.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Application/Input.h), implement cross-platform input event.
* [Scheduler.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Application/Scheduler.h), implement timer callback function.