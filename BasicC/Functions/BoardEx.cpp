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

// Example
void mainMain()
{
	// Varriables
	int arr[] = { 1,2,3,4 };
	int c = sizeof(arr) / sizeof(arr[0]);

	// Code
	printArr(arr , c);

	scanf("%d");
}