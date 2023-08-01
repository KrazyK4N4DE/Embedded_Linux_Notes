#include <stdio.h>
#define INF 210000000  // 代指无限大
#define N 4

int min(int a, int b)
{
		return a < b ? a : b;
}

void floyd(int matrix[N][N], int n)
{
		for (int k = 0; k < n; ++k)
		{
				for (int i = 0; i < n; ++i)
				{
						for (int j = 0; j < n; ++j)
								matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
				}
		}
}

int main()
{
		int matrix[N][N] = 
		{ 
				{0, 1, INF, INF}, 
				{4, 0, INF, 5}, 
				{INF, 2, 0, INF}, 
				{3, INF, 7, 0}
		};
		floyd(matrix, N);
		for (int i = 0; i < N; ++i)
		{
				for (int j = 0; j < N; ++j)
						printf("%d ", matrix[i][j]);
				putchar('\n');
		}
		return 0;
}