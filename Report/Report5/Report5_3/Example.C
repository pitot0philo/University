#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1. ���������� ���
//2. ��1/��0�� ����
//3. ���������⸦ ���� ��/�޸� ����
//4. ���� Ȥ�� ���д� if������ �Ǻ�
//5. continue�� while(1)�� ���ѹݺ�

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