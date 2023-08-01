/*
 * @brief  类对象的定位new运算符操作
 */
#include <iostream>
#include <string>
#include <new>

using namespace std;

const int BUF = 512;

class JustTesting
{
private:
        string words;
        int num;

public:
        JustTesting(const string &s = "Just testing", int n = 0)
        {
                words = s;
                num = n;
                cout << words << " constructed\n";
        }
        ~JustTesting()
        {
                cout << words << " destroyed\n";
        }
        void Show() const
        {
                cout << words << ", " << num << endl;
        }
};

int main()
{
        char *buffer = new char[BUF];
        JustTesting *pc1, *pc2, *pc3, *pc4;

        cout << "Magnitude of JustTesting: " << sizeof(JustTesting) << endl;

        pc1 = new (buffer) JustTesting;     //定位new运算符
        pc2 = new JustTesting("heap1", 20); //普通new运算符

        cout << "buffer: " << (void *)buffer << endl
             << "heap1: " << pc2 << endl;

        cout << pc1 << ": ";
        pc1->Show();
        cout << pc2 << ": ";
        pc2->Show();

        //这里pc3指向的位置加了sizeof(JustTesting)，以免覆盖pc1指向的位置
        pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Better Idea", 6);
        pc4 = new JustTesting("heap2", 10);

        cout << pc3 << ": ";
        pc3->Show();
        cout << pc4 << ": ";
        pc4->Show();

        delete pc2;
        delete pc4;
        //显式调用析构函数，注意析构的顺序
        pc3->~JustTesting();
        pc1->~JustTesting();
        delete[] buffer;

        return 0;
}