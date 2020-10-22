#include <stdio.h>

void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main(void)
{
	double max, mid, min;

	printf("enter the three real numbers : ");
	scanf("%lf %lf %lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("print lined numbers : %.1lf %.1lf %.1lf", max, mid, min);

	return 0;
}

void swap(double* pa, double* pb)
{
	double temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double* maxp, double* midp, double* minp)
{
	for (int i = 0; i <= 10; i++)
	{
		if (*maxp < *midp)
		{
			swap(maxp, midp);
		}
		else if (*maxp < *minp)
		{
			swap(maxp, minp);
		}
		else if (*midp < *minp)
		{
			swap(midp, minp);
		}
	}
}