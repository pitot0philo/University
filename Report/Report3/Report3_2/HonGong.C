#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	int b;
	char sign = 0;

	printf("사칙연산 입력(정수) : ");
	scanf("%d%c%d", &a, &sign, &b);

	if (sign == '+')
	{
		printf("%d%c%d=%d", a, sign, b, a + b);
	}
	else if (sign == '-')
	{
		printf("%d%c%d=%d", a, sign, b, a - b);
	}
	else if (sign == '*')
	{
		printf("%d%c%d=%d", a, sign, b, a * b);
	}
	else if (sign == '/')
	{
		printf("%d%c%d=%d", a, sign, b, a / b);
	}
	else
	{
		printf("invailed value!");
	}

	system("pause>=null\n");
	return 0;
}