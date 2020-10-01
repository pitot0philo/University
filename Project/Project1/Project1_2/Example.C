#include <stdio.h>

int main(void)
{
	int a;
	printf("Enter month : ");
	scanf("%d", &a);

	//12월, 1월, 2월 겨울
	//3월, 4월, 5월 봄
	//6월, 7월, 8월 여름
	//9월 10월 11월 가을
	if (a > 12 || a < 0)
	{
		printf("Invaild Value!");
	}
	else
	{
		if (a <= 5 && a >= 3)
		{
			printf("Spring");
		}
		else if (a <= 8 && a >= 6)
		{
			printf("Summer");
		}
		else if (a <= 11 && a >= 9)
		{
			printf("Autumn");
		}
		else
		{
			printf("Winter");
		}
	}

	return 0;
}