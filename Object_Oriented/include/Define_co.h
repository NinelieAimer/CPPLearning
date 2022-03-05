#include<string>
#include<iostream>

using namespace std;

#define PI 3.14
class Person
{
    private:
        string m_Name;
        int m_Age;
        string m_Sex;
    
    public:

        void show_info()
        {
            cout<<"name: "<<m_Name<<endl;
            cout<<"age: "<<m_Age<<endl;
            cout<<"sex: "<<m_Sex<<endl;
        }
        void set_name(string name)
        {
            m_Name=name;
        }
        void set_Age(int age){
            m_Age=age;
        }
        void set_Sex(string sex)
        {
            m_Sex=sex;
        }
};
class Point
{
    private:
        int m_X;
        int m_Y;
    public:
        int getX()
        {
            return m_X;
        }

        void setX(int x){
            m_X=x;
        }

        int getY(){
            return m_Y;
        }

        void setY(int y){
            m_Y=y;
        }

};
class Circle
{
	//access permission
	private:
        int m_R;
        Point center;

    public:
        void setR(int R)
        {
            m_R=R;
        }
        int getR()
        {
            return m_R;
        }
        
        void set_center(Point c)
        {
            center=c;
        }

        Point getCenter()
        {
            return center;
        }
};

class Student
{
	public:
		string name;
		string s_number;

		void show_name_number()
		{
			cout<<"name: "<<name<<endl;
			cout<<"student_number: "<<s_number<<endl;
		}
};

class Cube
{
    private:
        double m_L;
        double m_W;
        double m_H;
    
    public:

        //Get L and set L
        double getL()
        {
            return m_L;
        }
        double set_L(double L)
        {
            m_L=L;
        }

        //Get W and set W
        double getW()
        {
            return m_W;
        }
        double set_W(double W)
        {
            m_W=W;
        }

        //Get H and set H
        double getH()
        {
            return m_H;
        }
        double set_H(double H)
        {
            m_H=H;
        }

        double calculateS()
        {
            return 2*m_L*m_W+2*m_H*m_L+2*m_W*m_H;
        }

        double calculateV()
        {
            return m_L*m_H*m_W;
        }
};

bool isSame(Cube &c1,Cube &c2);
void isInCircle(Circle &c,Point &p);

