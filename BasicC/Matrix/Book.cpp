#define _CRT_SECURE_NO_WARNINGS
#define n 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma region
int sumArr(int *arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int sumMatCol(int mat[n][n], int size, int index)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += mat[i][index];
	}
	return sum;
}
int ex5(int mat[n][n], int size)
{
	int sum, tempSum;
	sum = sumArr(mat[0], size);

	// Check rows
	for (int i = 1; i < size; i++)
	{
		tempSum = sumArr(mat[i], size);
		if (tempSum != sum)
			return 0;
	}

	// Check collumns
	for (int i = 0; i < size; i++)
	{
		tempSum = sumMatCol(mat, size, i);
		if (tempSum != sum)
			return 0;
	}

	// Check cross
	tempSum = 0;
	for (int i = 0; i < size; i++)
	{
		tempSum += mat[i][i];
	}
	if (tempSum != sum)
		return 0;
	
	tempSum = 0;
	for (int i = size-1; i >= 0; i--)
	{
		tempSum += mat[size-1-i][i];
	}
	if (tempSum != sum)
		return 0;
	else return 1;
}

#pragma endregion Ex5

int main3()
{
	int mat[n][n] = { {2,9,4},
				{7,5,3},
				{6,1,8} };

	if (ex5(mat, 3))
		printf("1");
	else printf("0");
	scanf("%d");

	return 0;
}
