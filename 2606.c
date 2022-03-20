#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

int queue[MAX];
int check[MAX];
int graph[MAX][MAX];

int front = 0;
int rear = 0;

void push(int N)
{
	rear += 1;
	queue[rear] = N;
}

int pop(void)
{
	front += 1;
	return queue[front];
}

int empty(void)
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}

int process_bfs(int n, int v)
{
	int buffer;
	int temp = 0;

	for (int i = 1; i < n + 1; i++)
	{
		check[i] = 0;
	}

	push(v);
	check[v] = 1;
	while (empty() != 1)
	{
		buffer = pop();
		//	printf("buffer : %d\n", buffer);
		for (int i = 1; i < n + 1; i++)
		{

			if (graph[buffer][i] == 1)
			{
				if (check[i] == 0)
				{
					push(i);
					check[i] = 1;
					temp++;

					//printf("check[%d]: %d\n",i, check[i]);
				}
			}

		}
	}
	return temp;
}

int main(void)
{
	int N;
	int V;
	int v1, v2;
	int result;

	scanf("%d", &N);
	scanf("%d", &V);
	for (int i = 0; i < V; i++)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	result = process_bfs(N, 1);
	printf("%d", result);
}
