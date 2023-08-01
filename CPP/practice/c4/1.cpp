#include<iostream>

int main()
{
	using namespace std;
	const int size = 20;

	char first[size], last[size];
	char grade;
	int age;

	cout << "first name: ";
	cin.getline(first, size);
	cout << "last name: ";
	cin.getline(last, size);
	cout << "letter grade you deserve: ";
	cin >> grade;
	cout << "age: ";
	cin >> age;

	cout << "Name: " << last << ", " << first << endl 
	<< "grade: " << char(grade + 1) << "\nage: " << age << endl;
	//grade+1后需要类型转换为char，不然输出为数字

	return 0;
}
