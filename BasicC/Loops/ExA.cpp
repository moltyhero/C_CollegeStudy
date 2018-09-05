#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void exA()
{
	int num;
	printf ("Enter number");
	scanf ("%d",&num);

	for (int i = 1; i <= num; i++)
	{
		int j = 0;
		for (j = 0; j < i; j++)
		{
			printf ("*");
		}
		int k = (num * 2) - (i * 2);
		for (int l=0; l < k; l++)
		{
			printf (" ");
		}
		for (j = 0; j < i; j++)
		{
			printf ("*");
		}
		printf ("\n");
	}
	scanf ("%d",&num);
}