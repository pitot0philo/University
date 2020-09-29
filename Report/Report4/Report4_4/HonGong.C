#include <stdio.h>

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
	return 0;
}