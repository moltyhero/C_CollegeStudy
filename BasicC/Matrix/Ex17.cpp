#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void createMat(int matrix[5][6], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("Enter number");
			scanf("%d", *matrix[i, j]);
		}
	}
}

int searchNum(int matrix[5][6], int line, int size, int number)
{
	for (int i = 0; i < size; i++)
	{
		if (matrix[line][i] == number)
			return 1;
	}
	return 0;
}

int main5()
{
	int mat[5][6], found;
	createMat(mat, 5, 6);
	for (int i = 1; i <= 49; i++)
	{
		found = 0;
		for (int j = 0; j <= 5; j++)
		{
			if (searchNum(mat, j, 6, i))
			{
				found = 1;
				break;
			}
		}
		if (found)
			printf("%d", i);
	}

	return 0;
}