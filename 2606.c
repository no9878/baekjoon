#include <stdio.h>

int com;//1<=com<=100
graph[101][101] = { 0 };
visited[101] = {0};
int count = 0;
void dfs(int start)
{
	visited[start] = 1;
	count++;
	for (int i = 1; i <= com;++i)
	{
		if (!visited[i] && graph[i][start] == 1)
			dfs(i);
	}
}

int main(void)
{
	
	scanf_s("%d", &com);
	int link;
	scanf_s("%d", &link);
	int a, b;
	for (int i = 0; i < link; ++i)
	{
		
		scanf_s("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
		
	}
	dfs(1);
	printf("%d\n", count-1);
	return 0;
}