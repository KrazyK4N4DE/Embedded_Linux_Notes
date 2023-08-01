#include<iostream>
#include<ctime>

int main()
{
	using namespace std;

	cout << "Enter the delay time: ";
	float sec;
	cin >> sec;
	clock_t delay = sec * CLOCKS_PER_SEC;
	cout << "starting\a\n";
	clock_t start = clock();
	while(clock() - start < delay);
	cout << "Done\a\n";

	return 0;
}
