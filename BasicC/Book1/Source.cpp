#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void ex3PrintLiteralNumber(int num)
{
	switch (num)
	{
		case 1:
			printf("One");
		default:
			break;
	}
}

void p106Ex13(int sumGoals[])
{
	for (int i = 0; i < 20; i++)
	{
		printf("%d", i);
		printf("%f", sumGoals[i] / 3);
		if (sumGoals[i] == 0)
		{
			printf("The player hasn't goaled");
		}
		else if (sumGoals[i] > 5)
		{
			printf("Amazing player");
		}
	}
}

void p113Ex23()
{
	int numberOfExaminees ;
	int passersNum = 0;
	int mistakeTam, mistakeRest;
	float precentage;

	printf("Enter number of examinees\n");
	scanf("%d", &numberOfExaminees);

	for (int i = 0; i < numberOfExaminees; i++)
	{
		printf("Enter the number of mistakes in tamrorim\n");
		scanf("%d", &mistakeTam);

		printf("Enter the number of mistakes in the rest of the questions\n");
		scanf("%d", &mistakeRest);

		if (mistakeTam == (float)0.0 && mistakeRest <= (float)3.0)
			passersNum++;
		//printf("passers: %d\n", passersNum);
	}

	//printf("passers: %d\n", passersNum);
	precentage = (float)passersNum / numberOfExaminees * 100;
	printf("%f", precentage);

}

void p113Ex24()
{
	int num, isRishoni = 1;
	printf("Enter number\n");
	scanf("%d", &num);

	if (num == 4 || num == 2)
	{
		printf("Not rishoni!");
	}
	else
	{
		for (int i = 2; i < sqrt(num); i++)
		{
			if (num % i == 0)
			{
				printf("Not rishoni!");
				isRishoni = 0;
				break;
			}
		}

		if (isRishoni)
		{
			printf("Is rishoni!");
		}
	}
	
}

void p124Ex55()
{
	time_t t;
	srand((unsigned)time(&t));

	int n, num, maxNum, maxTimes;
	int *mone;
	float avg=0;

	mone = (int*)calloc(3, sizeof(int));
	

	printf("Enter number of randoms\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		num = (8 + rand() % 3);
		avg += num;
		mone[num - 8]++;
		//printf("%d\n", num);
	}

	// Highest times of number
	maxNum = 8;
	maxTimes = mone[0];
	if (mone[1] > maxTimes)
	{
		maxNum = 9;
		maxTimes = mone[1];
	}
	if (mone[2] > maxTimes)
	{
		maxNum = 10;
		maxTimes = mone[2];
	}
	printf("Highest times is of the number %d, %d times\n", maxNum, maxTimes);

	// Average
	avg = avg / n;
	printf("Average is %f\n", avg);

	// Highest number
	for (int i = 2; i >= 0; i--)
	{
		if (mone[i] > 0)
		{
			printf("Highest number is %d", i+8);
			break;
		}
	}

}

void p136Ex19() // Fibonachi
{
	int num, current = 1, previous = 0, temp;

	printf("Enter number\n");
	scanf("%d", &num);

	while (current < num)
	{
		printf("%d, ", current);
		temp = current;
		current = current += previous;
		previous = temp;
	}
}

void p136Ex20() // Reveresed number
{
	int num, reversed=0;

	printf("Enter number\n");
	scanf("%d", &num);

	while (num != 0)
	{
		reversed = reversed * 10;
		reversed += num % 10;
		num = num / 10;
	}

	printf("%d", reversed);
}

int main()
{
	p136Ex20();
	scanf("%d");
}