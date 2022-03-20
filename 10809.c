#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char word[101];
int result;

void input(void)
{
	scanf("%s", &word);
	//printf("%s", word);

}

int process(int Alpha) //요소의 위치를 int형으로 반환한다
{
	int index = 0;
	Alpha += 97; // (아스키 값으로 바꿔줌)알파벳으로 변환
	//printf("출력중인 알파벳: %c\n", Alpha);
	while (word[index] != NULL)
	{
		if (word[index] == Alpha)
		{
			result = index;
			//printf("process의 result값: %d\n", result);
			break;
		}
		else
		{
			result = -1;
		}
		index++;
	}
	return result;
}


int main(void)
{
	input();
	
	for (int i = 0; i < 26; i++)
	{
		result = process(i);

		//printf("main문의 result값: %d\n", result);
		printf("%d ", result);
	}
	

	return 0;
}