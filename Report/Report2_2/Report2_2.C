#include <stdio.h>
#include <math.h>
int main(void)
{
	double weight;
	double height;
	double c, d, e;

	printf("몸무게(kg)와 키(cm)를 입력");
	scanf("%lf%lf", &weight, &height);
	
	c = height / 100;
	d = powf(c, 2);
	e = weight / d;
	printf("몸무게는 %lf kg, 키는 %.2lf m이다. BMI 지수는 %.3lf이다", weight, c, e);
	return 0;
}