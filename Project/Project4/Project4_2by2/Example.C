#include <Stdio.h>
#include <time.h>
#include <stdlib.h>

void printmatrix1(double(*MatArry)[2], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%.4lf   ", MatArry[i][j]);
		}
		printf("\n");
	}
}

void print_addmatrix(double(*MatArry1)[2], double(*MatArry2)[2], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%.4lf  ", MatArry1[i][j] + MatArry2[i][j]);
		}
		printf("\n");
	}
}

void print_submatrix(double(*MatArry1)[2], double(*MatArry2)[2], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%.4lf  ", MatArry1[i][j] - MatArry2[i][j]);
		}
		printf("\n");
	}
}

void print_multmatrix(double(*MatArry1)[2], double(*MatArry2)[2], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%.4lf  ", MatArry1[i][0]*MatArry2[0][j]+MatArry1[i][1]*MatArry2[1][j]);
		}
		printf("\n");
	}
}

void print_trans(double(*MatArry)[2], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%.4lf  ", MatArry[j][i]);
		}
		printf("\n");
	}
}

void print_inver(double(*MatArry)[2], int col, int row)
{
	double Det = 0;
	Det = MatArry[0][0] * MatArry[1][1] - MatArry[0][1] * MatArry[1][0];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i + 1) % 2 != (j + 1) % 2)
			{
				printf("%.4lf  ", -MatArry[(j + 1) % 2][(i + 1) % 2] / Det);
			}
			else
			{
				printf("%.4lf  ", MatArry[(j + 1) % 2][(i + 1) % 2] / Det);
			}
		}
		printf("\n");
	}
}
int main(void)
{
	int i, j, k, m;
	double matrix1[2][2];
	double matrix2[2][2];

	srand((unsigned)time(NULL));

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			matrix1[i][j] = rand() % 100;
		}
	}

	for (k = 0; k < 2; k++)
	{
		for (m = 0; m < 2; m++)
		{
			matrix2[k][m] = rand() % 100;
		}
	}

	int col = sizeof(matrix1[0]) / sizeof(double);
	int row = sizeof(matrix1) / sizeof(matrix1[0]);

	printf("matrix1 is : \n");
	printmatrix1(matrix1, col, row);
	printf("\n");
	printf("matrix 2 is : \n");
	printmatrix1(matrix2, col, row);

	//Çà·ÄÀÇ µ¡¼À:
	printf("\naddition of matrix 1 and matrix 2 is : \n");
	print_addmatrix(matrix1, matrix2, col, row);

	//Çà·ÄÀÇ »¬¼À: a11-b11 a12-b12 a13-b13//a21-b21 a22-b22 a23-b23//a31-b31 a32-b32 a33-b33
	printf("\nSubtraction of matrix 1 and matrix 2 is : \n");
	print_submatrix(matrix1, matrix2, col, row);

	//Çà·ÄÀÇ °ö¼À
	printf("\nmultiply of matrix 1 and matrix 2 is : \n");
	print_multmatrix(matrix1, matrix2, col, row);

	//Çà·ÄÀÇ ÀüÄ¡
	printf("\ntranspose of matrix 1 is : \n");
	print_trans(matrix1, col, row);

	printf("\ntranspose of matrix 2 is : \n");
	print_trans(matrix2, col, row);

	//¿ªÇà·Ä
	printf("\nInverse of matrix 1 is : \n");
	print_inver(matrix1, col, row);

	printf("\nInverse of matrix 2 is : \n");
	print_inver(matrix2, col, row);

	return 0;
}