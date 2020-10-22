#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, i;
	int sum = 0;

	printf("Enter two integer Variable : ");
	scanf("%d%d", &a, &b);
	
	for (i = a; i <= b; i++)
	{
		sum += i;
	}

	printf("sigma from a to b is %d", sum);

	system("pause>null\n");

	return 0;
}