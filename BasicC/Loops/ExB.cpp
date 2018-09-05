#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void exB()
{
	char letter, temp, temp2;
	int num;
	printf ("Enter lowercase letter\n");
	scanf ("%c",&letter);
	num = letter - 'a';
	
	// First letter
	for (int j = 0; j < num; j++)
	{
		printf (" ");
	}
	printf ("a\n");

	
	for (int i = 1; i <= num; i++)
	{
		// Spaces
		for (int j = i; j < num; j++)
		{
			printf (" ");
		}

		// First letters
		for (int j = 0; j < i; j++)
		{
			temp = 'a' + j;
			printf ("%c",temp);
		}
		
		// Middle letter
		temp = 'a' + i;
		printf ("%c" , temp);
		temp2 = temp + 1;

		// Last letters
		for (int j = 0; j < i; j++)
		{
			temp--;
			printf ("%c",temp);
		}
		printf ("\n");
	}

	// Please stop so I can see what happend
	scanf ("%d",&letter);
}