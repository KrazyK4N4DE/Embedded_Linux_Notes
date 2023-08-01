#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])  // a.out t1 t2 t3
{
        if(argc == 1)
        {
                cerr << "Usage: " << argv[0] << " filename(s)\n";
                exit(0);
        }

        long count;
        long total = 0;
        char ch;

        ifstream fin;
        for(int i = 1; i < argc; i++)
        {
                fin.open(argv[i]);
                if(!fin.is_open())
                {
                        cout << argv[i] << " could not be opened.\n";
                        fin.clear();
                        continue;
                }
                count = 0;
                while(fin.get(ch))
                        count++;
                cout << count << " characters in " << argv[i] << endl;
                total += count;
                fin.clear();
                fin.close();
        }
        cout << total << " characters in all files.\n";
}