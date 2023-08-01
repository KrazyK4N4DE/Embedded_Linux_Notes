#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

void outint(int n) {cout << n << " ";}

int main()
{
        list<int> one(5, 2);  //创建一个包含5个2的list
        cout << "List one: \n";
        for_each(one.begin(), one.end(), outint);

        int stuff[5] = {1, 2, 4, 8, 6};
        list<int> two;
        two.insert(two.begin(), stuff, stuff + 5);  //将stuff数组的元素插入到two的头部
        cout << "\nList two: \n";
        for_each(two.begin(), two.end(), outint);
        cout << endl;

        int more[6] = {6, 4, 2, 4, 6, 5};
        list<int> three(two);
        three.insert(three.end(), more, more + 6);  //将more数组的元素插入到three的尾部
        cout << "\nList three: \n";
        for_each(three.begin(), three.end(), outint);
        cout << endl;

        cout << "\nList three minus 4: \n";
        three.remove(4); //删除three中所有值为4的元素
        for_each(three.begin(), three.end(), outint);
        cout << endl;

        cout << "\nList three after splice: \n";
        three.splice(three.begin(), one);  //将one中的元素合并到three的头部
        for_each(three.begin(), three.end(), outint);
        cout << endl;

        cout << "\nList three after unique: \n";
        three.unique();  //保留three中连续重复元素的第一个
        for_each(three.begin(), three.end(), outint);
        cout << endl;

        cout << "\nList three after sort & unique: \n";
        three.sort();  //将three中的元素从小到大排序
        three.unique();  //保留three中连续重复元素的第一个
        for_each(three.begin(), three.end(), outint);
        cout << endl;

        cout << "\nSorted two merged into three: \n";
        two.sort();
        three.merge(two);  //将two中的元素合并到three中
        for_each(three.begin(), three.end(), outint);
        cout << endl;

        return 0;
}