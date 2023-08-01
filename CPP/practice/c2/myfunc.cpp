#include<iostream>
void simon(int);

int main()
{
	using namespace std;
	
	int n;
	cout << "Enter the number: ";
	cin >> n;
	simon(n);
	cout << "Done!" << endl;

	return 0;
}

void simon(int n)
{
	using namespace std;
	
	cout << "Simon says touch your toes " << n << " times." << endl; 
}
