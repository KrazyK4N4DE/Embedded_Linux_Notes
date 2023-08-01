/*
* ·´×ª×Ö·û´®
*/
#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s)
{
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
				char tmp = s[left];
				s[left] = s[right];
				s[right] = tmp;
				left++;
				right--;
		}
}

int main()
{

}