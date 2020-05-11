#include <stdio.h>
#include <string.h>
#include "animal.h"

/* 設置動物的昵稱 */
void Animal_setName(Animal* t, const char* name)
{
    // 這裡假定name小於128個字符，為簡化示例代碼，不做保護（產品代碼中不要這樣寫）
    strcpy(t->name, name);
}
/* 設置動物的年齡 */
void Animal_setAge(Animal* t, int age)
{
    t->age = age;
}
/* 動物和我們打招呼 */
void Animal_sayHello(Animal* t)
{
    printf("Hello! 我是%s，今年%d歲了！\n", t->name, t->age);
}
/* 初始化動物的昵稱和年齡 */
void Animal_init(Animal* t, const char* name, int age)
{
    t->setName(t, name);
    t->setAge(t, age);
}

ABS_CTOR(Animal)
FUNCTION_SETTING(setName, Animal_setName);
FUNCTION_SETTING(setAge, Animal_setAge);
FUNCTION_SETTING(sayHello, Animal_sayHello);
FUNCTION_SETTING(init, Animal_init);
END_ABS_CTOR

/* 魚的吃行為 */
void Fish_eat(Animal* t)
{
    printf("魚吃水草！\n");
}
/* 魚的呼吸行為 */
void Fish_breathe(Animal* t)
{
    printf("魚用鰓呼吸！\n");
}
/* 魚的移動行為 */
void Fish_move(IMoveable* t)
{
    printf("魚在水裡游！\n");
}
/* 初始化魚的昵稱和年齡 */
void Fish_init(Fish* t, const char* name, int age)
{
    Animal* animal = SUPER_PTR(t, Animal);
    animal->setName(animal, name);
    animal->setAge(animal, age);
}

CTOR(Fish)
SUPER_CTOR(Animal);
FUNCTION_SETTING(Animal.eat, Fish_eat);
FUNCTION_SETTING(Animal.breathe, Fish_breathe);
FUNCTION_SETTING(IMoveable.move, Fish_move);
FUNCTION_SETTING(init, Fish_init);
END_CTOR

/* 狗的吃行為 */
void Dog_eat(Animal* t)
{
    printf("狗吃骨頭！\n");
}
/* 狗的呼吸行為 */
void Dog_breathe(Animal* t)
{
    printf("狗用肺呼吸！\n");
}
/* 狗的移動行為 */
void Dog_move(IMoveable* t)
{
    printf("狗在地上跑！\n");
}
/* 初始化狗的昵稱和年齡 */
void Dog_init(Dog* t, const char* name, int age)
{
    Animal* animal = SUPER_PTR(t, Animal);
    animal->setName(animal, name);
    animal->setAge(animal, age);
}

CTOR(Dog)
SUPER_CTOR(Animal);
FUNCTION_SETTING(Animal.eat, Dog_eat);
FUNCTION_SETTING(Animal.breathe, Dog_breathe);
FUNCTION_SETTING(IMoveable.move, Dog_move);
FUNCTION_SETTING(init, Dog_init);
END_CTOR

void Car_move(IMoveable* t)
{
    printf("汽車在開動！\n");
}

CTOR(Car)
FUNCTION_SETTING(IMoveable.move, Car_move);
END_CTOR
