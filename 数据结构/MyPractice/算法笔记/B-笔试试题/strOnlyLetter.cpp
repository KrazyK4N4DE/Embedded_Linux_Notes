#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

// ȥ���ַ����е��ظ���ĸ
string removeDuplicates(const string& str) {
        string result;
        unordered_set<char> seen;

        for (char ch : str) {
                if (seen.find(ch) == seen.end()) {
                        result += ch;
                        seen.insert(ch);
                }
        }

        return result;
}

bool areStringsEqual(const string& str1, const string& str2) {
        // ���ȣ��������ַ���ȥ�غ���������ȷ�����ǰ�����ͬ����ĸ
        string sortedStr1 = removeDuplicates(str1);
        string sortedStr2 = removeDuplicates(str2);

        sort(sortedStr1.begin(), sortedStr1.end());
        sort(sortedStr2.begin(), sortedStr2.end());

        // �Ƚ��������ַ����Ƿ����
        return sortedStr1 == sortedStr2;
}

int main() {
        string str1, str2;

        // ���������ַ���
        cout << "�������һ���ַ�����";
        cin >> str1;
        cout << "������ڶ����ַ�����";
        cin >> str2;

        // ��������ַ����Ƿ��������ͬ����ĸ��������
        cout << (areStringsEqual(str1, str2) ? "true" : "false") << endl;

        return 0;
}
