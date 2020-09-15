#include <stdio.h>
int main(void)
{
	int a;
	double b;
	printf("몸무게(kg)와 키(cm)를 입력:");
	scanf("%d%lf", &a, &b);
	printf("입력된 값: %d%lf\n", a, b);

	return 0;
}