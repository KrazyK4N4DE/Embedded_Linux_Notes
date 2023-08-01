/*
* ������
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
        bool isValid(vector<vector<char>>& board, int row, int col, char val) {
                for (int i = 0; i < 9; i++) { // �ж������Ƿ��ظ�
                        if (board[row][i] == val) {
                                return false;
                        }
                }
                for (int j = 0; j < 9; j++) { // �ж������Ƿ��ظ�
                        if (board[j][col] == val) {
                                return false;
                        }
                }
                int startRow = (row / 3) * 3;
                int startCol = (col / 3) * 3;
                for (int i = startRow; i < startRow + 3; i++) { // �ж�9�������Ƿ��ظ�
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
                        for (int j = 0; j < board[0].size(); j++)  // ������ά����
                        {
                                if (board[i][j] == '.')  // �пհ׵ĸ��Ӿ�ȥ����������
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
                                        return false;  // 1��9�������ʵĻ�����return false�ɣ��Ѿ�û�н�������ˣ��Ժ�ĸ�������Ҳû����
                                }
                        }
                }
                return true;  // �����궼û��return false��˵��Ҳ���ɹ�������
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