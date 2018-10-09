#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int contains5(int num) // Ex1
{
	if (num == 0) return 0;
	else if (num % 10 == 5) return 1;
	else return contains5(num / 10);
}

int sumDigits(int num) // Ex2 A
{
	int sum = 0;
	if (num == 0) 
		return 0;
	else
		sum += num%10 + sumDigits(num / 10);
	return sum;
}

int countEvenDigits(int num) // Ex2 B
{
	if (num) return 0;
	else
	{
		if (num%2==0)
		{
			return (1 + countEvenDigits(num / 10));
		}
		else 
			return countEvenDigits(num / 10);
	}
}

int countainsOddDigit(int num) // Ex 3
{
	if (num)
		return 0;
	else
	{
		if (num % 2 != 0)
			return countainsOddDigit(num / 10);
		else
			return 1;
	}
}

int doesInOrder(int num) // Ex4
{
	if (num/10 ==0)
		return 1;
	else
	{
		if (num%10>(num/10%10))
		{
			return doesInOrder(num/10);
		}
		else return 0;
	}
}

void printReadableNumber(int num) // Ex5
{
	if (num / 1000 == 0)
	{
		printf("%d,");
	}
	else
	{
		printReadableNumber(num / 1000);
		int temp = num % 1000;
		printf("%d," , temp);
	}
}

int orderNumber(int num) // Ex6
{
	int temp, myNum = num % 10, i=1, changeNum;
	if (num / 10 == 0)
		return num;
	
	num = orderNumber(num/10)*10+myNum;

	temp = num/10;
	while (temp)
	{
		if (myNum > temp % 10)
		{
			//num = num / 10;
			//num = num + myNum * 10;
			i *= 10;
		}
		else break;
		temp /= 10;
	}
	if (i > 1)
	{
		// Find a way to enter the digit in the currect place
	}
	
	return num;
}

int dividedBy11(int num) // Ex11
{
	int act = 1, temp=num, sum=0;
	if (abs(num) >= 1 && abs(num) <= 10)
		return 0;
	else if (num == 0) return 1;
	while (temp!=0)
	{
		sum += temp % 10 * act;
		act = act * (-1);
		temp = temp / 10;
	}
	return dividedBy11(sum);
}

int reverse(int num)
{
	int temp;
	if (num < 10)
	{
		return num;
	}
	return 10 * (num % 10) + reverse(num/10);
}

int main()
{
	printf("%d", reverse(123));

	// Please stop so I can see what happend
	scanf("%d");
}