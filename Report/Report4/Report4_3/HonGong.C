#include <stdio.h>

int main(void)
{
	int row, star, i, j, k;
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
	else if ((star % row) != 0)
	{
		for (i = 0; i < (row - 1); i++)
		{
			for (j = 0; j < ((star / row)+1); j++)
			{
				printf("*");
			}
		printf("\n");
		}

		k = 0; 
		while (k < (star-((row-1)*((star/row)+1))))
		{
			printf("*");
			k++;
		}
	}
	return 0;
}