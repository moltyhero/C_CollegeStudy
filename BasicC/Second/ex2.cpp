#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ex2()
{
	int max = 0,temp = 0,num1 = 0,num2;
	printf ("Enter number");
	scanf ("%d",&num2);
	while (num2 != 0)
	{
		if (num2 > num1)
		{
			++temp;
		}
		else
		{
			if (temp > max)
			{
				max = temp;
			}
			temp = 1;
		}
		num1 = num2;
		printf ("Enter number");
		scanf ("%d",&num2);
	}
	if (temp > max)
	{
		max = temp;
	}
	printf ("%d",max);
	scanf ("%d",num2);
}