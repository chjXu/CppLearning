#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person
{
    /* data */
    char mName[64];

    int mAge;
};

void PersonEat(struct Person *p)
{
    /* data */
    printf("%s 在吃饭 \n",p->mName);
}

void test01()
{
    struct Person p1;
    strcpy(p1.mName,"的吗西亚");
    PersonEat(&p1);
    
}


struct Dog
{
    /* data */
    char mName[64];

    int mAge;
};

void DogEat(struct Dog * dog)
{
    printf("%s 在吃狗粮 \n",dog->mName);
} 

void test02()
{
    struct Dog d;
    strcpy(d.mName,"旺财");
    DogEat(&d);
    
    struct Person p1;
    strcpy(p1.mName,"老王");
    DogEat(&p1);
}
//C语言的属性和行为是分开处理的

int main()
{
    //test01();
    test02();
    return 0;
}