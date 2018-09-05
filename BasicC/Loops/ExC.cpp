#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	// Varriables
	int n,k,mone=0;

	// Code
	printf ("Enter number and parts\n");
	scanf ("%d%d",&n,&k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int l = i; l < n; l++)
			{
				printf ("%d",l);
				mone++;
			}
			for (int l = 0; l < n-mone; l++)
			{
				printf ("%d",l);
			}
			printf ("@");
			mone = 0;
		}
		printf ("\n");
	}

	// Please stop so I can see what happend
	scanf ("%d");
}