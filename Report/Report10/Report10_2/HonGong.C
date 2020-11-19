#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	char name[20];
	int snum;
	int sKor;
	int sEng;
	int sMath;
	double Avg;
	int Tot;
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
		scanf("%d%d%d", &list[i].sKor, &list[i].sEng, &list[i].sMath);
	}

	for (int i = 0; i < 5; i++)
	{
		list[i].Tot = list[i].sKor + list[i].sEng + list[i].sMath;
		list[i].Avg = ((list[i].sKor + list[i].sEng + list[i].sMath) / 3);
	}

	int count = 0;
	count = sizeof(list) / sizeof(int);

	char grade[5];

	for (int i = 0; i < 5; i++)
	{
		if (list[i].Avg >= 70 && list[i].Avg < 80)
		{
			grade[i] = 'C';
		}
		else if (list[i].Avg >= 80 && list[i].Avg < 90)
		{
			grade[i] = 'B';
		}
		else if (list[i].Avg > 90)
		{
			grade[i]='A';
		}
		else
		{
			grade[i] = 'F';
		}
	}

	printf("\n#Data before line_up\n");


	for (int i = 0; i < 5; i++)
	{
		printf("\n%5d%10s%5d%5d%5d%7d%7lf%7c", list[i].snum, list[i].name, list[i].sKor, list[i].sEng, list[i].sMath, list[i].Tot, list[i].Avg, grade[i]);
	}

	sort(list, 0, 4);

	printf("\n#Data after line_up\n");

	for (int i = 0; i < 5; i++)
	{
		printf("\n%5d%10s%5d%5d%5d%7d%7lf%7c", list[i].snum, list[i].name, list[i].sKor, list[i].sEng, list[i].sMath, list[i].Tot, list[i].Avg, grade[i]);
	}
	return 0;
}