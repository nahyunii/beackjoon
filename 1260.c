#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001

int check[MAX];
int queue[MAX];
int front = 0;
int rear = 0;

int result[MAX];

int graph[MAX][MAX];

int N;
int M;
int V;

int temp2;

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

int process_bfs(void)
{
	int buffer;
	int temp = 0;

	//for (int i = 1; i < N+1; i++)
	{
		//check[i] = 0;
	}

	push(V);
	check[V] = 1;

	while (empty() != 1)
	{
		buffer = pop();
	//	printf("buffer : %d\n", buffer);
		result[temp] = buffer;
		temp++;
		for (int i = 1; i < N+1; i++)
		{
		
			if (graph[buffer][i] == 1)
			{
				if (check[i] == 0)
				{
					push(i);
					check[i] = 1;

					//printf("check[%d]: %d\n",i, check[i]);
				}
			}

		}
	}
}

void process_dfs(int current)
{
	result[temp2] = current;
	temp2++;
	check[current] = 1;
	for (int i = 1; i < N + 1; i++)
	{
		if (graph[current][i] == 1 && check[i] == 0)
		{
			process_dfs(i);
		}
	}
	


}


int main(void) 
{
	int v1, v2;

	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}


	process_dfs(V);

	for (int i = 0; i < temp2; i++)
	{
		//if (result[i] != 0)
		{
			printf("%d ", result[i]);
		}

	}

	for (int i = 0; i < temp2; i++)
	{
		result[i] = 0;
	}

	printf("\n");

	process_bfs();
	

	for (int i = 0; i < temp; i++)
	{
		//if (result[i] != 0)
		{
			printf("%d ", result[i]);
		}

	}

	return 0;
}