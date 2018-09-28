#define _CRT_SECURE_NO_WARNINGS
#define n 10
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void printBoard(char board[n+1][n+1])
{
	for (int i = 0; i < n; i++)
	{
		printf("%s \n", board[i]);
	}
}

int main()
{
	char board[n+1][n+1];
	int col=1, row=1, addBulliCol, addBulliRow, addDovRow, addDovCol, movement, bulliRow, bulliCol, dovRow, dovCol, standingOnPoint = 1, pointsLeft =  n*n, firstTurn = 1, dovWon = 0;
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			board[i][j] = '.';
		}
		board[i][j] = NULL;
	}

	while (col!=0 && row!=0)
	{
		printf("Enter a cell for a wall\n");
		scanf("%d %d", &row, &col);
		board[row - 1][col - 1] = '*';
		pointsLeft--;
	}
	printf("Enter a place for bulli\n");
	scanf("%d%d", &bulliRow, &bulliCol);
	bulliRow--;
	bulliCol--;
	board[bulliRow][bulliCol] = 'B';
	pointsLeft--;

	printf("Enter a place for dov\n");
	scanf("%d%d", &dovRow, &dovCol);
	board[--dovRow][--dovCol] = 'D';

	printBoard(board);

	while (pointsLeft > 0 && !dovWon)
	{
		// Handle bulli movement
		printf("Enter movement\n");
		scanf("%d", &movement);
		switch (movement)
		{
			case 1:
				addBulliRow = 0;
				addBulliCol = 1;
				break;
			case 2:
				addBulliRow = 0;
				addBulliCol = -1;
				break;
			case 3:
				addBulliRow = -1;
				addBulliCol = 0;
				break;
			case 4:
				addBulliRow = 1;
				addBulliCol = 0;
				break;
			default:
				break;
		}
		if (board[bulliRow + addBulliRow][bulliCol + addBulliCol] == '*' ||
			bulliRow + addBulliRow < 0 || bulliRow + addBulliRow > n ||
			bulliCol + addBulliCol < 0 || bulliCol + addBulliCol > n) // Out of boundaries or move to a wall
		{
			// You are dumb
		}
		else
		{
			board[bulliRow][bulliCol] = ' ';
			bulliRow += addBulliRow;
			bulliCol += addBulliCol;
			if (board[bulliRow][bulliCol] == '.')
				pointsLeft--;
			board[bulliRow][bulliCol] = 'B';
		}

		// Handle dov movement
		if (bulliRow-dovRow > 0)
			addDovRow = 1;
		else if (bulliRow - dovRow == 0)
			addDovRow = 0;
		else addDovRow = -1;

		if (bulliCol - dovCol > 0)
			addDovCol = 1;
		else if (bulliCol - dovCol == 0)
			addDovCol = 0;
		else addDovCol = -1;

		if (board[dovRow + addDovRow][dovCol + addDovCol] == 'B')
			dovWon = 1;
		
		else if (board[dovRow + addDovRow][dovCol + addDovCol] == '.' || board[dovRow + addDovRow][dovCol + addDovCol] == ' ')
		{
			if (standingOnPoint)
				board[dovRow][dovCol] = '.';
			else
				board[dovRow][dovCol] = ' ';

			dovRow += addDovRow;
			dovCol += addDovCol;
			if (board[dovRow][dovCol] == '.')
				standingOnPoint = 1;
			else
				standingOnPoint = 0;
			board[dovRow][dovCol] = 'D';
		}
		
		printBoard(board);
	}

	if (dovWon)
		printf("Dov ate bulli! Dov is the winner!");
	else
		printf("Bulli ate every point! Bulli is the winner!");

	scanf("%d");
	return 0;
}