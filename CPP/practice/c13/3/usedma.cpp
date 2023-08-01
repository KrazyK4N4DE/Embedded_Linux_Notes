#include <iostream>
#include "dma.h"

using namespace std;

int main()
{
        baseDMA shirt("Portabelly", 8);
        cout << "Displaying baseDMA object:\n";
        cout << shirt << endl;
        cout << "--------------------------------------------\n";

        lacksDMA balloon1("red", "Blimpo", 4);
        cout << "Displaying lacksDMA object:\n";
        cout << balloon1 << endl;
        cout << "--------------------------------------------\n";

        lacksDMA balloon2(balloon1); // 基类定义的拷贝构造函数拷贝了"Blimpo"和4，默认拷贝函数拷贝了"red"
        cout << "Displaying lacksDMA copy object:\n";
        cout << balloon2 << endl;
        cout << "--------------------------------------------\n";

        hasDMA map1("Mercator", "Keys", 5);
        cout << "Displaying hasDMA object:\n";
        cout << map1 << endl;
        cout << "--------------------------------------------\n";

        hasDMA map2 = map1;
        cout << "Displaying hasDMA copy object:\n";
        cout << map2 << endl;
        cout << "--------------------------------------------\n";

        return 0;
}