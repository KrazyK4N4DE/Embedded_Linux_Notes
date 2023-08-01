/*
* 解数独
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
        bool isValid(vector<vector<char>>& board, int row, int col, char val) {
                for (int i = 0; i < 9; i++) { // 判断行里是否重复
                        if (board[row][i] == val) {
                                return false;
                        }
                }
                for (int j = 0; j < 9; j++) { // 判断列里是否重复
                        if (board[j][col] == val) {
                                return false;
                        }
                }
                int startRow = (row / 3) * 3;
                int startCol = (col / 3) * 3;
                for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
                        for (int j = startCol; j < startCol + 3; j++) {
                                if (board[i][j] == val) {
                                        return false;
                                }
                        }
                }
                return true;
        }
        bool backtracking(vector<vector<char>>& board)
        {
                for (int i = 0; i < board.size(); i++)
                {
                        for (int j = 0; j < board[0].size(); j++)  // 遍历二维数组
                        {
                                if (board[i][j] == '.')  // 有空白的格子就去试着填数字
                                {
                                        for (char k = '1'; k <= '9'; k++)
                                        {
                                                if (isValid(board, i, j, k))
                                                {
                                                        board[i][j] = k;
                                                        if (int res = backtracking(board)) return true;
                                                        board[i][j] = '.';
                                                }
                                        }
                                        return false;  // 1到9都不合适的话，就return false吧，已经没有解决方案了，以后的格子填了也没用了
                                }
                        }
                }
                return true;  // 遍历完都没有return false，说明也都成功填完了
        }
public:
        void solveSudoku(vector<vector<char>>& board)
        {
                backtracking(board);
        }
};

int main()
{
		return 0;
}