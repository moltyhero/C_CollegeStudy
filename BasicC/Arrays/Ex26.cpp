#define _CRT_SECURE_NO_WARNINGS
#define n 9
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ex26()
{
	// Varriables
	int series[n] {2,3,4,2,3,4,5,6,7};
	int space;
	bool isSerialized = true;

	// Code
	// Find how many indexes between each predicted series
	for (int i = 1; i < n; i++)
	{
		if (series[i] == series[0])
		{
			space = i;
			break;
		}
	}
	
	// For every index, check if it's following one between each space is equal to him
	for (int i = 0; i+space < n; i+=space)
	{
		for (int j = i; j < i+space; j++)
		{
			if (series[j] != (series[j + space]))
				isSerialized = false;
		}
		if (!isSerialized)
		{
			break;
		}
	}

	// Print the correct massage
	if (isSerialized)
	{
		printf ("It is serialized");
	}
	else
	{
		printf ("It's not serialized");
	}
	
	// Please stop so I can see what happend
	scanf ("%d");
}