#include <iostream>
#include <memory> //智能指针头文件
#include <string>

using namespace std;

class Report
{
private:
        string str;
public:
        Report(string s) : str(s) { cout << "Object created!" << endl; }
        ~Report() { cout << "Object deleted!" << endl; }
        void comment() { cout << str << endl; }
};

int main() 
{
        {
                shared_ptr<Report> ps(new Report("using shared_ptr"));
                ps -> comment();
        }

        {
                unique_ptr<Report> ps(new Report("using unique_ptr"));
                ps -> comment();
        }

        return 0;
}