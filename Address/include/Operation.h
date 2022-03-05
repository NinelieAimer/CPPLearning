#include<string>
#include<iostream>
#define MAX 1000;

using namespace std;


struct Person
{
    string m_name;
    int m_gender;
    int m_age;
    string m_tel;
    string m_addr;
};

struct ADB
{
    struct Person personArray[1000];
    int ADB_size;
};

void add_person(ADB *book);
void show_person(ADB *book);
int find_person(ADB *book,string name);
void del_person(ADB *book);
void edit_person(ADB *book);
void del_all(ADB *book);