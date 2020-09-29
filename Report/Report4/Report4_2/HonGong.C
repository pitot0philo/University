#include <stdio.h>

int main(void)
{
	int max;
	int i, j, k=0;
	printf("Input integer value more than 2 : ");
	scanf("%d", &j);

	//1. 소수라고 가정한다.
	//2. 2부터 정수보다 하나 작은 수로도 나눠떨어지면 취소한다
	//3. 1의 가정이 거부되지 않으면 출력한다

		for (max = 2; max <= j; max++)
		{
			for (i = 2; i < max; i++)
			{
				if (max % i == 0) break;
			}
			if (max == i)
			{
				printf("%5d", max);
				k++;
			if (k % 5 == 0)
				puts("");
			}
		}
	return 0;
}