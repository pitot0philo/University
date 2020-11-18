#include <Stdio.h>
#include <time.h>
#include <stdlib.h>

void printmat(double(*MatArry)[3], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%.4lf  ", MatArry[i][j]);
		}
		printf("\n");
	}
}

void print_addmat(double(*MatArry1)[3],double(*MatArry2)[3], int col, int row)
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

void print_submat(double(*MatArry1)[3], double(*MatArry2)[3], int col, int row)
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

void print_Mult(double(*MatArry1)[3], double(*MatArry2)[3], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%.4lf  ", MatArry1[i][0] * MatArry2[0][j] + MatArry1[i][1] * MatArry2[1][j] + MatArry1[i][2] * MatArry2[2][j]);
		}
		printf("\n");
	}
}

void print_trans(double(*MatArry)[3], int col, int row)
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

void print_inver(double(*MatArry)[3], int col, int row)
{
	double det = 0;
	det= MatArry[0][0] * (MatArry[1][1] * MatArry[2][2] - MatArry[2][1] * MatArry[1][2]) -
		MatArry[0][1] * (MatArry[1][0] * MatArry[2][2] - MatArry[1][2] * MatArry[2][0]) +
		MatArry[0][2] * (MatArry[1][0] * MatArry[2][1] - MatArry[1][1] * MatArry[2][0]);

	double Trans_Arry[3][3];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Trans_Arry[i][j] = MatArry[j][i];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%.4lf  ", 1.0 / det * (Trans_Arry[(i + 1) % 3][(j + 1) % 3] * Trans_Arry[(i + 2) % 3][(j + 2) % 3] - Trans_Arry[(i + 1) % 3][(j + 2) % 3] * Trans_Arry[(i + 2) % 3][(j + 1) % 3]));
		}
		printf("\n");
	}
}


int main(void)
{
	double matrix1[3][3];
	double matrix2[3][3];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix1[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix2[i][j] = rand() % 100;
		}
	}

	int col = sizeof(matrix1[0]) / sizeof(double);
	int row = sizeof(matrix1) / sizeof(matrix1[0]);

	printf("matrix 1 is : \n");
	printmat(matrix1, col, row);
	printf("\n");

	printf("matrix 2 is : \n");
	printmat(matrix2, col, row);

	//Çà·ÄÀÇ µ¡¼À
	printf("\naddition of matrix 1 and matrix 2 is : \n");
	print_addmat(matrix1, matrix2, col, row);
	printf("\n");

	//Çà·ÄÀÇ »¬¼À
	printf("\nSubtraction of matrix 1 and matrix 2 is : \n");
	print_submat(matrix1, matrix2, col, row);
	printf("\n");

	//Çà·ÄÀÇ °ö¼À
	printf("\nmultiply of matrix 1 and matrix 2 is : \n");
	print_Mult(matrix1, matrix2, col, row);
	printf("\n");

	//Çà·ÄÀÇ ÀüÄ¡
	printf("\ntranspose of matrix 1 is : \n");
	print_trans(matrix1, col, row);
	printf("\n");

	printf("\nTranspose of matrix 2 is : \n");
	print_trans(matrix2, col, row);
	printf("\n");

	//¿ªÇà·Ä
	printf("\nInverse of matrix 1 is : \n");
	print_inver(matrix1, col, row);

	printf("\nInverse of matrix 2 is : \n");
	print_inver(matrix2, col, row);

	return 0;
}