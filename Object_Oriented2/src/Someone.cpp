#include"Someone.h"
#include<iostream>
#include<string>
#include<math.h>

using namespace std;


Person::Person(int a)
{
    age=a;
    cout<<"Construct object person with arguments"<<endl;
    cout<<"age: "<<age<<endl;
};

Person::~Person()
{
    cout<<"Object is destroyed"<<endl;
};

Man::Man()
{
    cout<<"Initiation"<<endl;
}

Man::Man(int age)
{
    m_age=age;
    cout<<"Aguments get"<<endl;
}

// Man::Man(const Man &m)
// {
//     m_age=m.m_age;
//     cout<<"Have created copy"<<endl;
// }

Man::~Man()
{
    cout<<"Destroy object"<<endl;
}

int Man::get_age()
{
    return m_age;
}

Female::Female(string a,int b,bool c):name(a),age(b),sex(c)
{
    
}





Person::Person()
{
    cout<<"Has none arguments"<<endl;
};


Person::Person(const Person &p)
{
    age=p.age;
    cout<<"Copy"<<endl;
    cout<<"age: "<<age<<endl;
}




