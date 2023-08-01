/*
auto为C++11支持的方法，故编译时的指令为g++ -std=c++11 mixtypes.cpp
*/
#include<iostream>

struct years
{
	int year;
};

int main()
{
	using namespace std;

	years s1, s2, s3;
	s1.year = 1998;
	years* pa = &s2;
	pa->year = 1999;
	years tri[3];
	tri[0].year = 2003;
	cout << "tri->year = " << tri->year << endl;
	const years* arp[3] = {&s1, &s2, &s3};
	cout << "arp[1]->year = " << arp[1]->year << endl;
	const years** ppa = arp;		//指向指针的指针
	auto ppb = arp;		//arp是数组的首地址，而数组元素为指针
	cout << "(*ppa)->year = " << (*ppa)->year << endl;
	cout << "(*(ppb + 1))->year = " << (*(ppb + 1))->year << endl;

	return 0;
}
