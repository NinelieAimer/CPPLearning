#include <iostream>
#include<string>
#include "Show_Select.h"
#include "Operation.h"

using namespace std;


int main()
{
	int choice=0;
	ADB book;
	book.ADB_size=0;

	while(true)
	{
		show_menu();
		cin>>choice;
		switch (choice)
		{
			case 0: //Exit
				cout<<"Welcome to use next time"<<endl;
				system("pause");
				return 0;
			case 1:
				add_person(&book);
				break;
			case 2:
				show_person(&book);
				break;
			case 3:
				del_person(&book);
				break;
			case 4:
				{	
					string name;
					cout<<"Enter name:"<<"";
					cin>>name;
					int flag=find_person(&book,name);
					if(flag==-1){
						cout<<"Not found"<<endl;
						
					}
					else
					{
						cout<<"NAME: "<<book.personArray[flag].m_name<<" \t"
            			<<"Gender: "<<book.personArray[flag].m_gender<<" \t"
            			<<"Age: "<<book.personArray[flag].m_age<<" \t"
            			<<"Telephone: "<<book.personArray[flag].m_tel<<" \t"
            			<<"Address: "<<book.personArray[flag].m_addr<<endl;
					}
					break;
				}
			case 5:
				edit_person(&book);
				break;
			case 6:
				del_all(&book);
				break;
		};
	}
	system("pause");
	return 0;

}