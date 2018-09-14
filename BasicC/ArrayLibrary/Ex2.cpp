#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Sudoku.h"

void main(int mat[20][20])
{
	//// Varriables
	//int sumPlayer1 = 0, sumPlayer2 = 0;

	//// Code
	//while (sumPlayer1 < 1000 && sumPlayer2 < 1000)
	//{
	//	sumPlayer1 += 1;
	//	sumPlayer2 += 2;
	//}
	//if (sumPlayer1 > sumPlayer2)
	//{
	//	printf("Player 1 has won!");
	//}
	//else printf("Player 2 has won!");

	//// Please stop so I can see what happend
	//scanf ("%d");

	int matrix[4][4];
	int ok = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	ok = isSoduko(matrix);
	printf("%d", ok);
	scanf("%d");

}