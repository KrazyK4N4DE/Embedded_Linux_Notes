/*
* �绰�������ĸ���
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
private:
        string letterMap[10] =
        {
                " ",
                " ",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz"
        };
        vector<string> results;
        string path;
        void backtracking(string digits, int index)  // ��ͬ��startIndex��index�Ǹ��߳��򣬴����digits����������ĸ��±���
        {
                if (digits.size() == 0) return;
                if (index == digits.size())
                {
                        results.push_back(path);
                        return;
                }

                int digit = digits[index] - '0';  // �ַ�ת��Ϊ����
                string letter = letterMap[digit];  // ���ַ�����ȡ����Ӧλ�õ����֣�Ȼ���Ӧ������ӳ�䵽��Ӧ����ĸ����

                for (int i = 0; i < letter.size(); i++)  // �����ķ�Χ�������Ŀ�ȣ�����ָÿ�����ֶ�Ӧ��ĸ����Ĵ�СΪ��Χ
                {
                        path.push_back(letter[i]);
                        backtracking(digits, index + 1);
                        path.pop_back();
                }
        }
public:
        vector<string> letterCombinations(string digits) 
        {
                backtracking(digits, 0);
                return results;
        }
};