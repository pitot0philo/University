#include <Stdio.h>

double average(double a, double b)
{
	double temp;
	temp = a + b;
	return(temp / 2.0);
}

int main(void)
{
	double res;
	res = average(1.5, 3.4);

	printf("%lf", res);

	return 0;
}
