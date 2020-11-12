#include <stdio.h>

int main(void)
{
	char a[4][10] = { "horse","fox","hipo","tiger" };//a[0][0~4]에 horse 저장, a[1][0~2]에 fox 저장, a[2][0~3]에 hipo 저장, a[3][0~4]에 tiger 저장
	char* pa[] = { a[0],a[1],a[2],a[3] };//pa 포인터에 a 2차원배열 그대로 저장
	int count;
	int i;
	count = sizeof(pa) / sizeof(pa[0]);
	for (i = 0; i < count; i++)
	{
		printf("%c", pa[i][i]);//저장된 pa 배열을 가져와서 출력. 이때 pa[0][0]=h, pa[1][1]=o, pa[2][2]=p, pa[3][3]=e
	}

	return 0;
}