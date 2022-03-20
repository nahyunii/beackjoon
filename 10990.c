#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;

void get_num(void)
{
	scanf("%d", &N);
}

void print_first_line(int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		printf(" ");
	}
	printf("*\n");
}

void print_nth_line(int index)
{
	int nth = index + 2;
	
	for (int i = 0; i < N-nth; i++)
	{
		printf(" ");
	}
	printf("*");
	for (int i = 0; i < 1+ 2 * index; i++)
	{
		printf(" ");
	}
	printf("*");
	printf("\n");

}

void print_star(void)
{
	print_first_line(N);
	for (int i = 0; i < N - 1; i++)
	{
		print_nth_line(i);
	}

}

int main(void)
{
	get_num();
	print_star();
	return 0;
}