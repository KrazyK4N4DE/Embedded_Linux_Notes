#include<iostream>
#include<array>

const int SIZE = 3;

int main()
{
	using namespace std;

	array<float, SIZE> grade;
	float total = 0;

	for(int i = 0; i < SIZE; i++)
	{
		cout << "\nGrade in round " << i + 1 << " (in seconds): ";
		cin >> grade[i];
		total += grade[i];
	}
	cout << "\nAverage grade: " << total/SIZE << "seconds" << endl;

	return 0;
}
