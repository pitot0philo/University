#include <stdio.h>

int main(void)
{
	int row, star, i, j;
	printf("Enter the number of rows and stars: ");
	scanf("%d%d", &row, &star);
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < (star / row); j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}