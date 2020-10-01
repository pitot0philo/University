#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b;
	printf("input real number angle value : ");
	scanf("%lf", &a);

	b = fmod((a + 180), 360) - 180;

	printf("%lf", b);
	return 0;

}