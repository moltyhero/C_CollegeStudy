#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void ex4()
{
	srand(time(NULL));
	int randomNum = rand() % 100 + 1;
	int guess;
	printf("%d \n", randomNum);
	for (int i = 0; i < 99; i++)
	{
		printf("Enter your guess \n");
		scanf("%d", &guess);
		if (guess == randomNum)
		{
			printf("You are correct after %d tries ", i);
			i = 99;
		}
	}
}
