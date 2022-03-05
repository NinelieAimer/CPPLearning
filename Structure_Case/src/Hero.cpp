#include<string>
#include<iostream>

using namespace std;

struct Hero
{
    string name;
    int age;
    string gender;
};
void BubbleSort(struct Hero heros[],int len)
{
    bool flag;
    for(int i=0;i<len;i++){
        flag=false;
        for(int j=len-1;j>i;j--){
            if(heros[j].age<heros[j-1].age){
                flag=true;
                Hero temp;
                temp=heros[j];
                heros[j]=heros[j-1];
                heros[j-1]=temp;
            }
        }
        if(flag==false) return;

    }
};


void printInfo(const Hero heros[],int len)
{
    for(int i=0;i<len;i++){
        cout<<"name: "<<heros[i].name<<" "<<"age: "<<heros[i].age<<" gender: "<<heros[i].gender<<endl;
    }
}

int main(void)
{
    Hero heros[5]={

        {"A",23,"MALE"},
        {"B",24,"FEMALE"},
        {"C",22,"MALE"},
        {"D",24,"MALE"},
        {"E",25,"FEMALE"},
    };
    int len=sizeof(heros)/sizeof(heros[0]);
    BubbleSort(heros,len);
    printInfo(heros,len);
    return 0;
}
