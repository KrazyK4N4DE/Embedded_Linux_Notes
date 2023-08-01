#include<iostream>

using namespace std;

const int SIZE = 5;

void eatline();
int fill_arr(double arr[], int Max);                 //填充数组
void show_arr(const double arr[], int n);            //显示数组
void revaluate(double index, double arr[], int n);   //重新评估数组

int main()
{
    double array[SIZE];

    int input_count = fill_arr(array, SIZE);
    cout << "Input_count = " << input_count << endl;
    show_arr(array, input_count);
    if(input_count > 0)     //如果数组有输入，才能进行评估
    {
        cout << "Enter the factor to revaluate the array: ";
        double factor;
        while(!(cin >> factor))
        {
            eatline();
            cout << "Enter a valid factor: ";
        }
        revaluate(factor, array, input_count);
        show_arr(array, input_count);
    }
    cout << "Bye!\n";
    cin.get();
    cin.get();

    return 0;
}

void eatline()
{
    cin.clear();
    while(cin.get() != '\n')
        continue;
}

int fill_arr(double arr[], int Max)
{
    int i;
    double tmp;
    for(i = 0; i < Max; i++)
    {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> tmp;
        if(!cin)
        {
            eatline();
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if(tmp < 0)
            break;
        arr[i] = tmp;
    }
    return i;
}

void show_arr(const double arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << "Property #" << i + 1 << ": $" << arr[i] << endl;
}

void revaluate(double index, double arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] *= index;
}
