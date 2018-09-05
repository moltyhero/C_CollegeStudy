#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int max = 0,temp = 0,num1 = 0,num2;
	printf ("Enter number");
	scanf ("%d",&num2);
	while (num2 != 0)
	{
		if (num2 > num1)
		{
			++temp;
			num1 = num2;
		}
		printf ("Enter number");
		scanf ("%d",&num2);
	}
	
}