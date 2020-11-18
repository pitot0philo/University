#include <Stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
	int i, j, k, m;
	double matrix1[3][3];
	double matrix2[3][3];
	double add_matrix[3][3];
	double subt_matrix[3][3];
	double mult_matrix[3][3];
	double trans_matrix1[3][3];
	double trans_matrix2[3][3];

	srand((unsigned)time(NULL));

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			matrix1[i][j] = rand() % 100;
		}
	}

	for (k = 0; k < 3; k++)
	{
		for (m = 0; m < 3; m++)
		{
			matrix2[k][m] = rand() % 100;
		}
	}

	printf("matrix 1 is : \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%.4lf  ", matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("matrix 2 is : \n");
	for (k = 0; k < 3; k++)
	{
		for (m = 0; m < 3; m++)
		{
			printf("%.4lf  ", matrix2[k][m]);
		}
		printf("\n");
	}
	//행렬의 덧셈: a11+b11 a12+b12 a13+b13//a21+b21 a22+b22 a23+b23//a31+b31 a32+b32 a33+b33
	printf("\naddition of matrix 1 and matrix 2 is : \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			add_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
			printf("%.4lf  ", add_matrix[i][j]);
		}
		printf("\n");
	}

	//행렬의 뺄셈: a11-b11 a12-b12 a13-b13//a21-b21 a22-b22 a23-b23//a31-b31 a32-b32 a33-b33
	printf("\nSubtraction of matrix 1 and matrix 2 is : \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			subt_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
			printf("%.4lf  ", subt_matrix[i][j]);
		}
		printf("\n");
	}

	printf("\nmultiply of matrix 1 and matrix 2 is : \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			mult_matrix[i][j] = 0;
			for (k = 0; k < 3; k++)
			{
				mult_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			printf("%.4lf  ", mult_matrix[i][j]);
		}
		printf("\n");
	}

	printf("\ntranspose of matrix 1 is : \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			trans_matrix1[i][j] = matrix1[j][i];
			printf("%.4lf  ", trans_matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\nTranspose of matrix 2 is : \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			trans_matrix2[i][j] = matrix2[j][i];
			printf("%.4lf  ", trans_matrix2[i][j]);
		}
		printf("\n");
	}

	//역행렬: 전치행렬/행렬식: 행렬식이 0이면 전치행렬 없다고 선언 필요

	printf("\nInverse of matrix 1 is : \n");

	double det_matrix1;
	double inv_matrix1[3][3];

	det_matrix1 = matrix1[0][0] * (matrix1[1][1] * matrix1[2][2] - matrix1[2][1] * matrix1[1][2]) -
		matrix1[0][1] * (matrix1[1][0] * matrix1[2][2] - matrix1[1][2] * matrix1[2][0]) +
		matrix1[0][2] * (matrix1[1][0] * matrix1[2][1] - matrix1[1][1] * matrix1[2][0]);

	if (det_matrix1 == 0)
	{
		printf("Inverse of matrix 1 is not exist!! \n");
		return 0;
	}
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			inv_matrix1[i][j] = 1.0 / det_matrix1 * (trans_matrix1[(i + 1) % 3][(j + 1) % 3] * trans_matrix1[(i + 2) % 3][(j + 2) % 3] - trans_matrix1[(i + 1) % 3][(j + 2) % 3] *trans_matrix1[(i + 2) % 3][(j + 1) % 3]);
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%.4lf  ", inv_matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\nInverse of matrix 2 is : \n");

	double det_matrix2;
	double inv_matrix2[3][3];

	det_matrix2 = matrix2[0][0] * (matrix2[1][1] * matrix2[2][2] - matrix2[2][1] * matrix2[1][2]) -
		matrix2[0][1] * (matrix2[1][0] * matrix2[2][2] - matrix2[1][2] * matrix2[2][0]) +
		matrix2[0][2] * (matrix2[1][0] * matrix2[2][1] - matrix2[1][1] * matrix2[2][0]);

	if (det_matrix2 == 0)
	{
		printf("Inverse of matrix 1 is not exist!! \n");
		return 0;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			inv_matrix2[i][j] = 1.0 / det_matrix2 * (trans_matrix2[(i + 1) % 3][(j + 1) % 3] * trans_matrix2[(i + 2) % 3][(j + 2) % 3] - trans_matrix2[(i + 1) % 3][(j + 2) % 3] * trans_matrix2[(i + 2) % 3][(j + 1) % 3]);
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%.4lf  ", inv_matrix2[i][j]);
		}
		printf("\n");
	}

	return 0;
}