#define _CRT_SECURE_NO_WARNINGS
#define n 4
#define m 6
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char mat[n][n];

int longestSameChars(mat matrix, int line)
{
	int max = 0, mone = 0;

	for (int i = 0; i < n-1; i++)
	{
		if (matrix[line][i] == matrix[line][i+1])
		{
			mone++;
		}
		else
		{
			if (++mone > max)
				max = mone;
			mone = 0;
		}
	}
	return max;
}

int mainEx16()
{
	mat matrix;
	int maxLine, max = 0, mone;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Enter character");
			matrix[i][j] = getchar();
		}
	}
	for (int i = 0; i < n; i++)
	{
		mone = longestSameChars(matrix, i);
		if (mone > max)
		{
			max = mone;
			maxLine = i;
		}
	}
	printf("Highes is %d in line %d ", max, maxLine);

	return 0;
}