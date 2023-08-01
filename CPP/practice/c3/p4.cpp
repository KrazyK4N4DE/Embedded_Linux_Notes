#include<iostream>

const int Day=24;
const int Hrs=60;
const int Min=60;

int main()
{
	using namespace std;

	cout<<"sizeof(long) and sizeof(long long): \n"
	<<sizeof(long)<<endl<<sizeof(long long)<<endl;
	long long value;
	cout<<"Enter the number of seconds: ";
	cin>>value;
	int tmp_h, tmp_m;
	int days, hours, minutes, seconds;

	days=value/(Day*Hrs*Min);
	tmp_h=value%(Day*Hrs*Min);

	hours=tmp_h/(Hrs*Min);
	tmp_m=tmp_h%(Hrs*Min);

	minutes=tmp_m/Min;
	seconds=tmp_m%Min;

	cout<<value<<" seconds = "<<days<<" days, "
	<<hours<<" hours, "<<minutes<<" minutes, "
	<<seconds<<" seconds\n";

	return 0;
}
