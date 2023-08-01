/*
* �ظ������ַ���
*/
#include <iostream>
using namespace std;

// �ƶ�ƥ�䣺��Ȼǰ������ͬ���Ӵ�����������ͬ���Ӵ����� s + s��������ɵ��ַ����У�������Ӵ���ǰ����ǰ����Ӵ����󴮣���һ���������һ��s
bool repeatedSubstringPattern(string s)
{
        string ss = s + s;  // �����ַ���ƴ������
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);  // ��ͷȥβ
        if (ss.find(s) != string::npos) return true;  // �����ͷȥβ�����ҵ�s�ַ�����˵��ƴ�Ӻ��ֳ��ָ�s
        return false;
}

// KMP�㷨������ǰ��׺������������Ӵ�������С�ظ��Ӵ�
void getNext(int* next, const string& s)
{
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
                while (j > 0 && s[j] != s[i]) j = next[j - 1];
                if (s[j] == s[i]) j++;
                next[i] = j;
        }
}
bool repeatedSubstringPatternKMP(string s)
{
        int len = s.size();
        if (len == 0) return false;  // �ַ�������Ϊ0������û�����ݣ���̸�Ӵ���
        int* next = new int[len];
        getNext(next, s);  // ����ǰ׺��
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) return true;  // len - next[len - 1]��ʾ����ǰ��׺���������Ӵ��ĳ��ȣ�������ܱ�len�������ǿ϶������ظ��Ӵ���
        return false;
}

int main()
{
		return 0;
}