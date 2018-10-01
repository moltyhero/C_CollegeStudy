#define _CRT_SECURE_NO_WARNINGS
#define n 5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Ex19.h"



void createMat(int matrix[n][n])
{
	time_t t;
	srand((unsigned)time(&t));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 200 + rand() % 501;
		}
	}
}

int calcWin(int matrix[n + 2][n + 2])
{
	int sum = 0, isBig;

	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			isBig = 1;
			for (int k = -1; k < 2; k++)
			{
				for (int l = -1; l < 2; l++)
				{
					if (matrix[i][j] < matrix[i + k][j + l])
					{
						isBig = 0;
						break;
					}
				}
				if (!isBig)
					break;
			}
			if (isBig)
				sum += matrix[i][j];
		}
	}

	return sum;
}

int main()
{
	int mat[n][n];
	int newMat[n + 2][n + 2];
	createMat(mat);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < n+2; i++)
	{
		newMat[0][i] = 0;
	}
	for (int i = 0; i < n+2; i++)
	{
		newMat[i][0] = 0;
	}
	for (int i = 0; i < n + 2; i++)
	{
		newMat[n+1][i] = 0;
	}
	for (int i = 0; i < n + 2; i++)
	{
		newMat[i][n+1] = 0;
	}
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			newMat[i][j] = mat[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n+2; i++)
	{
		for (int j = 0; j < n+2; j++)
		{
			printf("%d ", newMat[i][j]);
		}
		printf("\n");
	}

	printf("%d", calcWin(newMat));

	scanf("%d");
	return 0;
}