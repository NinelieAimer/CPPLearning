#include <iostream>
using namespace std;


class Base
{
	public:

		Base()
		{
			m_A=100;
		}
		int m_A;
		static int m_B;
};
int Base::m_B=12;

class Son:public Base
{
	public:
		int m_A;
		static int m_B;
		Son()
		{
			m_A=200;
		}

};

int Son::m_B=400;


class BasePage
{
	public:
		void header()
		{
			cout<<"Public test"<<endl;
		}
		void foorer()
		{
			cout<<"Footer"<<endl;
		}

		void left()
		{
			cout<<"Java test"<<endl;
		}

		void right()
		{
			cout<<"righter"<<endl;
		}
};

class Java:public BasePage
{
	public:
		void content()
		{
			cout<<"Java"<<endl;
		}
};

void test01()
{
	cout<<"Java vedio"<<endl;
	Java ja;
	ja.header();
	ja.left();
	ja.right();
	ja.foorer();
	ja.foorer();
};

int main()
{
	// test01();
	// system("pause");

	Son s;
	// cout<<s.m_A<<endl;
	// cout<<s.Base::m_A<<endl; //访问父类
	// cout<<s.m_B<<endl;
	// cout<<s.Base::m_B<<endl;
	cout<<Base::m_B<<endl;
	cout<<Son::m_B<<endl;
	cout<<Son::Base::m_B<<endl;
	return 0;
}