#include <stdio.h>

int main(void)
{
	int a;
	printf("Enter month : ");
	scanf("%d", &a);

	//1월, 2월, 3월 겨울
	//4월, 5월, 6월 봄
	//7월, 8월, 9월 여름
	//10월 11월 12월 가을
	if (a > 12 || a < 0)
	{
		printf("Invaild Value!");
	}
	else
	{
		if (a <= 3 && a >= 1)
		{
			printf("Winter");
		}
		else if (a <= 6 && a >= 4)
		{
			printf("Spring");
		}
		else if (a <= 9 && a >= 7)
		{
			printf("Summer");
		}
		else
		{
			printf("Fall");
		}
	}

	return 0;
}