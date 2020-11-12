#include <stdio.h>
#include <string.h>

void swap(char* type, void* a, void* b);

int main(void)
{
	int age1, age2;
	double height1, height2;

	printf("enter the age and height of 1st person : ");
	scanf("%d%lf", &age1, &height1);
	printf("enter the age and height of 2nd person : ");
	scanf("%d%lf", &age2, &height2);

	swap("int", &age1, &age2);
	swap("double", &height1, &height2);

	printf("\nage and height of 1st person is %d, %.2lf\n", age1, height1);
	printf("age and height of 2nd person is %d, %.2lf\n", age2, height2);

	return 0;
}

void swap(char* type, void* a, void* b)
{
	int temp;
	double dtemp;

	if (strcmp(type, "int") == 0)
	{
		temp = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = temp;
	}
	else if(strcmp(type, "double") == 0)
	{
		dtemp = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = dtemp;
	}
}
