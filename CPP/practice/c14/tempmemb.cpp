#include <iostream>

using namespace std;

template <typename T>
class Beta
{
private:
        template <typename V>
        class Hold
        {
        private:
                V val;
        public:
                Hold(V v = 0) : val(v) {}
                void Show() const {cout << val << endl;}
                V Value() const {return val;}
        };
        Hold<T> q;
        Hold<int> n;
public:
        Beta(T t, int i) : q(t), n(i) {}
        template <typename U>
        U Blab(U u, T t) {return (q.Value() + n.Value()) *u / t;}
        void Show() const {q.Show(); n.Show();}
};

int main()
{
        Beta<double> guy(3.5, 3);
        cout << "T was set to double\n";
        guy.Show();

        cout << "V == T, they are both double\n";
        cout << "U was set to int, so int is returned\n";
        cout << guy.Blab(10, 2.3) << endl;

        cout << "U was set to double, so double is returned\n";
        cout << guy.Blab(10.0, 2.3) << endl;

        return 0;
}