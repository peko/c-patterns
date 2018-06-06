Mojoc strictly follow this code style to ensure the C code readability and uniformity. This code style is important to understand how Mojoc works.

* [Basic Naming](#basic-naming)
* [Variable Naming](#variable-naming)
* [Abbreviated Naming](#abbreviated-naming)
* [Goto Label Naming](#goto-label-naming)
* [Enum Naming](#enum-naming)
* [Function Naming](#function-naming)
* [Struct Naming](#struct-naming)
* [Macro Naming](#macro-naming)
* [Others Naming](#others-naming)
* [Code Format](#code-format)
* [Code Comment](#code-comment)
* [Other Rules](#other-rules)

## Basic Naming
The basic use CamelCased, this is BigCamelCased, this is smallCamelCased.

## Variable Naming
* The common variable use smallCamelCased.
    ```c
    int               keyLength;
    int               valueTypeSize;
    SkeletonBone*     bone;
    SkeletonBoneData* boneData;
    Drawable*         drawable;
    ```

* The const use smallCamelCased.
  ```c
  static const char*  ids[AudioId_Length];
  static const char*  saveDataFileName = "MojocSaveDataFile";
  static const int    bezierSize       = (BEZIER_SEGMENTS + 1) * 2 - 1;
  static const float  subDivPre        = subDivStep3           / pre5;
  ```

* The bool variable (including member variables) begin with prefix is, then the whole is smallCamelCased.
  ```c
  SLboolean isLoopEnabled;
  bool      isFound;
  bool      isRemoved;
  particle->isActive
  ```

* The singleton variable begin with prefix 'A', then the whole is BigCamelCased.
  ```c
  extern struct AComponent   AComponent  [1];
  extern struct ADrawable    ADrawable   [1];
  extern struct AParticle    AParticle   [1];
  extern struct AApplication AApplication[1];
  ```

* The variable of function get out argument begin with prefix out, then the whole is smallCamelCased.
  ```c
  void (*OnSaveData)(void**   outSaveData,   int*         outLength);
  void (*Inverse)   (Matrix4* matrix4,       Matrix4*     outInverse);
  void Init         (int      valueTypeSize, ArrayIntMap* outArrayIntMap);
  ```

* The variable of function pointer use BigCamelCased.
  ```c
  typedef struct
  {
      void (*OnPause)  ();
      void (*OnResume) ();
      void (*OnDestroy)();
  }
  ApplicationCallbacks;


  typedef float (*TweenActionValueOnGet)(void* target);
  typedef void  (*TweenActionValueOnSet)(void* target, float value);


  typedef struct
  {
      TweenActionValueOnGet OnGet;
      TweenActionValueOnSet OnSet;
  }
  TweenActionValueGetSet;
  ```

## Abbreviated Naming
* The abbreviated words use upper case words or lower case words.
  ```c
  typedef struct
  {
  }
  RGB;


  RGB rgb;
  RGB myRGB;
  RGB rgbDatas[10];
  RGB myRGBData;
  

  void SetRGB    (RGB* rgb);
  void RGBSet    (RGB* rgb);
  void SetRGBData(RGB* rgb);

  ```

## Goto Label Naming
* The goto label tag use BigCamelCased. But goto label address use common variable rule. 

  ```c
  goto ParseArrayEnd;
  goto ParseObjectEnd;
  goto UseVBO;
  goto UseVAO;
  goto *coroutine->step;
  ```

## Enum Naming
* The enum use BigCamelCased, and must has prefix separated by '_'.
  ```c
  enum
  {
      HeroState_Stand,
      HeroState_DieOver,
  };


  enum
  {
      CollisionGroup_HeroBody   = 1,
      CollisionGroup_HeroAttack = 1 << 1,
  };


  typedef enum
  {
      FontTextAlignment_HorizontalLeft,
      FontTextAlignment_HorizontalRight,
      FontTextAlignment_VerticalTop,
      FontTextAlignment_VerticalBottom,
  }
  FontTextAlignment;


  typedef enum
  {
      InputTouchType_Up     = 1,
      InputTouchType_Down   = 2,
      InputTouchType_Move   = 3,
      InputTouchType_Cancel = 4,
  }
  InputTouchType;
  ```

* The typedef enum use BigCamelCased.

## Function Naming
* The global function and global inline function use BigCamelCased, and must has prefix separated by '_'.
  ```c
  extern void         Application_Main        ();
  static inline void  AApplication_AppendChild(Component* child);
  static inline float AGLTool_ToGLWidth       (float      screenWidth);
  static inline float AMath_Random            ();
  ```

* The local function and local inline function use BigCamelCased;
  ```c
  static void         LoadingRun    (Coroutine* coroutine);
  static inline float GetWorldScaleY(Drawable*  drawable);
  ```

* The typedef function use BigCamelCased, and must has prefix.
  ```c
  typedef float (*TweenActionValueOnGet)(void*      target);
  typedef void  (*TweenActionValueOnSet)(void*      target, float value);
  typedef void  (*CoroutineRun)         (Coroutine* coroutine);
  ```

* The function operation may not succeed and return the flag result, begin with prefix “Try”, then the whole is BigCamelCased.
  ```c
  void* (*TryPut)   (ArrayIntMap* arrayIntMap, intptr_t key, void* valuePtr);
  bool  (*TryRemove)(ArrayIntMap* arrayIntMap, intptr_t key);
  ```

* The function return boolean which is operation purpose, begin with prefix “Is” or “Test” or “Check” , then the whole is BigCamelCased.
  ```c
  bool (*IsContains)         (ArrayIntSet*  arrayIntSet, intptr_t element);
  bool (*TestPolygonPoint)   (Array(float)* vertexArr,   float x, float y);
  bool ADrawable_CheckVisible(Drawable*     drawable);
  ```

* The function named Release, means free struct members memory space.

* The function begin with prefix “Create”, means return malloc pointer, so for delete first Release and then free it.
  ```c
  ArrayList* (*Create)            (int elementTypeSize);
  ArrayList* (*CreateWithSize)    (int elementTypeSize, int size);
  ArrayList* (*CreateWithCapacity)(int elementTypeSize, int capacity);
  ```

* The function begin with prefix “Init”, means pointer members memory on stack, so just Release for delete.
  ```c
  void (*Init)            (int elementTypeSize, ArrayList*               outArrayList);
  void (*InitWithSize)    (int elementTypeSize, int size,     ArrayList* outArrayList);
  void (*InitWithCapacity)(int elementTypeSize, int capacity, ArrayList* outArrayList);
  ```

## Struct Naming
* The struct (union) or typedef struct (union), use BigCamelCased.

## Macro Naming
* The head define macro, use upper case words separated by '_' and end with 'H'.
  ```c
  #ifndef STYLE_GUIDE_H
  #define STYLE_GUIDE_H
  ```

* The macro without parameters, use upper case words case words separated by '_'.
  ```c
  #define MATH_PI  3.141592653589793
  #define MATH_2PI 6.283185307179586
  #define MATH_PI2 1.570796326794897
  ```

* The macro with parameters, use BigCamelCased, and must has prefix separated by '_'.
  ```c
  #define AMath_Min(x, y) 
  #define AStruct_GetParent2(memberPtr, structType)
  #define ACoroutine_YieldFrames(waitFrames)
  ```

## Others Naming
* The file name, folder name, resource name, use BigCamelCased.


## Code Format
* Use space key indent, not tab key.
* Use 4 spaces indent;
* The pointer '*' on type name side.
  ```c
  int*  p1;
  int** p2 = &p1;
  void* Function(char* str);
  ```
* The '{' and '}' vertical alignment.
  ```c
  {
    // vertical alignment
  }
  ```

* The '(' and ')' if need to wrap, then vertical alignment.
  ```c
  AMath_Max
  (
      animationData->duration,
      AArray_Get
      (
          deformTimeline->frameArr,
          deformTimeline->frameArr->length - 1,
          float
      )
  );

  static void ReadAnimationDeform
  (
      SkeletonData*          skeletonData,
      JsonObject*            jsonDeform,
      SkeletonAnimationData* animationData,
      ArrayList*             skeletonTimelineArr
  )
  {
     // ...
  }
  ```

* The if, while, for, switch, must have "{}", and one space with "()".
* The operator at least one space on both sides.
  ```c
  vertexX + (y - vertexY) / (preY - vertexY) * (vertexData[preIndex] - vertexX)
  ```

* The case 4 spaces indent, and break 4 spaces indent in switch case.
  ```c
  switch (111)
  {
      case 0:
          break;

      case 1:
      {
          break;
      }
  }
  ```

* Empty two lines around functions.
  ```c
  static int a = 100;


  static void Function1()
  {
  }


  static inline void Function2()
  {
  }

 
  struct A
  {
  }
  ```

* Empty two lines between different contents.
  ```c
  #include "AAA.h"
  #include "BBB.h"


  typedef float (*Function1)(void* target);
  typedef float (*Function2)();


  struct A
  {
  }


  struct B
  {
  }


  extern struct B B[1];


  ```

* Use split line to separate different logical related contents.
  ```c
  // this is split line
  //--------------------


  void Function1();


  //--------------------
  

  void Function2();


  void Function3()
  {
      int a;

      //---------------- 

      int b;
  }
  ```

* The goto label indent with the current line.
  ```c
  static void Function()
  { 
       goto Label:

       Label1:
       int a;

       Label2:
       int b;

       Label3:
       int c;
  }
  ``` 

* The conditional compile, indent with the current line.
  ```c
  typedef struct
  {
       Sprite       sprite[1];
       PhysicsBody* body;
       Enemy*       enemy;
       ArrowHitType hitType;

       #ifdef APP_DEBUG
       Drawable     debugDrawable[1];
       #endif
  }
  Arrow;

  void Function()
  {
      int a;
        
      #ifdef APP_DEBUG
      int b;
      #endif
  }


  #ifdef APP_DEBUG
  Drawable debugDrawable[1];
  #endif
  ```


* In code block try vertical alignment.
  ```c
  Look all examples above, will feel it.
  ```

## Code Comment
* Outside function body use “/***/”.
  ```c
  /**
   * Comment struct
   */  
  struct A
  {   
      /**
       * Comment property
       */ 
      int a;
      
      /**
       * Comment function
       */
      void (*Function)();
  }
  ```

* In function body use “//”.
* Comment code block or multiline code.
  ```c
  /*
  --------------------------------------------
    This is means comment few blocks of code
  --------------------------------------------
  */
  ```

## Other Rules
* The parameter macro, only when inline function not working to use.
  * such as shortcut parameters of function call.
  * such as macro specific functionality.
  * such as generic parameter.
  * such as varargs.

* Do not use 0 or 1 as boolean value, non-boolean value use conditional expressions in conditional judgments.
* The const variable can not modified. Do not define const in .h file and modified in .c file.

#
> _**Follow the style, Get the power !**_
