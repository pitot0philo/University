#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int a, b;
	printf("Á¤¼ö µÎ°³¸¦ ÀÔ·Â:");
	scanf("%d%d", &a, &b);
	
	printf("µ¡¼À : %d\n", a + b);
	printf("»¬¼À : %d\n", a - b);
	printf("°ö¼À : %d\n", a * b);
	if (b != 0)//ºÐ¸ð°¡ 0ÀÌ µÇÁö ¾Ê°Ô ¹æÁö
		printf("³ª´°¼À : %d / %d=%.4f", a, b, a / (float)b);
		
	system("pause>null");
	return 0;
}