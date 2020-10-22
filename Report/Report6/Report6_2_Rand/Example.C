#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int line_up(int* a, int count);

int main(void)
{
	int random[11];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 11; i++)
	{
		random[i] = rand() % 100;
	}

	int count = sizeof(random) / sizeof(int);

	line_up(random, count);

	for (int i = 0; i < 11; i++)
	{
		printf("%d\n", random[i]);
	}
	return 0;
	
}

int line_up(int* a, int count)
{
	int temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (*(a + i) > * (a + j))
			{
				temp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = temp;
			}
		}
	}
}