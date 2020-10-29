#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//난수생성기 입력 및 중복 제거
int main(void)
{
	int answer = 0;
	while (1)
	{
		int com_number[5];//컴퓨터가 사용할 숫자를 배열에 입력
		srand((unsigned)time(NULL));
		int temp;//나온 랜덤넘버를 임시 저장
		for (int i = 0; i < 4; i++)
		{
			temp = rand() % 10;
			com_number[i] = temp;

			for (int j = 0; j < i; j++)//중복되는 숫자 제거
			{
				if (temp == com_number[j] && i != j)
				{
					i--;
				}
			}

			for (int j = 0; j < i; j++)//0 제거
			{
				if (0 == com_number[j] && i != j)
				{
					i--;
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			//printf("*");//랜덤넘버 저장 및 암호화 출력
			printf("%d", com_number[i]);
		}
		int count = 1;

			//9회차까지 반복

		int plyr_number[5];
		while (1)
		{
			printf("\ngame No. %d\n", count);//n회차 게임을 입력받는 코드
			while (1)//범위 내의 숫자만 입력받는 코드
			{
				printf("enter the number from 1 to 9 : ");
				scanf("%d %d %d %d", &plyr_number[0], &plyr_number[1], &plyr_number[2], &plyr_number[3]);

				if (plyr_number[0] < 0 || plyr_number[0]>9 || plyr_number[1] < 0 || plyr_number[1]>9 || plyr_number[2] < 0 || plyr_number[2]>9 || plyr_number[3] < 0 || plyr_number[3]>9)
				{
					printf("numbers can only be entered in the range of 0 to 9!!\n");
					continue;
				}
				else if (plyr_number[1] == plyr_number[0] || plyr_number[2] == plyr_number[0] || plyr_number[3] == plyr_number[0] || plyr_number[1] == plyr_number[2] || plyr_number[1] == plyr_number[3] || plyr_number[2] == plyr_number[3])
				{
					printf("overlaped numbers can not be entered!!\n");
					continue;
				}
				break;
			}

			int ball = 0, strike = 0, out = 0;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (com_number[i] == plyr_number[j])
					{
						if (i == j)
						{
							strike++;
						}
						else if (i != j)
						{
							ball++;
						}
					}
				}
			}
			if (ball == 0 && strike == 0)
			{
				out += 1;
			}
			printf("ball : %d, strike : %d, out: %d\n", ball, strike, out);
			if (strike == 4)
			{
				printf("\nyou won!!\n");
				break;
			}
			else if (count == 9)
			{
				printf("\nyou lose... answer was %d %d %d %d\n", com_number[0], com_number[1], com_number[2], com_number[3]);
				break;
			}

			count++;
		}

		printf("want to play again? : <1> Yes <2> No\n");
		scanf("%d", &answer);

		if (answer == 1)
			continue;
		else if (answer == 2)
			break;
	}
	return 0;
}







