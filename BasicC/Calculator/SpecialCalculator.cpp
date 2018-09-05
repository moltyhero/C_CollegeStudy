#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	// Varriables
	char c;
	int sum,num1, num2;

	// Code
	printf ("Enter your desired action");
	scanf ("%c",&c);

	while (c != '_')
	{
		sum = 0;
		if (c == '+')
		{
			printf ("Enter numbber");
			scanf ("%d",&num1);
			while (num1!=0)
			{
				sum += num1;
				printf ("Enter number");
				scanf ("%d",&num1);
			}
			printf ("The summery is %d",sum);
		}
		else if (c == '*')
		{
			printf ("Enter numbber");
			scanf ("%d",&num1);
			while (num1!=1)
			{
				sum *= num1;
				printf ("Enter number");
				scanf ("%d",&num1);
			}
			printf ("The summery is %d",sum);
		}
		else if (c == '-')
		{
			printf ("Enter 2 numbers");
			scanf ("%d%d",&num1, &num2);
			sum = num1 - num2;
		}

		else if (c == '/')
		{
			
		}
	}

	// Please stop so I can see what happend
	scanf ("%d");
}