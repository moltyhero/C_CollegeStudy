#define _CRT_SECURE_NO_WARNINGS
#define n 9
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ex24()
{
	// Varriables
	int heartBeat[n];
	int moneHigh=0,moneLow=0;

	// Code
	for (int i = 0; i < n; i++)
	{
		if (heartBeat[i] > 150)
		{
			++moneHigh;
		}
		else if (heartBeat[i] < 80)
		{
			++moneLow;
		}
		if (moneHigh == 3)
		{
			printf ("High heartbeat!");
			break;
		}
		else if (moneLow == 3)
		{
			printf ("Low heartbeat!");
			break;
		}
	}

	// Please stop so I can see what happend
	scanf ("%d");
}