#include <stdio.h>

int main(void)
{
	char ch;

	printf("문자 입력 : ");
	scanf("%c", &ch);
	printf("%c문자의 아스키코드 값은 %d입니다.", ch, (int)ch);
	return 0;
}