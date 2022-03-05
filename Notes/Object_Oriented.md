## 面向对象

### 内存分区模型

- 代码区：二进制代码，存放CPU执行的机器指令，操作系统管理

  - 共享的，频繁执行的程序，只需要存一份
  - 只读的

- 全局区：全局变量、静态变量、常量

  - 全局变量由操作系统回收
  - 静态变量：延长变量的生命周期，到程序结束时候才释放，用statistic修饰的全局变量只能在本文件中访问
  - 常量：const修饰全局常量，字符串常量

- 栈区：编译器自动分配释放，存放函数的参数值，局部变量

- 堆区：程序运行之后开辟的，由程序员分配和释放，如果程序员不释放，程序结束时候由操作系统回收，C++中主要利用new在堆区开辟内存

  - ```c++
    int *p=new int(10)  //这个10是值，就是在堆区开辟一个内存空间，值是10，内存地址返回给p
    ```

### 引用

```c++
int a=10;
int &b=a;
b=20;
cout<<a<<endl;

==
20
==
```

- 引用必须初始化
- 引用一旦初始化后就不能改变

##### 引用做函数参数

>这个曾经考试用太多，就不说了

##### 引用作函数的返回值

- **不要返回局部变量的引用**
- 函数的调用可以作为左值存在

##### 引用的本质

引用本质在C++中就是一个**指针常量**

常量引用的也有

```c++
//这里相当于 int temp=10; const int&ref=temp;
const int &a=10;
```

### 函数高级

##### 函数默认值

```c++
int  add(int a,int b=20,int c=20) //b有默认参数,c必须要有
{
	return a+b+c;
}

add(10)

==
10+20+20
==

add(10,30)
===
10+30+20
===
```

- **可以覆盖**
- 而且默认参数都要放后面，**只要中间有一个有，后面全都要有默认参数**

- 声明中默认参数，函数实现就不能有默认参数，**两个只能有一个写默认参数**

##### 函数占位符

> ​	只填数据类型

```c++
void func(int a,int) //这个后面就是占位，可以传入一个整型,而且必须要传
```

##### 函数重载

> 函数名相同，提高复用性

- 同一个作用域下
- 函数名称相同
- 函数**参数类型不同，或者个数不同（默认参数不在），或者顺序不同**（可以用占位符）

```c++
void print_test()
{
	cout<<"first"<<endl;
}


void print_test(int)
{
	cout<<"Overloading"<<endl;
}
```

- 关键就是看编译器能不能判断重载哪个，防止二义性

### 类和对象



#### 封装

> - 将属性和行为作为一个整体，表现生活中的事物
>
> - 将属性和行为加以权限控制

##### 三种权限

- public:成员类内可以访问，类外也能发
- protected:类内可以访问，类外不能访问，继承的可以访问
- private:类内可以访问，类外不能访问，继承不能访问

#### 对象的初始化和清理

> ​	构造函数用来初始化对象，析构函数用来清理工作

#### 构造函数：类名(){}

- 没有返回值，也不写void
- 函数名称与类名相同
- 构造函数**可以有参数**，因此可以重载
- 程序在构造对象时候会自动调用构造，无须手动调用，而且只会调用一次
- 构造函数可以分为有参数和无参数，以及普通构造和拷贝构造

```c++
//拷贝构造函数
Person(const Person &p){}; //要用const，而且要传引用型
//括号法调用构造函数
Person p1;
Person p2(10);
Person p3(p2);

//显示法调用构造函数
Person p1;		//无参数的
Person p2=Person(10); //有参数的
Person p3=Person(p2);	//拷贝构造
Person(10); //匿名对象，当前行执行结束了，就会回收对象；不要利用拷贝构造函数，初始化匿名对象

//隐式转换法
Person p4=10;
Person p5=p4;
```

##### 拷贝构造函数

> - 使用一个已经创建完毕的对象来初始化一个新对象
> - **值传递的方式**给函数参数传值，把对象传给函数时候，函数不是引用，就是直接拷贝构造了，拷贝构造函数也会调用
> - 以值方式返回局部对象，**这个未必，编译器不同，不一定**

##### 构造函数的调用规则

- 默认构造函数
- 默认析构函数
- 默认拷贝构造函数

> - **如果用户定义了有参构造函数，C++就不在提供无参构造函数，但是会提供拷贝构造函数**
> - **如果用户定义了拷贝构造函数，C++就不再提供其他构造函数**

##### 深拷贝和浅拷贝

- 浅拷贝：简单的赋值拷贝操作（**当你没写拷贝构造函数时候，你强行调用，就会进行拷贝构造，基本属性给拷贝下来**）
- 深拷贝：在堆区重新申请空间，进行拷贝操作，这个建议看视频理解，他会新开堆，全部拷贝

##### 初始化列表

> ​	我们不是经常有对象的属性吗，可以用语法把他初始化
>
> 构造函数():属性1（值1），属性2（值2）...{}

```c++
Female::Female(string a,int b,bool c):name(a),age(b),sex(c)
{
    
}

```

- **构造时候先构造类对象再构造自身，析构时候相反**

##### 静态成员变量和静态成员函数

> ​	当将类的某个数据成员声明为static时，**该静态数据成员只能被定义一次**，**而且要被同类的所有对象共享**。各个对象都拥有类中每一个普通数据成员的副本，但静态数据成员只有一个实例存在，与定义了多少类的对象无关。静态方法就是与该类相关的，是类的一种行为，而不是与该类的实例对象相关。
>
>  **静态成员变量不能在类中初始化，即类内声明，类外初始化，而且必须要，这个初始化还不是具体实例的，是类的**
>
> 静态成员变量不可在类体内进行赋值，因为它是被所有该类的对象所共享的，如果你在一个对象里给它赋值，其他对象里的该成员变量也会发生变化，因此，为了避免混乱，**所以不可在类体内对静态成员变量进行赋值。**



- **静态成员对象属于类的，可以通过类名访问**

```c++
class Cash_Box
{
	public:
		static int cash;
};

int Cash_Box::cash=10;


int main()
{
	Cash_Box n1;
	n1.cash=20;

	Cash_Box n2;
	cout<<n2.cash<<endl;
	cout<<Cash_Box::cash<<endl; //直接用类访问
	return 0;
}
```

- 静态成员函数所有对象共享一个函数，**静态成员函数只能访问静态成员变量（可以用来初始化）**
- 成员变量和成员函数是分开存储的

#### 多类继承

```c++
class Son:public Base,public Base2
{
	public:
		int m_C;
		int m_D;

		Son()
		{
			m_C=300;
			m_D-=400;
		}
};

```

#### 菱形继承

![image-20220304162452150](D:\CPPLearning\Notes\pictures\image-20220304162452150.png)

> ​	有可能出现两个父类有同名属性，我们继承下来分不清，要使用虚继承来解决这个问题

在继承之前加上*virtual*说明这个是一个虚继承，后面还是还要加权限的比如public

```c++
class Camelidae:virtual public Animal{};
class Alpaca:public Sheep,public Camelidae{};
al.Sheep::m_Age=18;
al.Camelidae::m_Age=28;
cout<<al.Sheep::m_Age<<endl;
cout<<al.Camelidae::m_Age<<endl;
cout<<al.m_Age<<endl;
```

上面这个就是虚继承，而被继承的Animal的类叫做*虚基类*，这样继承下来Alpaca类就没有多个age属性了，相当于只有一个，都是28。虚继承相当于继承了一个指针，这个指针指向都是一个值。

#### 析构函数：~类名(){}

- 没有返回值，也不写void
- 析构函数**不可以有参数**，所以不能重载
- 程序在对象销毁前会自动析构，无需手动调用，只会调用一次

#### 多态

顾名思义多态多态就是有多种形态，多态又分为*静态多态*和*动态多态*

- 静态多态：函数重载和运算符重载都是静态多态，复用函数名
- 动态多态：派生类和虚拟函数实现运行时多态

C++中我们通常提的都是动态多态

静态多态和动态多态的区别：

- 静态多态的函数地址早绑定-编译阶段确定函数地址
- 动态多态的函数地址晚绑定-运行阶段确定函数地址

```c++
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
```

**这里走的是Animal的speak函数**，编译器很聪明，让动物说话

**实现动态多态方法：**

- 有继承关系
- 子类要**重写**父类的虚函数（函数名称和参数一模一样）
- 父类一定要用虚函数

**动态多态使用**

- 父类的指针或者引用，执行子类对象

> ​	所谓虚函数，其实是创建了一个虚函数指针，指向一个虚函数表，这个表里面有一个虚函数对象，子类继承后也会继承指针，继承虚函数表，若子类重写这个函数，虚函数指针就会指向子类的函数，所以当函数调用是**引用**或者指针时候，指向的是子类的函数