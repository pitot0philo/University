#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void line_up(char* a, int* b, int c);

int main(void)
{
	char str[100];
	char alphabet[27];
	int temp[27] = { 0 };
	int count = 0;
	char* Return;
	int counttemp = 0;
	for (int i = 0; i < 25; i++)
	{
		alphabet[i] = i + 97;//alphabet 배열에 a부터 z까지의 소문자 저장
	}

	printf("enter the string : ");
	fgets(str, strlen(str), stdin);

	if ((Return = strchr(str, '\n')) != NULL)
	{
		*Return = '\0';
	}

	for (int i = 0; i < 25; i++)
	{
		for (int k = 0; k < strlen(str); k++)
		{
			if (str[k] == alphabet[i])
			{
				temp[i] = ++count;
			}
		}
		count = 0;
	}

	counttemp = sizeof(temp) / sizeof(int);

	line_up(alphabet, temp, counttemp);

	for (int i = 0; i < 25; i++)
	{
		if(temp[i])
			printf("%c : %d\n", alphabet[i], temp[i]);
	}
}

//temp=count of alphabet.
//if temp[0]<temp[1] -> alphabet[0]->alphabet[1]
//if temp[0]<temp[1]=temp[2]<temp[3] -> alphabet[0]->alphabet[3] and alphabet[1], alphabet[2] stay still.
//func get two array(temp and alphabet), one integer value(count temp)
//if temp change, alphabet also change. but how?
//how to change temp? Refer to Report 6_2 Random
//Data Type: Void func

void line_up(char* a, int* b, int c)
{
	int tempcount;
	int tempalphabet;
	for (int i = 0; i < c; i++)
	{
		for (int j = i + 1; j < c; j++)
		{
			if (*(b + i) < * (b + j))
			{
				tempcount = *(b + j);
				*(b + j) = *(b + i);
				*(b + i) = tempcount; // temp array lined up

				tempalphabet = *(a + j);
				*(a + j) = *(a + i);
				*(a + i) = tempalphabet;//alphabet arry lined up?
			}
		}
	}
}
