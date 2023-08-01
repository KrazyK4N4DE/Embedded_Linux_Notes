/*
* N皇后
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
        vector<vector<string>> results;
        // 判断棋盘该位置放皇后是否合法
        bool isValid(vector<string>& chessboard, int n, int row, int col)
        {
                // 这里不用排除单行不合法的，因为在每一层递归中，只会选同一行中的一个元素
                // 只用考虑在本行之上的，以为之下的还没遍历到，肯定没有皇后
                // 排除单列不合法的
                for (int i = 0; i < row; i++)
                        if (chessboard[i][col] == 'Q') return false;
                // 排除斜线位置不合法的
                // 排除正45度角的
                for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
                        if (chessboard[i][j] == 'Q') return false;
                // 排除135度角的
                for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
                        if (chessboard[i][j] == 'Q') return false;
                // 都合法那就true吧
                return true;
        }
        void backtracking(vector<string>& chessboard, int n, int row)
        {
                if (row == n)
                {
                        results.push_back(chessboard);
                        return;
                }
                for (int col = 0; col < n; col++)  // col为colum(列)的意思
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