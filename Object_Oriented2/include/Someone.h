#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class Person
{
	public:
        int age;

		Person(int a);
        Person();
        Person(const Person &p);
        ~Person();
};

class Man
{
    private:
        int m_age;
    public:
        Man();
        Man(int age);
        // Man(const Man &m);
        ~Man();
        int get_age();
};

class Female
{
    public:
        string name;
        int age;
        bool sex;
        Female(string a,int b,bool c);
};



