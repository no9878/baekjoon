#include <stdio.h>
#include <stdlib.h>

int drow[] = { -1,1,0,0 };
int dcol[] = { 0,0,-1,1 };

void dfs(int row, int col,int all[50][50])
{
	all[row][col] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nrow = row + drow[i];
		int ncol = col + dcol[i];
		if (nrow >= 0 && nrow < 50 && ncol >= 0 && ncol < 50 && all[nrow][ncol] == 1)
		{
			dfs(nrow, ncol,all);
		}
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);
	int* close = (int*)malloc(sizeof(int) * T);
	for (int i = 0; i < T; ++i)
		
		close[i] = 0;

	for (int Q = 0; Q < T; ++Q)
	{
		int all[50][50] = { 0 };
		int M, N, K;
		int X[2500], Y[2500];

		if (scanf("%d %d %d", &M, &N, &K) != 3 || M < 1 || M>50 || N < 1 || N>50 || K < 1 || K>2500)
			return 1;
		for (int j = 0; j < K; ++j)
		{
			if (scanf("%d %d", &X[j], &Y[j]) != 2 || X[j]<0 || X[j]>M - 1 || Y[j]<0 || Y[j]>N - 1)
				return 1;
		}



		for (int i = 0; i < K; ++i)
		{
			all[Y[i]][X[i]] = 1;

		}
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (all[i][j] == 1)
				{
					dfs(i, j,all);
					close[Q]++;
				}
			}
		}
	}
	for (int i = 0 ; i < T; ++i)
		printf("%d\n", close[i]);
	free(close);
	return 0;
}