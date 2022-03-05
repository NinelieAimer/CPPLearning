#include <iostream>
#include<string>
#include <math.h>
#include "Define_co.h"


using namespace std;



int main()
{


	// Student Jerry;
	// Jerry.name="NinelieAimer";
	// Jerry.s_number="2201702841";
	// Jerry.show_name_number();

	// Person li;
	// li.set_name("NinelieAimer");
	// li.show_info();
	
	// Cube c1;
	// c1.set_L(10);
	// c1.set_H(10);
	// c1.set_W(10);

	// Cube c2;
	// c1.set_L(12);
	// c1.set_H(10);
	// c1.set_W(10);
	// cout<<isSame(c1,c2)<<endl;
	// cout<<c1.calculateS()<<" "<<c1.calculateV()<<endl;

	Circle c;

	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.set_center(center);

	Point p;
	p.setX(10);
	p.setY(20);

	isInCircle(c,p);
	return 0;
}