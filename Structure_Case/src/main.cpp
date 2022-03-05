#include <iostream>
#include<string>

using namespace std;
//Student Structure
struct Student
{
	string name;
	float score;
};

struct Teacher
{
	string name;
	Student students[5];

};
//Initiate function
void Initiation(struct Teacher teachers[],int len)
{
	string nameSeed="ABCDE";
	for( int i=0;i<len;i++){
		//Teachers' name
		teachers[i].name="Teacher_";
		teachers[i].name+=nameSeed[i];

		//Students' Info
		for (int j=0;j<5;j++){
			teachers[i].students[j].name="Student_";
			teachers[i].students[j].name+=nameSeed[j];

			teachers[i].students[j].score=60;
			
		}
		

	}
};

//Print Info
void prinInfo(const struct Teacher teachers[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout<<"Teacher name:  "<<teachers[i].name<<endl;
		for (int j=0;j<5;j++){
			cout<<"Student name:  "<<teachers[i].students[j].name<<endl;
			cout<<"Score:  "<<teachers[i].students[j].score<<endl;
		}
	}
	
}

// int main(void)
// {
// 	//construct Teacher array
// 	Teacher teachers[3];
// 	int len=sizeof(teachers)/sizeof(teachers[0]);
// 	Initiation(teachers,len);
// 	prinInfo(teachers,len);
// 	return 0;
// }