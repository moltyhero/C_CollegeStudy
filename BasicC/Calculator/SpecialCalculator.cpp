#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void specialCalculator()
{
	// Varriables
	char c;
	int sum,num1, num2;

	// Code
	printf ("Enter your desired action\n");
	scanf ("%c",&c);

	while (c != '_')
	{
		sum = 0;
		switch (c)
		{
			case '+':
			{
				printf ("Enter number\n");
				scanf ("%d",&num1);
				while (num1 != 0)
				{
					sum += num1;
					printf ("Enter number\n");
					scanf ("%d",&num1);
				}
				printf ("The summery is %d\n",sum);
			}
			break;
			case '*':
			{
				sum = 1;
				printf ("Enter numbber\n");
				scanf ("%d",&num1);
				while (num1 != 1)
				{
					sum *= num1;
					printf ("Enter number");
					scanf ("%d",&num1);
				}
				printf ("The summery is %d\n",sum);
			}
			break;
			case '-':
			{
				printf ("Enter 2 numbers\n");
				scanf ("%d%d",&num1,&num2);
				sum = num1 - num2;
			}
			break;
			case '/':
			{
				printf ("Enter 2 numbers\n");
				scanf ("%d%d",&num1,&num2);

				sum = num2/num1;
				printf ("Answer is: %d\n" , sum);
				if (num2%num1 != 0)
				{
					sum = num2 % num1;
					printf ("Leftover: %d\n",sum);
				}
			}
			break;
			case '^':
			{
				printf ("Enter 2 numbers");
				scanf ("%d%d",&num1,&num2);
				sum = pow (num1,num2);
				printf ("%d\n" , sum);
			}
			break;
			default:
			{
				printf ("???");
			}
			printf ("bue");
		}
	}

	// Please stop so I can see what happend
	scanf ("%d");
}