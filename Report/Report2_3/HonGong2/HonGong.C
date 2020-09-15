#include <stdio.h>
#include <math.h>

int main(void)
{
	int a, b;
	printf("정수 두개를 입력:");
	scanf("%d%d", &a, &b);
	
	if (b != 0)//분모가 0이 되지 않게 방지
		printf("%d / %d=%f", a, b, a / b);
		
		return 0;
}