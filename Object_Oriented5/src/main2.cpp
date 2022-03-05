#include <string>
#include<iostream>

using namespace std;


class Animal
{
    public:
        virtual void speak()
        {
            cout<<"Animal is speaking"<<endl;
        }


};

class Cat:public Animal
{
    public:
        void speak() //虚函数
        {
            cout<<"Cat is speaking"<<endl;
        }
};
class Dog:public Animal
{
    public:
        void speak()
        {
          cout<<"Dog is speaking"<<endl;  
        };
};
//地址早绑定，在编译阶段就确定了函数的地址
//如果想让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段绑定
void doSpeak(Animal &animal)
{
    animal.speak();
};

void test01()
{
    Cat cat;
    Dog dog;
    doSpeak(cat);
    doSpeak(dog);
}


int main()
{
    test01();
    return 0;
}