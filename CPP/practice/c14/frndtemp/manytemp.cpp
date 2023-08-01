/*
非约束模板友元
*/
#include <iostream>

using namespace std;

template <class T>
class HasFriend
{
private:
        T item;
public:
        HasFriend(const T &i) : item(i) {}
        template <class C, class D>
        friend void Show2(C &c, D &d);
};

template <class C, class D>
void Show2(C &c, D &d)
{
        cout << c.item << ", " << d.item << endl;
}

int main()
{
        HasFriend<int> hfi1(10);
        HasFriend<int> hfi2(20);
        HasFriend<double> hfdb(0.5);

        cout << "hfi1, hfi2: ";
        Show2(hfi1, hfi2);

        cout << "hfdb: ";
        Show2(hfdb, hfi2);

        return 0;
}