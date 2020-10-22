#include <stdio.h>
#include <math.h>


double Euclid_Dist(double x1, double y1, double x2, double y2);

int main(void)
{
	double x1, y1, x2, y2;

	printf("First point : ");
	scanf("%lf %lf", &x1, &y1);

	printf("Second point : ");
	scanf("%lf %lf", &x2, &y2);

	printf("Euclidean Distance : %lf", Euclid_Dist(x1, y1, x2, y2));

	return 0;
}

double Euclid_Dist(double x1, double y1, double x2, double y2)
{
	return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}