#define _CRT_SECURE_NO_WARNINGS
#define n 9
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void e25()
{
	// Varriables
	int arr[n];
	bool isThere = false;

	// Code
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == arr[j])
			{
				isThere = true;
				break;
			}
		}
		if (!isThere)
		{
			printf ("No tmoora");
			break;
		}
	}
	if (isThere)
	{
		printf ("TMOORA!!!");
	}

	// Please stop so I can see what happend
	scanf ("%d");
}