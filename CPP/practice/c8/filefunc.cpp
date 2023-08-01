#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

const int LIMIT = 5;

void file_it(ostream &os, double fo, const double fe[], int max);

int main()
{
        ofstream fout;
        const char *fn = "filefunc.txt";

        fout.open(fn);
        if(!fout.is_open())
        {
                cout << "Can't open " << fn << ". Bye.\n";
                exit(EXIT_FAILURE);
        }

        //物镜
        cout << "Enter the focal length of your telescope objective in mm: ";
        double obj;
        cin >> obj;

        //目镜
        double eps[LIMIT];
        cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
        for(int i = 0; i < LIMIT; i++)
        {
                cout << "Eyepiece #" << i + 1 << ": ";
                cin >> eps[i];
        }

        //应用于终端
        file_it(cout, obj, eps, LIMIT);
        //应用于文件
        file_it(fout, obj, eps, LIMIT);

        return 0;
}

void file_it(ostream &os, double fo, const double fe[], int max)
{
        os << "Focal length of objective: " << fo << endl;
        os << "F.1. eyepieces\t\tMagnification" << endl;

        for(int i = 0; i < max; i++)
        {
                os << fe[i] << "\t\t\t" << int(fo / fe[i] + 0.5) << endl;
        }
}