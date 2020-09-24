#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b;
	printf("Input 2 integer variable  : ");
	scanf("%d%d", &a, &b);

	if (a % 2 == 0 && b % 2 == 0)
	{
		printf("%d and %d are all even number", a, b);
	}
	else if (a % 2 == 0 && b % 2 != 0)
	{
		printf("%d is even number but %d is odd number", a, b);
	}
	else if (a % 2 != 0 && b % 2 == 0)
	{
		printf("%d is even number but %d is odd number", b, a);
	}
	else
	{
		printf("%d and %d are all odd number", a, b);
	}

	system("pause>null\n");

	return 0;
}

//if-else 단독으로 사용한 것은, a,b를 모두 평가해야 하는데, a는 0이 아니고, b는 0이거나 혹은 그 반대의 경우에는 switch 구문으로
//나타내기 힘들다는 문제가 생긴다. 이에 의해서 && 연산자로 단순히 나타낼 수 있는 if-else를 단독으로 사용하였다.