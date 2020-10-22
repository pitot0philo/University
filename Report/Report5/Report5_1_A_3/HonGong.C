#include <stdio.h>
double centi_to_meter(double a);

int main(void)
{
	double res;

	res = centi_to_meter(187);
	printf("%.2lfm\n", res);

	return 0;
}

double centi_to_meter(double a)
{
	double temp;
	temp = a / 100;
	return (temp);
}