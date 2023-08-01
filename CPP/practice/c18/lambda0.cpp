#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const int SIZE1 = 39;
const int SIZE2 = 390;
const int SIZE3 = 3900;

bool mod3(int x) {return x % 3 == 0;}
bool mod13(int x) {return x % 13 == 0;}

int main()
{
        vector<int> numbers(SIZE1);
        cout << "SIZE1 = " << SIZE1 << endl;

        srand(time(0));
        generate(numbers.begin(), numbers.end(), rand);
        int count3, count13;
        
        // 方法1：函数指针
        count3 = count_if(numbers.begin(), numbers.end(), mod3);
        cout << "Count of numbers divisible by 3: " << count3 << endl;
        count13 = count_if(numbers.begin(), numbers.end(), mod13);
        cout << "Count of numbers divisible by 13: " << count13 << endl;

        // 方法2：函数对象
        numbers.resize(SIZE2);
        generate(numbers.begin(), numbers.end(), rand);
        cout << "SIZE2 = " << SIZE2 << endl;
        
        class f_mod
        {
        private:
                int dv;
        public:
                f_mod(int d = 1) : dv(d) {}
                bool operator()(int x) {return x % dv == 0;}
        };

        count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
        cout << "Count of numbers divisible by 3: " << count3 << endl;
        count13 = count_if(numbers.begin(), numbers.end(), f_mod(13));
        cout << "Count of numbers divisible by 13: " << count13 << endl;

        // 方法3：lambda表达式
        numbers.resize(SIZE3);
        generate(numbers.begin(), numbers.end(), rand);
        cout << "SIZE3 = " << SIZE3 << endl;

        count3 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0;});
        cout << "Count of numbers divisible by 3: " << count3 << endl;
        count13 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 13 == 0;});
        cout << "Count of numbers divisible by 13: " << count13 << endl;

        return 0;
}