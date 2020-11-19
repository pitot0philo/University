#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double* pmem;
	int size = 5;
	int count = 0;
	double realnum;
	double sum = 0;

	pmem = (double*)calloc(size, sizeof(double));
	while (1)
	{
		printf("enter the real number : ");
		scanf("%lf", &realnum);
		if (realnum == -1) break;
		if (count == size)
		{
			size += 5;
			pmem = (double*)realloc(pmem, size * sizeof(double));
		}
		pmem[count++] = realnum;
	}
	for(int i=0;i<count;i++)
	{
		sum += pmem[i];
	}

	printf("\n%.4lf ", sum);
	free(pmem);

	return 0;
}