#define _CRT_SECURE_NO_WARNINGS
#define n 5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main()
{
	int mat[n][n] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	// Varriables
	int newMat[n + 2][n + 2];
	int mone = 0;

	// Code
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			newMat[i][j] = mat[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			printf("%d", newMat[i][j]);
		}
		printf("\n");
	}


	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int count = 0;
			for (int k = i-1; k <= i+1; k++)
			{
				for (int w = j - 1; w <= j + 1; w++)
				{
					if (newMat[k][w] == 1)
					{
						count++;
					}
				}
			}
			if (count == 9)
			{
				mone++;
			}
		}
	}
	printf("%d", mone);

	// Please stop so I can see what happend
	scanf ("%d");
}