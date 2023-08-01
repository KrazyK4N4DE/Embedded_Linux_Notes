/*
* N�ʺ�
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
        vector<vector<string>> results;
        // �ж����̸�λ�÷Żʺ��Ƿ�Ϸ�
        bool isValid(vector<string>& chessboard, int n, int row, int col)
        {
                // ���ﲻ���ų����в��Ϸ��ģ���Ϊ��ÿһ��ݹ��У�ֻ��ѡͬһ���е�һ��Ԫ��
                // ֻ�ÿ����ڱ���֮�ϵģ���Ϊ֮�µĻ�û���������϶�û�лʺ�
                // �ų����в��Ϸ���
                for (int i = 0; i < row; i++)
                        if (chessboard[i][col] == 'Q') return false;
                // �ų�б��λ�ò��Ϸ���
                // �ų���45�Ƚǵ�
                for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
                        if (chessboard[i][j] == 'Q') return false;
                // �ų�135�Ƚǵ�
                for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
                        if (chessboard[i][j] == 'Q') return false;
                // ���Ϸ��Ǿ�true��
                return true;
        }
        void backtracking(vector<string>& chessboard, int n, int row)
        {
                if (row == n)
                {
                        results.push_back(chessboard);
                        return;
                }
                for (int col = 0; col < n; col++)  // colΪcolum(��)����˼
                {
                        if (isValid(chessboard, n, row, col))
                        {
                                chessboard[row][col] = 'Q';
                                backtracking(chessboard, n, row + 1);
                                chessboard[row][col] = '.';
                        }
                }
        }
public:
        vector<vector<string>> solveNQueens(int n) 
        {
                vector<string> chessboard(n, string(n, '.'));
                backtracking(chessboard, n, 0);
                return results;
        }
};

int main()
{
		return 0;
}