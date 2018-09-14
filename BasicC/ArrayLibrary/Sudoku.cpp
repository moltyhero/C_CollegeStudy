#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Sudoku.h"


int isRow(int matrix[4][4], int row)
{
	// Varriables
	int isOk;

	// Code
	for (int i = 1; i <= 4; i++)
	{
		isOk = 0;
		for (int j = 0; j < 4; j++)
		{
			if (matrix[row][j] == i)
			{
				if (isOk)
				{
					return 0;
				}
			}
			else isOk = 1;
		}
	}

	return 1;
}

int isCol(int matrix[4][4], int col)
{
	// Varriables
	int isOk;

	// Code
	for (int i = 1; i <= 4; i++)
	{
		isOk = 0;
		for (int j = 0; j < 4; j++)
		{
			if (matrix[j][col] == i)
			{
				if (isOk)
				{
					return 0;
				}
			}
			else isOk = 1;
		}
	}

	return 1;
}

int is2X2(int mat[][4], int r, int c)
{
	// Varriables
	int isOk;

	// Code
	for (int i = 1; i <= 4; i++)
	{
		isOk = 0;
		for (int j = r; j <= r+1; j++)
		{
			for (int k = c; k <= c+1; k++)
			{
				if (mat[j][k] == i)
				{
					if (isOk)
					{
						return 0;
					}
				}
				else isOk = 1;
			}
		}
	}

	return 1;
}

int isQuarter(int mat[4][4])
{
	// Code
	if (!is2X2(mat, 0, 0) || !is2X2(mat, 0, 2) || !is2X2(mat, 2, 0) || !is2X2(mat, 2, 2))
		return 0;

	return 1;
}

int isSoduko(int mat[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		if (!isRow(mat, i))
		{
			printf("GOOD1");
			return 0;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (!isCol(mat, i))
		{
			printf("GOOD2");
			return 0;
		}
			
	}
	if (!isQuarter(mat))
	{
		printf("GOOD3");
		return 0;
	}
		
}