/*
非模板友元
*/
#include <iostream>

using namespace std;

template <class T>
class HasFriend
{
private:
        T item;
        static int ct;
public:
        HasFriend(const T &i) : item(i) { ct++; }
        ~HasFriend() { ct--; }
        friend void Counts();                // display ct
        friend void Reports(HasFriend<T> &); // display item
};

template <class T>
int HasFriend<T>::ct = 0;

void Counts()
{
        cout << "int count: " << HasFriend<int>::ct
             << "\ndouble count: " << HasFriend<double>::ct << endl;
}

void Reports(HasFriend<int> &hf)
{
        cout << "HasFriend<int> item: " << hf.item << endl;
}

void Reports(HasFriend<double> &hf)
{
        cout << "HasFriend<double> item: " << hf.item << endl;
}

int main()
{
        cout << "Before declaring any objects\n"
             << "-----------------------------\n";
        Counts();
        cout << "-----------------------------\n";

        HasFriend<int> hfi1(10);
        cout << "After declaring hfi1\n"
             << "-----------------------------\n";
        Counts();
        Reports(hfi1);
        cout << "-----------------------------\n";

        HasFriend<int> hfi2(20);
        cout << "After declaring hfi2\n"
             << "-----------------------------\n";
        Counts();
        Reports(hfi2);
        cout << "-----------------------------\n";

        HasFriend<double> hfdb(0.5);
        cout << "After declaring hfdb\n"
             << "-----------------------------\n";
        Counts();
        Reports(hfdb);
        cout << "-----------------------------\n";

        return 0;
}