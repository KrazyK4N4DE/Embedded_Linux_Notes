#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> Lotto(int ndot, int rdot);

int main()
{
        vector<int> winners = Lotto(51, 6);

        for(auto pt = winners.begin(); pt != winners.end(); pt++)
                cout << *pt << " ";
        cout << endl;

        return 0;
}

vector<int> Lotto(int ndot, int rdot)
{
        vector<int> v;
        srand(time(0));
        for(int i = 0; i < rdot; i++)
                v.push_back(rand() % ndot);
        return v;
}