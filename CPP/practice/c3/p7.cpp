#include<iostream>

const double GAL_TO_LIT=3.875;
const double KM_TO_MIL=62.14;

int main()
{
	using namespace std;

	double consume_eu, consume_us;
	cout<<"Enter the consume in L/100km: ";
	cin>>consume_eu;
	consume_us=GAL_TO_LIT*KM_TO_MIL/consume_eu;
	cout<<"Consume in mpg: "<<consume_us<<" mpg\n";

	return 0;
}
