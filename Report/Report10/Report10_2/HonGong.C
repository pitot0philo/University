#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	char name[20];
	int snum;
	double sKor;
	double sEng;
	double sMath;
	double Avg;
	double Tot;
	char grade;

}Student;

void swap(Student* arr, int a, int b)
{
	Student temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void sort(Student* arr, int m, int n)
{
	if (m < n)
	{
		int temp = m;
		int i = m + 1;
		int j = n;

		while (i <= j)
		{
			while (i <= j && arr[i].Tot >= arr[temp].Tot)
				i++;
			while (j > m && arr[j].Tot <= arr[temp].Tot)
				j--;
			if (i > j)
				swap(arr, j, temp);
			else
				swap(arr, i, j);
		}

		sort(arr, m, j - 1);
		sort(arr, j + 1, n);
	}
}

int main(void)
{
	struct Student list[5];

	for (int i = 0; i < 5; i++)
	{
		printf("Student number : ");
		scanf("%d", &list[i].snum);
		printf("Student name : ");
		scanf("%s", &list[i].name);
		printf("Korean, English, Math score : ");
		scanf("%lf%lf%lf", &list[i].sKor, &list[i].sEng, &list[i].sMath);
	}

	for (int i = 0; i < 5; i++)
	{
		list[i].Tot = list[i].sKor + list[i].sEng + list[i].sMath;
		list[i].Avg = ((list[i].sKor + list[i].sEng + list[i].sMath) / 3);
	}

	int count = 0;
	count = sizeof(list) / sizeof(int);


	for (int i = 0; i < 5; i++)
	{
		if (list[i].Avg >= 70 && list[i].Avg < 80)
		{
			list[i].grade = 'C';
		}
		else if (list[i].Avg >= 80 && list[i].Avg < 90)
		{
			list[i].grade = 'B';
		}
		else if (list[i].Avg > 90)
		{
			list[i].grade = 'A';
		}
		else
		{
			list[i].grade = 'F';
		}
	}

	printf("\n#Data before line_up\n");


	for (int i = 0; i < 5; i++)
	{
		printf("\n%5d  %s  %.0lf  %.0lf  %.0lf  %.0lf  %.2lf%5c", list[i].snum, list[i].name, list[i].sKor, list[i].sEng, list[i].sMath, list[i].Tot, list[i].Avg, list[i].grade);
	}

	sort(list, 0, 4);

	printf("\n\n#Data after line_up\n");

	for (int i = 0; i < 5; i++)
	{
		printf("\n%5d  %s  %.0lf  %.0lf  %.0lf  %.0lf  %.2lf%5c", list[i].snum, list[i].name, list[i].sKor, list[i].sEng, list[i].sMath, list[i].Tot, list[i].Avg, list[i].grade);
	}
	return 0;
}