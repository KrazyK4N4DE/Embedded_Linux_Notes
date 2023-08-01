#include<iostream>
#include<array>

int main()
{
	using namespace std;

	array<double, 10> donation;
	cout << "Enter double digits:\n";
	double input, aver = 0, sum = 0;
	int count = 0;

	while((count < 10) && (cin >> input))
	{
		donation[count] = input;
		sum += donation[count];
		count++;
	}

	if(count == 0)
		cout << "No digits....\n";
	else
	{
		aver = sum / count;
		int bigger = 0;
		for(int i = 0; i < count; i++)
		{
			if(donation[i] > aver)
				bigger++;
		}
		cout << "Average: " << aver << endl
		<< bigger << " digits bigger than average value\n";
	}

	return 0;
}
