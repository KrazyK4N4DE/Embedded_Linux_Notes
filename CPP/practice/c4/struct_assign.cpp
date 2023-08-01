#include<iostream>

struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;

	inflatable guest = 
{
	"Glorious Gloria",
	1.88,
	29.99
};
	inflatable pal;

	cout << "guset: " << guest.name << " for $" << guest.price << "\n";
	pal = guest;
	cout << "pal: " << pal.name << " for $" << pal.price << "\n";

	return 0;
}
