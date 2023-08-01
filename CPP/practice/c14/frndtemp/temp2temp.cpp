/*
约束模板友元
*/
#include <iostream>

using namespace std;

template <typename V>
void Counts();
template <typename V>
void Reports(V &hf);

template <class T>
class HasFriend
{
private:
        T item;
        static int ct;
public:
        HasFriend(const T &i) : item(i) { ct++; }
        ~HasFriend() { ct--; }
        friend void Counts<T>();                // display ct
        friend void Reports<HasFriend<T> >(HasFriend<T> &); // display item
};

template <class T>
int HasFriend<T>::ct = 0;

template <typename V>
void Counts()
{
        cout << "count: " << HasFriend<V>::ct << endl;
}

template <typename V>
void Reports(V &hf)
{
        cout << "Item: " << hf.item << endl;
}

int main()
{
        cout << "Before declaring any objects\n"
             << "-----------------------------\n";
        Counts<int>();
        cout << "-----------------------------\n";

        HasFriend<int> hfi1(10);
        cout << "After declaring hfi1\n"
             << "-----------------------------\n";
        Counts<int>();
        Reports(hfi1);
        cout << "-----------------------------\n";

        HasFriend<int> hfi2(20);
        cout << "After declaring hfi2\n"
             << "-----------------------------\n";
        Counts<int>();
        Reports(hfi2);
        cout << "-----------------------------\n";

        HasFriend<double> hfdb(0.5);
        cout << "After declaring hfdb\n"
             << "-----------------------------\n";
        Counts<double>();
        Reports(hfdb);
        cout << "-----------------------------\n";

        return 0;
}