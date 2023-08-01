#include <iostream>
#include <string>

using namespace std;

int main()
{
        string one("Lottery Winner!");
        cout << one << endl;

        string two(20, '$');
        cout << two << endl;

        string three(one);
        cout << three << endl;

        one += "Oops";
        cout << one << endl;

        two = "Sorry! That was ";
        three[0] = 'P';

        string four;
        four = two + three;
        cout << four << endl;

        char alls[] = "All's well that ends well";
        string five(alls, 20);
        cout << five << "!\n";

        string six(alls + 6, alls + 10);  // 把alls的第6个字符到第10个字符赋值给six，即"well"
        cout << six << ", ";

        string seven(&five[6], &five[10]);  // 参数是起止位置，所以要传递地址
        cout << seven << "...\n";

        string eight(four, 7, 16);
        cout << eight << endl;

        return 0;
}