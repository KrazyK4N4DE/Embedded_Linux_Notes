/*
* ����֮��
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
                // ������ǰԪ�أ�����map��Ѱ���Ƿ���ƥ���key
                auto iter = map.find(target - nums[i]);
                if (iter != map.end())
                        return { iter->second, i };
                // ���û�ҵ�ƥ��ԣ��Ͱѷ��ʹ���Ԫ�غ��±���뵽map��
                map.insert(pair<int, int>(nums[i], i));
        }
        return {};
}

int main()
{
        return 0;
}