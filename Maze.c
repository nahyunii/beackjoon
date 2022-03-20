#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10001

typedef struct node {
	int x;
	int y;
}pos_t;

pos_t pos1;

#if 0
pos_t temp;
temp.x = 0;
temp.y = 0;

void func(int a, pos_t pos);
func(temp.x, temp);
#endif

pos_t queue[MAX];

int rear;
int front;
char map[101][101];
int check[101][101];

void push(pos_t N)
{
	rear += 1;
	queue[rear].x = N.x;
	queue[rear].y = N.y;
}

int pop_x(void)
{
	//front += 1;
	//return queue[front];

	return queue[front + 1].x;
}

int pop_y(void)
{
	front += 1;
	return queue[front].y;
}

int Is_empty(void)
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}


int process_BFS(pos_t V)
{
	pos_t candidate;
	int count = 1;
	pos_t buffer;

	int dx[4] = { 0, 1, 0, -1 }; // ->인접한 네방향 x좌표
	int dy[4] = { -1, 0, 1, 0 }; // ->인접한 네방향 y좌표
	// 1. push(start_node);
	push(V);
	// 1.1 day = 0
	// 2. check[start_node] <- day
	check[V.y][V.x] = count;
	// 3. while (not empty){
	while (Is_empty() == 0)
	{
		//    a. buffer <- pop()
		buffer.x = pop_x();
		buffer.y = pop_y();

		//printf("b.x: %d b.y: %d\n", buffer.x, buffer.y);
		//    c. for (i = 0; i < 4; i++) { //candidate[i]
		for (int i = 0; i < 4; i++)
		{
			// i. if (buffer, candidate 인접)
			// c.x = buffer.x + dx[i]
			candidate.x = buffer.x + dx[i];
			// c.y = buffer.y + dy[i]
			candidate.y = buffer.y + dy[i];

			//printf("c.x: %d, c.y: %d\n", candidate.x, candidate.y);
			if (candidate.x > -1 &&  candidate.y >-1)
			{
				if (map[candidate.y][candidate.x] == '1')
				{
					//printf("map[%d][%d]\n", candidate.y, candidate.x);
					if (check[candidate.y][candidate.x] == -1)
					{

						push(candidate);
						//printf("push pos:\n");
						//printf("c.x: %d, c.y: %d\n", candidate.x, candidate.y);

						check[candidate.y][candidate.x] = check[buffer.y][buffer.x] + 1;
						count = check[candidate.y][candidate.x];
					}
				}
				
			}
		}
	}
#if 0
	printf("check:\n");
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			printf("%d ", check[y][x]);
		}
		printf("\n");
	}
#endif
	return count;
}

int main(void)
{
	int M;
	int N;
	int result;
	pos_t temp;
	temp.x = 0;
	temp.y = 0;

	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++)
	{
		scanf("%s", &map[y]);
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			check[y][x] = -1;
			//printf("%d ", check[y][x]);
		}
		//printf("\n");
	}


#if 0
	printf("map: \n");
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			printf("%c ", map[y][x]);
		}
		printf("\n");
	}
#endif

	process_BFS(temp);

	printf("%d", check[N-1][M-1]);
}
