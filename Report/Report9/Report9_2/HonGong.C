#include <stdio.h>
#include <string.h>

int main(void)
{
	char word;
	int count = 0, temp = 0;
	int ret;

	printf("Enter the word that you want to compare the length : ");

	while (1)
	{
		ret = scanf("%c", &word);
		if (ret == -1) break;
		if (word != '\n')
		{
			count++;
		}
		else
		{
			if (temp < count)
				temp = count;
			count = 0;
		}
	}

	printf("the longist word is : %d", temp);

	return 0;
}