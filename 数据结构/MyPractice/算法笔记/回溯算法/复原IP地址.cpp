/*
* ��ԭIP��ַ
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
        bool isValid(const string& s, int start, int end)
        {
                if (start > end) return false;  // û��һ�㶫��
                if (s[start] == '0' && start != end) return false;  // ���Ǵ�0��������ǰ��0
                int num = 0;
                for (int i = start; i <= end; i++)  // �ַ���ת����
                {
                        if (s[i] > '9' || s[i] < '0') return false;  // ����0��9���Ƿ�
                        num = num * 10 + (s[i] - '0');
                        if (num > 255) return false;  // ת�����������255���������Ҷ�ip������
                }
                return true;
        }

        vector<string> results;
        void backtracking(string s, int startIndex, int pointNum)
        {
                if (pointNum == 3)
                {
                        if (isValid(s, startIndex, s.size() - 1))
                                results.push_back(s);
                        return;
                }
                for (int i = startIndex; i < s.size(); i++)
                {
                        if (isValid(s, startIndex, i))
                        {
                                s.insert(s.begin() + i + 1, '.');  // +1����ΪС����Ҫ����iλ�õ����ֺ���
                                pointNum++;
                                backtracking(s, i + 2, pointNum);  // ��Ϊ�ַ���������һ��С���㣬���Բ���+1��+2
                                pointNum--;
                                s.erase(s.begin() + i + 1);
                        }
                        else break;  //�Ӵ���������������һ��ĺ������������Ҫ�ˣ���Ϊ�Ѿ�֪�����Ǹ���Ч��IP
                }
        }
public:
        vector<string> restoreIpAddresses(string s) {
                if (s.size() < 4 || s.size() > 12) return results;  // ǳǳ��֦һ��
                backtracking(s, 0, 0);
                return results;
        }
};

int main()
{
        return 0;
}