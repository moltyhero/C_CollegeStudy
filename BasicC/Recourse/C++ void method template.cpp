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

int reverse(int num) // Ex8 (not working)

{
	int temp;
	if (num < 10)
	{
		return num;
	}
	return (num % 10) + reverse(num/10);
}

int numDigits(int num) // Ex9
{
	if (num > 10)
	{
		return 1 + numDigits(num / 10);
	}
	else return 1;
}

int maxDigit(int num) // Ex10
{
	if (num < 10) return num;
	else return fmax(num % 10, maxDigit(num / 10));
}

int ex13(int num) // Ex13 (Not this way)
{
	if (num < 10)
		return num;
	return num % 10 + (-1) *(ex13(num / 10));
}

int sameDigits (int num1, int num2) // Ex14
{
	if (num1 == 0 || num2 == 0) return 0;
	if (num1 % 10 == num2 % 10)
	{
		return 1 + sameDigits(num1 / 10, num2 / 10);

	}
	else return (sameDigits(num1 / 10, num2 / 10));
}

int unevenInLeft(int num) // Ex16
{
	if (num < 100)
		return num;
	else 
	{
		int temp = num % 10;
		num = unevenInLeft(num / 10);

		if (temp % 2 != 0)
		{
			int mone = 1, temp2 = num;
			while (temp2%10%2==0)
			{
				mone*=10;
				temp2 = temp2/ 10;
			}
			temp2 = num;
			num = num / mone * 10 + temp * mone;
			for (int i = 1; i < mone; i*=10)
			{
				num += temp2 % 10;
				temp2 /= 10;
			}
		}
		else
		{
			num = num*10 + temp;
		}
	}
	return num;
	
} // Not working



int main()
{
	printf("%d", unevenInLeft(123456));

	// Please stop so I can see what happend
	scanf("%d");
}