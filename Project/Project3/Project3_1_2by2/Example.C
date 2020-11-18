#include <Stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
	int i, j, k, m;
	int matrix1[2][2];
	int matrix2[2][2];
	int add_matrix[2][2];
	int subt_matrix[2][2];
	int mult_matrix[2][2];
	int trans_matrix1[2][2];
	int trans_matrix2[2][2];

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

	printf("matrix 1 is : \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d  ", matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("matrix 2 is : \n");
	for (k = 0; k < 2; k++)
	{
		for (m = 0; m < 2; m++)
		{
			printf("%d  ", matrix2[k][m]);
		}
		printf("\n");
	}
	//Çà·ÄÀÇ µ¡¼À: a11+b11 a12+b12 a13+b13//a21+b21 a22+b22 a23+b23//a31+b31 a32+b32 a33+b33
	printf("\naddition of matrix 1 and matrix 2 is : \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			add_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
			printf("%d  ", add_matrix[i][j]);
		}
		printf("\n");
	}

	//Çà·ÄÀÇ »¬¼À: a11-b11 a12-b12 a13-b13//a21-b21 a22-b22 a23-b23//a31-b31 a32-b32 a33-b33
	printf("\nSubtraction of matrix 1 and matrix 2 is : \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			subt_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
			printf("%d  ", subt_matrix[i][j]);
		}
		printf("\n");
	}

	printf("\nmultiply of matrix 1 and matrix 2 is : \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			mult_matrix[i][j] = 0;
			for (k = 0; k < 2; k++)
			{
				mult_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			printf("%d  ", mult_matrix[i][j]);
		}
		printf("\n");
	}

	printf("\ntranspose of matrix 1 is : \n");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			trans_matrix1[i][j] = matrix1[j][i];
			printf("%d  ", trans_matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\ntranspose of matrix 2 is : \n");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			trans_matrix2[i][j] = matrix2[j][i];
			printf("%d  ", trans_matrix2[i][j]);
		}
		printf("\n");
	}

	printf("\nInverse of matrix 1 is : \n");

	double inv_matrix1[2][2];
	double det_matrix1;
	det_matrix1 = matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if ((i+1)%2 != (j+1)%2)
			{
				inv_matrix1[i][j] = -matrix1[(j + 1) % 2][(i + 1) % 2] / det_matrix1;
			}
			else
			{
				inv_matrix1[i][j] = matrix1[(j + 1) % 2][(i + 1) % 2] / det_matrix1;
			}
			printf("%.4lf  ", inv_matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\nInverse of matrix 2 is : \n");

	double inv_matrix2[2][2];
	double det_matrix2;
	det_matrix2 = matrix2[0][0] * matrix2[1][1] - matrix2[0][1] * matrix2[1][0];

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if ((i + 1) % 2 != (j + 1) % 2)
			{
				inv_matrix2[i][j] = -matrix2[(j + 1) % 2][(i + 1) % 2] / det_matrix2;
			}
			else
			{
				inv_matrix2[i][j] = matrix2[(j + 1) % 2][(i + 1) % 2] / det_matrix2;
			}
			printf("%.4lf  ", inv_matrix2[i][j]);
		}
		printf("\n");
	}

	return 0;
}