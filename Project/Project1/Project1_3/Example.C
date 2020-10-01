#include <stdio.h>

int main(void)
{
	int a;
	printf("Enter year that you want to know : ");
	scanf("%d", &a);

	if (a % 4 == 0)
	{
		printf("%d is leap year", a);
	}
	else if (a % 100 == 0)
	{
		printf("%d is leap year", a);
	}
	else if (a % 400 == 0)
	{
		printf("%d is leap year", a);
	}
	else
	{
		printf("%d is not leap year", a);
	}

	return 0;
}