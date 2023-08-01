/*
在链表中添加和删除元素更容易，但排序速度更慢。
为证明这一点，编写一个程序，用于在链表和vector中存储1000000个int。
并计算在链表和vector中分别排序所需的时间。
并提出另一种方法：先将list的内容复制到vector中，然后对vector排序，再将vector的内容复制回list中。计算所需时间。
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const int LIM = 1000000;  // 1 million

int main()
{       
        srand(time(0));

        vector<int> vi0;
        // 为vi0赋值
        for(int i = 0; i < LIM; i++)
                vi0.push_back(rand() % 1000);
        
        vector<int> vi(vi0);
        list<int> li(vi0.begin(), vi0.end());

        clock_t start = clock();
        sort(vi.begin(), vi.end());
        clock_t end = clock();
        cout << "vector sort time: " << double(end - start) / CLOCKS_PER_SEC << endl;

        start = clock();
        li.sort();
        end = clock();
        cout << "list sort time: " << double(end - start) / CLOCKS_PER_SEC << endl;

        copy(vi0.begin(), vi0.end(), li.begin());
        start = clock();
        copy(li.begin(), li.end(), vi.begin());
        sort(vi.begin(), vi.end());
        end = clock();
        cout << "list to vector sort time: " << double(end - start) / CLOCKS_PER_SEC << endl;
        
        return 0;
}
