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

void ex5()
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

int max(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	return num2;
}

int max3(int num1, int num2, int num3)
{
	int highest;
	highest = max(num1, num2);
	highest = max(highest, num3);
	return highest;
}

void ex15()
{
	int result, avgResult1, avgResult2, avgResult3, avgResult = 0, maxResult;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			printf("Enter result of player number %d", i);
			scanf("%d", &result);
			avgResult += result;
		}
		if (i == 1)
			avgResult1 = avgResult;
		else if (i == 2)
			avgResult2 = avgResult;
		else
			avgResult3 = avgResult;
	}
	avgResult1 = avgResult1 / 3;
	avgResult2 = avgResult2 / 3;
	avgResult3 = avgResult3 / 3;
	maxResult = max3(avgResult1, avgResult2, avgResult3);
	// useless function was asked, I am not co oprating with this ex;
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
	scanf("%d", &num);
	while (isDifferentDigits(num))
	{
		++mone;
		printf("Enter number");
		scanf("%d", &num);
	}
	printf("Your number (%d) was the chosen one! Only after %d numbers...", num, mone);
}

void ex22(int num)
{
	int sumDigitsOfNum;

	sumDigitsOfNum = sumDigits(num);

	for (int i = 1; i < num; i++)
	{
		if (sumDigits(i) == sumDigitsOfNum)
		{
			printf("%d", i);
		}
	}
}

void findAllPlacesOfDigitInNum(int num, int digit)
{
	int mone = 1;
	while (num != 0)
	{
		if (num % 10 == digit)
		{
			printf("%d", mone);
		}
		++mone;
		num /= num;
	}
}

void ex23()
{
	int num;

	printf("Enter number");
	scanf("%d", &num);

	for (int i = 0; i < 10; i++)
	{
		printf("The digit %d is on the following places in the number: /n" , i);
		findAllPlacesOfDigitInNum(num, i);
	}
}

void changeGrade(int *grade, int units)
{
	if (units == 5)
	{
		*grade += 20;
	}
	else if (units == 4)
	{
		*grade += 10;
	}
}

void ex29()
{
	int num, grade, units, avg;
	printf("Enter number of tests");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		printf("Enter grade and untits number\n");
		scanf("%d%d", &grade, &units);
		changeGrade(&grade, units);
		avg += grade;
	}
	avg = avg / num;
	printf("The average is %d" , avg);
}

void ex38()
{
	int num, sum = 0;
	double avg;
	for (int i = 1; i < 20; i++)
	{
		printf("Enter number of students in hour %d", i);
		scanf("%d", &num);
		if (num > 10)
		{
			sum = sum + 700;
			sum = sum + 5 * (num - 10);
		}
	}
	avg = sum / 20;
	printf("The average salary is %f", avg);
}