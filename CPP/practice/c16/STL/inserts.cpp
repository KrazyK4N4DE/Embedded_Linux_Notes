#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void output(const string &s) { cout << s << " "; }

int main()
{
        string s1[4] = {"fine", "fish", "fashion", "fate"};
        string s2[2] = {"busy", "bats"};
        string s3[2] = {"silly", "singers"};

        vector<string> words(4);
        copy(s1, s1 + 4, words.begin());
        for_each(words.begin(), words.end(), output);
        cout << endl;

        //back_insert_iterator意为在容器的尾部插入元素
        copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words));
        for_each(words.begin(), words.end(), output);
        cout << endl;

        //insert_iterator意为在容器的指定位置插入元素
        copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin()));
        for_each(words.begin(), words.end(), output);
        cout << endl;

        return 0;
}