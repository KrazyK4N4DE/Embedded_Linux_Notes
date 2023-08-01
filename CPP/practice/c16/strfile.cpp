#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
        ifstream fin;
        fin.open("abc.txt");
        if(!fin.is_open())
        {
                cerr << "Can't open file. Bye.\n";  //cerr是标准错误输出流，用于输出错误信息，且只能输出到屏幕
                exit(EXIT_FAILURE );
        }

        string item;
        int count = 0;
        getline(fin, item, ':');  //从fin中读取一行，以':'为分隔符，将读取的内容赋值给item
        while(fin)
        {
                ++count;
                cout << count << ": " << item << endl;
                getline(fin, item, ':');
        }

        fin.close();

        return 0;
}