#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1. 난수생성기 등록
//2. 앞1/뒷0면 정의
//3. 난수생성기를 통해 앞/뒷면 결정
//4. 성공 혹은 실패는 if문으로 판별
//5. continue는 while(1)로 무한반복

int coin_toss(void);

int main(void)
{
	int plyr_coin;
	char plyr_cont;

	while (1)
	{
		printf("Front of back?(1 or 0) : ");
		scanf("%d", &plyr_coin);
		{
			if (plyr_coin == coin_toss())
				printf("Correct!!\n");
			else
				printf("Wrong!!\n");
		}
		printf("Want to continue? (y or n) : ");
		getchar();
		scanf("%c", &plyr_cont);
		{
			if (plyr_cont == 'y')
				continue;
			else if (plyr_cont == 'n')
				break;
		}
	}

	return 0;
}

	int coin_toss(void)
{
	int com_coin;
	srand((unsigned)time(NULL));
	com_coin = rand() % 2;
	return com_coin;
}