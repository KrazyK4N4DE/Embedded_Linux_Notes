#include<iostream>
#include<cstring>	//for strlen()

int main()
{
	using namespace std;

	const int SIZE=15;
	char name1[SIZE];
	char name2[SIZE]="C++owboy";
	cout <<"Howdy! I'm "<<name2<<"! What's your name?\n";
	cin>>name1;
	cout<<"Well, "<<name1<<", your name has ";
	cout<<strlen(name1)<<" letters and is stored\n";
	cout<<"in an array of "<<sizeof(name1)<<" bytes.\n";
	cout<<"Your initial is "<<name1[0]<<".\n";
	name2[3]='\0';
	cout<<"Here are the first 3 characters of my name: ";
	cout<<name2<<endl;

	return 0;
}
