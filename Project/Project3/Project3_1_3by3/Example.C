#include <Stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
	int i, j, k, m;
	int matrix1[3][3];
	int matrix2[3][3];
	int add_matrix[3][3];
	int subt_matrix[3][3];
	int mult_matrix[3][3];
	int trans_matrix1[3][3];
	int trans_matrix2[3][3];

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
			printf("%d  ", matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("matrix 2 is : \n");
	for (k = 0; k < 3; k++)
	{
		for (m = 0; m < 3; m++)
		{
			printf("%d  ", matrix2[k][m]);
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
			printf("%d  ", add_matrix[i][j]);
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
			printf("%d  ", subt_matrix[i][j]);
		}
		printf("\n");
	}

	//행렬의 곱셈:  a11 a12 a13       b11 b12 b13		a11*b11+a12*b21+a13*b31  a11*b12+a12*b22+a13+b32  a11*b13+a12*b23+a13*b33
	//  			a21 a22 a23	  x   b21 b22 b23	=	a21*b11+a22*b21+a23*b31  a21*b12+a22*b22+a23*b32  a21*b13+a22*b23+a23*b33
	//				a31 a32 a33		  b31 b32 b33		a31*b11+a32*b21+a33*b31  a31*b12+a32*b22+a33*b32  a31*b13+a32*b23+a33*b33
	//등호 왼쪽은 곱셈으로 새로 만들어진 행렬 C, 오른쪽에서 곱셈기호 왼쪽은 a, 오른쪽은 b이면
	//11=11*11+12*21+13*31  12=11*12+12*22+13*32 13=11*13+12*23+13*33...이므로
	//C행렬이 ij일때 곱은 ikkj로 반복.  3중 for문으로 ijk 사용, matrix5[i][j]=matrix1[i][k]*matrix2[k][j]

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
			printf("%d  ", mult_matrix[i][j]);
		}
		printf("\n");
	}

	printf("\ntranspose of matrix 1 is : \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			trans_matrix1[i][j] = matrix1[j][i];
			printf("%d  ", trans_matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\nTranspose of matrix 2 is : \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			trans_matrix2[i][j] = matrix2[j][i];
			printf("%d  ", trans_matrix2[i][j]);
		}
		printf("\n");
	}

	//역행렬: 전치행렬/행렬식: 행렬식이 0이면 전치행렬 없다고 선언 필요

	printf("\nInverse of matrix 1 is : \n");

	float det_matrix1;
	float inv_matrix1[3][3];

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

	float det_matrix2;
	float inv_matrix2[3][3];

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