#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char word[101];
int result;

void input(void)
{
	scanf("%s", &word);
	//printf("%s", word);

}

int process(int Alpha) //����� ��ġ�� int������ ��ȯ�Ѵ�
{
	int index = 0;
	Alpha += 97; // (�ƽ�Ű ������ �ٲ���)���ĺ����� ��ȯ
	//printf("������� ���ĺ�: %c\n", Alpha);
	while (word[index] != NULL)
	{
		if (word[index] == Alpha)
		{
			result = index;
			//printf("process�� result��: %d\n", result);
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

		//printf("main���� result��: %d\n", result);
		printf("%d ", result);
	}
	

	return 0;
}