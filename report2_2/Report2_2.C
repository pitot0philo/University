#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	double weight;
	double height;
	double c, d, bmi;

	printf("몸무게(kg)와 키(cm)를 입력");
	scanf("%lf%lf", &weight, &height);
	
	c = height / 100;
	d = powf(c, 2);
	bmi = weight / d;
	
	if (20 <= bmi && bmi <= 25)
		printf("표준입니다.");
	else
		printf("체중관리가 필요합니다.");
	system("pause>null");

	return 0;
}