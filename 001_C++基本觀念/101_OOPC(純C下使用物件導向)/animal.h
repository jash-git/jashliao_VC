#ifndef ANIMAL_H_INCLUDED_
#define ANIMAL_H_INCLUDED_

#include "lw_oopc.h"

INTERFACE(IMoveable)
{
    void (*move)(IMoveable* t);     // Move行為
};

ABS_CLASS(Animal)
{
    char name[128];     // 動物的昵稱(假設小於128個字符)
    int age;            // 動物的年齡

    void (*setName)(Animal* t, const char* name);   // 設置動物的昵稱
    void (*setAge)(Animal* t, int age);             // 設置動物的年齡 
    void (*sayHello)(Animal* t);                    // 動物打招呼
    void (*eat)(Animal* t);                         // 動物都會吃（抽象方法，由子類實現）
    void (*breathe)(Animal* t);                     // 動物都會呼吸（抽象方法，由子類實現）
    void (*init)(Animal* t, const char* name, int age); // 初始化昵稱和年齡
};

CLASS(Fish)
{
    EXTENDS(Animal);        // 繼承Animal抽象類
    IMPLEMENTS(IMoveable);  // 實現IMoveable接口

    void (*init)(Fish* t, const char* name, int age);
};

CLASS(Dog)
{
    EXTENDS(Animal);        // 繼承Animal抽象類
    IMPLEMENTS(IMoveable);  // 實現IMoveable接口


    void(*init)(Dog* t, const char* name, int age);
};

CLASS(Car)
{
    IMPLEMENTS(IMoveable);  // 實現IMoveable接口（車子不是動物，但可以Move）
};

#endif