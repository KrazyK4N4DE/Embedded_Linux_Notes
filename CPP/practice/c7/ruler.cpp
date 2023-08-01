#include <iostream>

using namespace std;

const int Len = 66;
const int Divs = 6;

void sub(char ar[], int low, int high, int level);

int main()
{
        char ruler[Len];
        //数组创建后每个元素都是随机的，所以先重置一下
        for (int i = 0; i < Len; i++)
                ruler[i] = ' ';
        int min = 0;
        int max = Len - 2;
        ruler[min] = ruler[max] = '|';
        ruler[Len-1] = '\0';
        cout << ruler << endl;

        for(int i = 1; i <= Divs; i++)
        {
                sub(ruler, min, max, i);
                cout << ruler << endl;
        }

        return 0;
}

void sub(char ar[], int low, int high, int level)
{
        if(level==0)
                return;
        //计算中间位置，将其设置为'|'，从而分为左右两半部分
        int mid = (high + low) / 2;
        ar[mid] = '|';
        //递归调用，使左右两半部分再分为左右两半部分
        sub(ar, low, mid, level - 1);
        sub(ar, mid, high, level - 1);
}