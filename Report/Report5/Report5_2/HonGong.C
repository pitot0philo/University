#include <stdio.h>

int rec_func(int n);

int main(void)
{
	int max;
	printf("enter the maximum number : ");
	scanf("%d", &max);
	printf("Sigma from 1 to %d is %d\n", max, rec_func(max));

	return 0;
}

int rec_func(int n)
{
	if (n <= 0)
		return 0;
	return n + rec_func(n - 1);
}