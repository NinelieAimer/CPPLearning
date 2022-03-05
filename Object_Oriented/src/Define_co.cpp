#include "Define_co.h"

#include<string>
#include<iostream>
#include<math.h>

using namespace std;
bool isSame(Cube &c1,Cube &c2)
{
    if(c1.getH()==c2.getH()&&c1.getL()==c2.getL()&&c1.getW()==c2.getW())
    {
        return true;
    }
    else
    {
        return false;
    };
};

void isInCircle(Circle &c,Point &p)
{
    int c_x=c.getCenter().getX();
    int c_y=c.getCenter().getY();

    int p_x=p.getX();
    int p_y=p.getY();

    int dis=(c_x-p_x)*(c_x-p_x)+(c_y-p_y)*(c_y-p_y);

    if(dis==c.getR()*c.getR())
    {
        cout<<"On circle"<<endl;
    }
    else if(dis>c.getR()*c.getR()){
        cout<<"Out of the circle"<<endl;
    }
    else
    {
        cout<<"In the Circle"<<endl;
    }
};