#include<iostream>
#include<string>
#include<cstring>

int main()
{
	using namespace std;

	char c1[20];
	char c2[20] = "jaguar";
	string s1;
	string s2 = "panther";

	s1 = s2;
	strcpy(c1, c2);
	s1 += " paste";
	strcat(c1, " juice");

	int len1 = s1.size();
	int len2 = strlen(c1);

	cout << "The string " << s1 << " contains " << len1 << " characters.\n";
	cout << "The string " << c1 << " contains " << len2 << " characters.\n";

	return 0;
}
