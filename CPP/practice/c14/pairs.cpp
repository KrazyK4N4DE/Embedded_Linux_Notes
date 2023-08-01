#include <iostream>

using namespace std;

template<class T1, class T2>
class Pair
{
private:
        T1 a;
        T2 b;
public:
        Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
        T1 &first();
        T2 &second();
        T1 first() const {return a;}
        T2 second() const {return b;}
};

template<class T1, class T2>
T1 &Pair<T1, T2>::first()
{
        return a;
}

template<class T1, class T2>
T2 &Pair<T1, T2>::second()
{
        return b;
}

int main()
{
        Pair<string, int> rating[4] = 
        {
                Pair<string, int>("The Purpled Duck", 5),
                Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
                Pair<string, int>("Cafe Souffle", 5),
                Pair<string, int>("Bertie's Eats", 3)
        };

        int joints = sizeof(rating) / sizeof(Pair<string, int>);

        cout << "Rating:\t Eatery\n";
        for(int i = 0; i < joints; i++)
                cout << rating[i].second() << ":\t" << rating[i].first() << endl;

        rating[3].first() = "Feb";
        rating[3].second() = 6;

        cout  << rating[3].second() << ":\t" << rating[3].first() << endl;

        return 0;
}