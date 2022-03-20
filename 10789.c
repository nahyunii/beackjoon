#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char* string[5];
char result[75];

void get_String(void)
{
	/*
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", &string[i]);
		printf("%s\n", string[i]);
	}
	printf("before string value: 0x%x\n", string);
	printf("address of string: 0x%x\n", &string);
	string = (char*)malloc(15 * sizeof(char));
	printf("after string value: 0x%x\n", string);
	printf("address of string: 0x%x\n", &string);
	scanf("%s", string);
	printf("%s", string);
	*/
	
	for (int i = 0; i < 5; i++)
	{
		string[i] = (char*)malloc(16 * sizeof(char));//동적할당 string의 사이즈 +1만큼 필요하다
		scanf("%s", string[i]);
		//printf("%s\n", string[i]);
	}

}

int process_String(void)
{
	for (int i = 0; i < 75; i++)
	{
		result[i] = '!';
	}
	
	int length = 0;
	for (int i = 0; i <15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ('A' <= string[j][i] && string[j][i] <= 'Z' ||
				'0' <= string[j][i] && string[j][i] <= '9' ||
				'a' <= string[j][i] && string[j][i] <= 'z')
			{
				result[length] = string[j][i];
				length++;
			}
		}	
	}
	//printf("length:%d\n", length);
	return length;

}

void print_result(int length)
{
	for (int i = 0; i < length; i++)
	{
		//printf("%dth : %c\n", i, result[i]);
		printf("%c", result[i]);
	}
	
}

int main(void)
{
	int length;

	//입력
	get_String();

	//연산
	length = process_String();

	//출력
	print_result(length);

	return 0;
}