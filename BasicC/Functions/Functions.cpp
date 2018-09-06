#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int howManyDigitInNumber(int num, int digit)
{
	// Varriables
	int mone = 0;

	// Code
	while (num != 0)
	{
		if (num % 10 == digit)
		{
			mone++;
		}
		num = num / 10;
	}
	return mone;
}

int randomNumberBetween(int num1, int num2)
{
	srand(time(NULL));

	return rand () % num1 + num2;
}

void main()
{
	int num1,num2;

	printf ("Enter 2 numbers");
	scanf ("%d%d",&num1,&num2);
	while (num1 != -999 || num2!=-999)
	{
		for (int i = 0; i < 5; i++)
		{
			printf ("%d",randomNumberBetween (num1,num2));
		}
		printf ("Enter 2 numbers");
		scanf ("%d%d",&num1,&num2);
	}
	
}

int sumDigits (int num)
{
	int sum=0;
	while (num != 0)
	{
		sum += num % 10;
		num /= num;
	}
	return sum;
}

void ex11 ()
{
	int n = 10,maxNum,maxSum = 0, num, sum;
	for (int i = 0; i < n; i++)
	{
		printf ("Enter number");
		scanf ("%d",&num);
		sum = sumDigits (num);
		if (sum > maxSum)
		{
			maxNum = num;
			maxSum = sum;
		}
	}
	printf ("Highest summery was from numner %d",maxNum);
}

bool isPerfectNumber(int num)
{
	int sum = 0;
	for (int i = 2; i <= num/2; i++)
	{
		if (num%i == 0)
		{
			sum += i;
		}
	}
	if (num == sum)
	{
		return 1;
	}
	else return 0;
}

void ex14 ()
{
	for (int i = 10; i <= 1000; i++)
	{
		if (isPerfectNumber(i))
		{
			printf("%d", i);
		}
	}
}

bool isDifferentDigits(int num)
{
	int copy, mone;
	copy = num;
	while (num!=0)
	{
		mone = 0;
		while (copy != 0)
		{
			if (num % 10 == copy % 10)
			{
				++mone;
			}
			copy /= 10;
		}
		if (mone > 1)
		{
			return 0;
		}
		num /= num;
	}
	return 1;
}

void ex16()
{
	int num, mone=0;
	printf("Enter number");
	scanf("%d", num);
	while (isDifferentDigits(num))
	{
		++mone;
		printf("Enter number");
		scanf("%d", num);
	}
	printf("Your number (%d) was the chosen one! Only after %d numbers...", num, mone);
}

void ex22()
{
	int num, sumDigitsOfNum;

	printf("Enter number");
	scanf("%d", num);

	sumDigitsOfNum = sumDigits(num);

	for (int i = 1; i < num; i++)
	{
		if (sumDigits(i) == sumDigitsOfNum)
		{
			printf("%d", i);
		}
	}
}

