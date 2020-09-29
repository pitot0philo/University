#include <stdio.h>

int main(void)
{
	int row, star, i, j;
	printf("Enter the number of rows and stars: ");
	scanf("%d%d", &row, &star);

	if (row > star)
	{
		printf("Invaild Value!");
	}
	else if ((star % row) == 0)
	{
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < (star / row); j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	else
	{
		printf("not now...");
	}
	return 0;
}