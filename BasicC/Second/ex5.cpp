#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ex5()
{
	int num1,copy,digitNum=0;
	printf ("Enter number");
	scanf ("d",&num1);
	copy = num1;
	while (num1 != 0)
	{
		num1 = num1 / 10;
		digitNum++;
	}
	num1 = copy;

	//for (int i = 0;
	
}