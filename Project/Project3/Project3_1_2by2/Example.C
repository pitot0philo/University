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

	//Çà·ÄÀÇ °ö¼À:  a11 a12 a13       b11 b12 b13		a11*b11+a12*b21+a13*b31  a11*b12+a12*b22+a13+b32  a11*b13+a12*b23+a13*b33
	//  			a21 a22 a23	  x   b21 b22 b23	=	a21*b11+a22*b21+a23*b31  a21*b12+a22*b22+a23*b32  a21*b13+a22*b23+a23*b33
	//				a31 a32 a33		  b31 b32 b33		a31*b11+a32*b21+a33*b31  a31*b12+a32*b22+a33*b32  a31*b13+a32*b23+a33*b33
	//µîÈ£ ¿ÞÂÊÀº °ö¼ÀÀ¸·Î »õ·Î ¸¸µé¾îÁø Çà·Ä C, ¿À¸¥ÂÊ¿¡¼­ °ö¼À±âÈ£ ¿ÞÂÊÀº a, ¿À¸¥ÂÊÀº bÀÌ¸é
	//11=11*11+12*21+13*31  12=11*12+12*22+13*32 13=11*13+12*23+13*33...ÀÌ¹Ç·Î
	//CÇà·ÄÀÌ ijÀÏ¶§ °öÀº ikkj·Î ¹Ýº¹.  3Áß for¹®À¸·Î ijk »ç¿ë, matrix5[i][j]=matrix1[i][k]*matrix2[k][j]

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

	float inv_matrix1[2][2];
	float det_matrix1;
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

	return 0;
}