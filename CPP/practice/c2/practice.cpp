#include<iostream>
using namespace std;

void mice();
void run();
void months(int);
double degree(double);
double convert(double);
void show(int, int);

int main()
{
	/*p1*/
	cout<<"wei"<<endl;
	cout<<"China"<<endl;
	
	/*p2*/
	double dis;
	cout<<"Enter the distance(in long): ";
	cin>>dis;
	cout<<dis<<"(long) = "<<dis*220<<"(yard)."<<endl;

	/*p3*/
	mice();
	mice();
	run();
	run();

	/*p4*/
	int age;
	cout<<"Enter ur age: ";
	cin>>age;
	months(age);

	/*p5*/
	cout<<"Please enter a Celsius value: ";
	double c_deg, f_deg;
	cin>>c_deg;
	f_deg = degree(c_deg);
	cout<<c_deg<<" degrees Celsius is "<<f_deg<<" degrees Fahrenheit."<<endl;

	/*p6*/
	double ly, as;
	cout<<"Enter the number of light years: ";
	cin>>ly;
	as = convert(ly);
	cout<<ly<<" light years = "<<as<<" astronomical units."<<endl;

	/*p7*/
	int hour, minute;
	cout<<"Enter the number of hours: ";
	cin>>hour;
	cout<<"Enter the number of minutes: ";
	cin>>minute;
	show(hour,minute);

	return 0;
}

void mice()
{
	cout<<"Three blind mice"<<endl;
}
void run()
{
	cout<<"See how they run"<<endl;
}

void months(int n)
{
	cout<<"You are "<<n<<" years old, equals to "<<n*12<<" months"<<endl;
}

double degree(double c)
{
	return (c*1.8+32.0);
}

double convert(double c)
{
	return 63240*c;
}

void show(int hour, int minute)
{
	cout<<"Time: "<<hour<<":"<<minute<<endl;
}
