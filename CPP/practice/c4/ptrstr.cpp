#include<iostream>
#include<cstring>

int main()
{
	using namespace std;

	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;
	cout << endl << animal << " and " << bird << endl;
	/*
	cin >> ps;
	cout << ps << endl;		//has not been assigned
	*/
	cout << "Enter a kind of animal: ";
	/*
	cin >> bird;
	cout << bird << endl;		//not allowed
	*/
	cin >> animal;
	cout << animal << endl;

	ps = animal;
	cout << ps << endl;

	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;

	cout << "\nAfter using strcpy\n";
	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl << endl;
	delete [] ps;

	return 0;
}
