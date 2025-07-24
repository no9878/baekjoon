#include <stdio.h>

int N, M;//1<=N<=1000,0<=M<=N*(N-1)/2
int graph[1001][1001] = { 0 };
visited[1001] = { 0 };
int front = 0; rear = 0;
int queue[1001] = { 0 };
int count = 0;
void enqueue(int x)
{
	queue[rear++] = x;
	
}
int dequeue()
{
	return queue[front++];
}
int empty()
{
	return (front == rear);
}
void bfs(int start)
{
	if (visited[start] == 0)
	{
		count++;
		enqueue(start);
		visited[start] = 1;
		
		while (!empty())
		{
			int curr = dequeue();
			
			
			for (int i = 1; i <= N;++i)
			{
				if (graph[curr][i] == 1 && !visited[i])
				{
					
					enqueue(i);
					visited[i] = 1;
				}
			}
		}
	}
}

int main(void)
{
	scanf_s("%d %d", &N, &M);
	int u, v;
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d", &u, &v);
		graph[u][v] = graph[v][u] = 1;
	}
	for (int i = 1; i <= N;i++)
	{
		bfs(i);
	}
	printf("%d\n", count);
	return 0; 
}