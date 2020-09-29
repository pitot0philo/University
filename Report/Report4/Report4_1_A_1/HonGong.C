#include <stdio.h>

int main(void)
{
	int a;
	printf("input integer variable :");
	scanf("%d", &a);
	while (a < 0)
	{
		a = -a;
	}
	printf("a : %d\n", a);

	return 0;