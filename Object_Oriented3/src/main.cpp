#include <iostream>
#include<string>

using namespace std;

class Cash_Box
{
	public:
		static int cash;
		static void func(){
			cash++;
			cout<<"static function"<<endl;
		}
};

int Cash_Box::cash=10;

class Person
{
	public:
		Person operator+(Person &p);

		Person(int age)
		{
			this->m_age=age;
		}

		void showClassName()
		{
			cout<<"This is  Person class"<<endl;
			
		}

		void showPersonage()
		{
			cout<<m_age<<endl;
		}


		Person &addAge(Person &p)
		{
			this->m_age+=p.m_age;
			return *this; //返回对象才能加
		};

		void showPerson() const
		{
			this->m_age=100;
		}
		mutable int m_age;
};

class Building
{
	friend class GoodFemale;
	friend void goodGay(Building *build);
	
	public:
		string m_SittingRoom;

		Building()
		{
			m_SittingRoom="sitting";
			m_BedRoom="Bd";
		}

	private:
		string m_BedRoom;
};

void goodGay(Building *build)
{
	cout<<build->m_BedRoom<<endl;
}

class GoodFemale
{
	public:
		Building *build;

		GoodFemale()
		{
			build=new Building;
		}
		void visit()
		{
			cout<<build->m_SittingRoom<<endl;
			cout<<build->m_BedRoom<<endl;
		};
};

Person Person::operator+(Person &p)
{
	Person temp(12);
	temp.m_age=this->m_age+p.m_age;
	return temp;
}

ostream & operator<<(ostream &cout,Person &p)
{
	cout<<p.m_age;
	cout<<p.m_age;
	return cout;
}




int main()
{
	// Cash_Box n1;
	// n1.cash=20;

	// Cash_Box n2;
	// cout<<n2.cash<<endl;
	// cout<<Cash_Box::cash<<endl;

	// Cash_Box n2;
	// n2.func();
	// Cash_Box::func();
	// cout<<n2.cash<<endl;

	// Person p1(3);
	// cout<<p1.m_age<<endl;
	// Person p2(12);
	// p2.addAge(p1).addAge(p1);
	// cout<<p2.m_age<<endl;

	// GoodFemale p1;
	// p1.visit();

	Person p4(1);
	Person p5(2);
	Person p6=p4+p5;
	cout<<p6.m_age<<endl;
	cout<<p6;


	return 0;
}