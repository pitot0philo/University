#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int a, b;
	printf("���� �ΰ��� �Է�:");
	scanf("%d%d", &a, &b);
	
	printf("���� : %d\n", a + b);
	printf("���� : %d\n", a - b);
	printf("���� : %d\n", a * b);
	if (b != 0)//�и� 0�� ���� �ʰ� ����
		printf("������ : %d / %d=%.4f", a, b, a / (float)b);
		
	system("pause>null");
	return 0;
}