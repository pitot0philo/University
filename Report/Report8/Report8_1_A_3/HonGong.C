#include <Stdio.h>

int main(void)
{

	char mark1[5][5] = { 0 };
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i == j) mark1[i][j] = 'X';
		}
	}

	char mark2[5][5] = { 0 };
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if ((i == j) || (i == (4 - j))) mark2[i][j] = 'X';
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (mark1[i][j] != 0) printf("%c", mark1[i][j]);
			else printf(" ");

			if (j + 1 == 5) printf("\n");
		}
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++ )
		{
			if (mark2[i][j] != 0) printf("%c", mark2[i][j]);
			else printf(" ");

			if (j + 1 == 5) printf("\n");
		}
	}

	return 0;
}