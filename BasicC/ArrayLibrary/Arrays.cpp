#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void printArr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d: %d", i, arr[i]);
	}
}

int sumArr(int arr[], int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int placeOfHighestInt(int arr[], int length)
{
	int max = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int sumBetween(int arr[], int length, int place1, int place2)
{
	int sum = 0;
	int high, low;
	if (place1 > place2)
	{
		high = place1;
		low = place2;
	}
	else
	{
		high = place2;
		low = place1;
	}
	
	if (high > length || low < 0)
	{
		return 0;
	}

	for (int i = low; i < high; i++)
	{
		sum += arr[i];
	}
	return sum;
}

void newOnlyDevidedBy3Arr(int arr[], int length)
{
	
}

float avgNumbersHigherThan10(int arr[], int length)
{
	int sum = 0;
	int moneHigherThan10 = 0;

	for (int i = 0; i < length; i++)
	{
		if (arr[i] > 10)
		{
			sum += arr[i];
			moneHigherThan10++;
		}
	}
	return sum / moneHigherThan10;
}