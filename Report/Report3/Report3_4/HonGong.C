#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b;
	printf("Input two integer Variables : ");
	scanf("%d%d", &a, &b);

	int c = 0;
	c = b % a;

	if (c == 0)
	{
		printf("%d is divisor of %d", a, b);
	}
	else
	{
		printf("%d is not divisor of %d", a, b);
	}

	system("pause>null\n");

	return 0;
}