#include <stdio.h>
#include <math.h>//powf ���ɾ� ����� ����
#include <stdlib.h>//system ���ɾ� ����� ����

int main(void)
{
	double weight;
	double height;
	double c, d, bmi;

	printf("������(kg)�� Ű(cm)�� �Է� : ");
	scanf("%lf%lf", &weight, &height);
	
	c = height / 100;
	d = powf(c, 2);
	bmi = weight / d;
	
	if (20 <= bmi && bmi <= 25)
		printf("ǥ���Դϴ�.");
	else
		printf("ü�߰����� �ʿ��մϴ�.");
	system("pause>null");

	return 0;
}