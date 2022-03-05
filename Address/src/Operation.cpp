#include "Operation.h"
#include<string>
#include<iostream>

void show_person(ADB *book){
    if (book->ADB_size==0){
        cout<<"Not contact"<<endl;
        return;
    }
    else
    {
        int size=book->ADB_size;
        for(int i=0;i<size;i++)
        {
            cout<<"NAME: "<<book->personArray[i].m_name<<" \t"
            <<"Gender: "<<book->personArray[i].m_gender<<" \t"
            <<"Age: "<<book->personArray[i].m_age<<" \t"
            <<"Telephone: "<<book->personArray[i].m_tel<<" \t"
            <<"Address: "<<book->personArray[i].m_addr<<endl;
        }
    }
    
}
void add_person(ADB *book)
{
    if(book->ADB_size>1000){
        cout<<"There is no room"<<endl;
        return;
    }
    else
    {
        int size=book->ADB_size;

        //Enter name;
        cout<<"Please enter name: "<<"";
        string name;
        cin>>name;
        book->personArray[size].m_name=name;

        //gender
        cout<<"Please enter gender(1 means male,0 means female): "<<"";
        int gender;
        cin>>gender;
        book->personArray[size].m_gender=gender;

        //age
        cout<<"Please enter age: "<<"";
        int age;
        cin>>age;
        book->personArray[size].m_age=age;

        //tel
        cout<<"Please enter telephone number: "<<"";
        string tel;
        cin>>tel;
        book->personArray[size].m_tel=tel;

        //Address
        cout<<"Please enter Address: "<<"";
        string addr;
        cin>>addr;
        book->personArray[size].m_addr=addr;


        ++(book->ADB_size);
        
        cout<<"Successfully"<<endl;
        

    }
}

int find_person(ADB *book,string name)
{
    int size=book->ADB_size;
    if (size==0)
    {
        
        return -1;
    }

    for(int i=0;i<size;i++){
        if(name==book->personArray[i].m_name) return i;
    }

    return -1;
}

void del_person(ADB *book)
{
    string name;
    cout<<"Enter name: "<<"";
    cin>>name;
    int flag=find_person(book,name);
    if(flag==-1){
        cout<<"Not found"<<endl;
        return;
    }   
    else
    {
        int size=book->ADB_size;
        for(int i=flag;i<size-1;i++){
            book->personArray[i]=book->personArray[i+1];
        }
        book->ADB_size-=1;
        cout<<"Delete successfully"<<endl;
        return;
    }
}

void edit_person(ADB *book)
{
    cout<<"Which person do you want to edit,please enter his/her name: "<<"";
    string name;
    cin>>name;

    int flag=find_person(book,name);
    if(flag==-1)
    {
        cout<<"Not found"<<endl;
        return;
    }
    else
    {
        
        while (true)
        {
            cout<<"Which info do you want to change?(0.exit,1.sex,2.tel,3.address): "<<"";
            int option;
            cin>>option;
            switch (option)
            {
                case 0:
                {
                    return;
                }
                case 1:
                {
                    cout<<"Please enter gender(1 is male,0 is female): "<<"";
                    int gender;
                    cin>>gender;
                    book->personArray[flag].m_gender=gender;
                    break;
                }
                case 2:
                {
                    cout<<"Please enter telephone: "<<"";
                    string tele;
                    cin>>tele;
                    book->personArray[flag].m_tel=tele;
                    break;
                }
                case 3:
                {
                    cout<<"Please enter address: "<<"";
                    string address;
                    cin>>address;
                    book->personArray[flag].m_addr=address;
                    break;
                }
            }
        }
        
    }
}

void del_all(ADB *book)
{
    book->ADB_size=0;
    cout<<"Delete successfully"<<endl;
    return;
}