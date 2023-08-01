/*
* ����վ
*/
#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
		// ͨ��gas��cost��ӦԪ��������õ�ÿһվ�����������
		// curSum��¼��Ϊ���������ͣ������Ļ���ʾ��ǰ�濪ʼ��������û���ߵ��յ�ģ����ʱ������һվ��Ϊ��㣬��start��¼
		// totalSum��¼����վ�����������
		int curSum = 0, totalSum = 0, start = 0;
		for (int i = 0; i < gas.size(); i++)
		{
				curSum += (gas[i] - cost[i]);
				totalSum += (gas[i] - cost[i]);
				if (curSum < 0)
				{
						curSum = 0;
						start = i + 1;
				}
		}
		if (totalSum < 0) return -1;
		return start;
}

int main()
{
		return 0;
}