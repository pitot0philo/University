#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE* ap;
	FILE* bp;
	FILE* cp;
	char str_a[200];
	char* ret_a;
	char str_b[200];
	char* ret_b;

	ap = fopen("a.txt", "r");
	if (ap == NULL)
	{
		printf("fail to open the file\n");
		return 1;
	}
	bp = fopen("b.txt", "r");
	if (bp == NULL)
	{
		printf("fail to open the file\n");
		return 1;
	}
	cp = fopen("c.txt", "w");
	if (cp == NULL)
	{
		printf("fail to open the writing file\n");
		return 1;
	}

	for (int i = 0; i < 10; i++)
	{
		ret_b = fgets(str_b, sizeof(str_b), bp);
		for (int i = 0; i < 10; i++)
		{
			ret_a = fgets(str_a, sizeof(str_a), ap);
			if (ret_a == NULL)
			{
				break;
			}
			if (ret_a == ret_b)
			{
				break;
			}
		}
		if()
	}
	printf("\nCopy done.\n");

	fclose(ap);
	fclose(bp);
	fclose(cp);

	return 0;
}