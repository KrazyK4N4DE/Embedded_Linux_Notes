#include<iostream>

int main()
{
	using namespace std;

	char ch='M';
	int i=ch;
	cout<<"The ASCII code for "<<ch<<" is "<<i<<endl<<endl;
	
	cout<<"Add 1 to the character code: "<<endl;
	ch+=1;
	i=ch;
	cout<<"The ASCII code for "<<ch<<" is "<<i<<endl;

	cout<<"Using cout.put():";
	cout.put(ch);
	cout.put('!');
	cout<<endl<<"Done.\n";

	return 0;
}
