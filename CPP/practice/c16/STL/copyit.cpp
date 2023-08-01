#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
        int casts[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int> dice(10);
        copy(casts, casts + 10, dice.begin());
        cout << "Let the dice be cast!" << endl;
        //创建一个输出迭代器
        ostream_iterator<int, char> out_iter(cout, " ");
        copy(dice.begin(), dice.end(), out_iter);
        
        cout << "\nImplicit use of reverse iterator.\n";
        copy(dice.rbegin(), dice.rend(), out_iter);
        cout << "\nExplicit use of reverse iterator.\n";
        //创建一个反向迭代器
        vector<int>::reverse_iterator ri;
        for(ri = dice.rbegin(); ri != dice.rend(); ri++)
                cout << *ri << ", ";
        cout << endl;

        return 0;
}