#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const int SIZE = 39;

int main()
{
        vector<int> numbers(SIZE);
        cout << "SIZE = " << SIZE << endl;
        srand(time(0));
        generate(numbers.begin(), numbers.end(), rand);
        int count3, count13;
        count3 = count13 = 0;

        for_each(numbers.begin(), numbers.end(), [&](int x) {count3 +=  (x % 3 == 0); count13 +=  (x % 13 == 0);});
        cout << "Count of numbers divisible by 3: " << count3 << endl;
        cout << "Count of numbers divisible by 13: " << count13 << endl;

        return 0;
}