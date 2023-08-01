#include <iostream>
#include <string>

using namespace std;

string v1(const string &s1, const string &s2);
string &v2(string &s1, const string &s2);
string &v3(const string &s1, const string &s2);

int main()
{
        string input;
        string copy;
        string result;

        cout << "Enter a string: ";
        getline(cin, input);
        copy = input;
        cout << "Your string as entered: " << input << endl;
        result = v1(input, "***");
        cout << "----------------------------------------" << endl;
        cout << "Your string enhanced: " << result << endl;
        cout << "Your original string: " << input << endl;
        cout << "----------------------------------------" << endl;

        result = v2(input, "###");
        cout << "Your string enhanced: " << result << endl;
        cout << "Your original string: " << input << endl;
        cout << "Resettig original string.\n";
        input = copy;
        cout << "----------------------------------------" << endl;

        result = v3(input, "@@@");
        cout << "Your string enhanced: " << result << endl;
        cout << "Your original string: " << input << endl;
        cout << "----------------------------------------" << endl;

        return 0;
}

string v1(const string &s1, const string &s2)
{
        string tmp;
        tmp = s2 + s1 + s2;
        return tmp;
}

string &v2(string &s1, const string &s2)
{
        s1 = s2 + s1 + s2;
        return s1;
}

string &v3(const string &s1, const string &s2)
{
        string tmp;
        tmp = s2 + s1 + s2;
        return tmp; //tmp引用的是临时变量，函数结束后，tmp被销毁，引用的内容也被销毁
}