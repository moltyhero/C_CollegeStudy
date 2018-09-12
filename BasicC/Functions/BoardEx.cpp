#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Print any array with known length
void printArr(int arr[] , int c)
{
	// Varriables
	int i;

	// Code
	for (i = 0; i < c; i++)
	{
		printf("\n%d : %d", i, arr[i]);
	}
	printf("\n%d", i);
}

//???
int newArr(int arr[], int c, int arrB[], int *mone)
{
	for (int i = 0; i < c; i++)
	{
		if (arr[i] % 2 == 0)
		{
			arrB[*mone++] = arr[i];
		}
	}
	return 0;
}

// Example
void main()
{
	// Varriables
	int arr[] = { 1,2,3,4 };
	int mone = 0;
	int c = sizeof(arr) / sizeof(arr[0]);
	int arrB[4];

	// Code
	printArr(arr , c);
	newArr(arr, c, arrB, &mone);
	printArr(arr, c);

	scanf("%d");
}