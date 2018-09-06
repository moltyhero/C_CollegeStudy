#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	// Varriables
	bool isOk = true;
	long num, copy;
	int base, endBase, mone=1;

	// Code
	printf ("Enter number, base and destination base \n");
	scanf ("%d%d%d",&num,&base,&endBase);

	// Convert to decimal base
	copy = num;
	num = 0;
	while (copy != 0 && isOk)
	{
		if (copy % 10 >= base)
		{
			printf ("ERROR");
			isOk = false;
		}
		else
		{
			num = num + (copy%10*mone);
			mone *= base;
		}
		copy = copy / 10;
	}
	
	// Now I have my nuber in decimal base, let's convert it to the end base
	if (isOk)
	{
		if (endBase == 10) // Maybe no need anymore convertion? ALREADY IN DECIMAL
		{
			printf ("%d",num);
		}
		else
		{
			mone = 1;
			while (num != 0)
			{
				copy = (num % endBase) * mone;
				num = num / endBase;
				mone *= 10;
			}
			printf ("%d",copy);
			
		}
	}

	// Please stop so I can see what happend
	scanf ("%d");
}