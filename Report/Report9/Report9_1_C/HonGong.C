#include <stdio.h>
#include <String.h>

int main(void)
{
	char str[80];
	char exc_str[80];
	char* star = "**************";
	int length;
	printf(" enter the word : \n");

	scanf("%s", str);

	length = strlen(str);
	if (length <= 5)
	{
		strcpy(exc_str, str);
	}
	else
	{
		strcpy(exc_str, str, 5);
		exc_str[5] = '\0';
		strncat(exc_str, star, length - 5);
	}

	printf("entered word : %s , excepted word : %s\n", str, exc_str);

	return 0;
}