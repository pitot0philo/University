#include <Stdio.h>

int sum(int a);

int main(void)
{
	sum(10);
	sum(100);
	return 0;
}

int sum(int a)
{
	int temp = 0;
	for (int i = 1; i <= a; i++)
	{
		temp += i;
	}
	printf("Sigma from 1 to %d is %d.\n", a, temp);

	return 0;
}