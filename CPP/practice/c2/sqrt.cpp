#include<iostream>
#include<cmath>

int main()
{
	using namespace std;

	double area;
	cout << "Enter the floor area, in square feet, of yourhome: ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "The value of the side: "
	<< side << endl;
	
	return 0;
}
