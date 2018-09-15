#define _CRT_SECURE_NO_WARNINGS
#define n 256
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef char String[n];


void ex1()
{
	// Varriables
	String str;

	// Code
	printf("Enter a string\n");
	scanf("%s", str);
	_strrev(str);
	printf("%s\n ", str);

	
}

void ex2()
{
	// Varriables
	String str;
	String original, copy;

	// Code
	printf("Enter a string\n");
	scanf("%s", str);
	printf("%s\n ", str);

	// b
	strcpy(original, str);
	strcat(str, original);
	printf("%s\n ", str);

	//c
	strcpy(str, original);
	strcpy(copy, original);
	_strrev(copy);
	strcat(str, copy);
	printf("%s\n ", str);

	//d
	strcpy(str, original);
	int i=0;
	while (str[i]!=NULL)
	{
		printf("%c", str[i]);
		printf("%c", str[i]);
		i++;
	}
}

void ex3()
{
	// Varriables
	int i=0, j=0;
	String str1, str2, finalPrint;
	printf("Enter 2 strings\n");
	scanf("%s %s", str1, str2);

	while (str1[i] != NULL)
	{
		if (strchr(str2, str1[i]) > 0)
		{
			finalPrint[j] = str1[i];
			j++;
		}
		i++;
	}
	printf("%s", finalPrint);

	
}

// ??
//void ex4()
//{
//	String str;
//	char *temp;
//	int i = 0;
//	printf("Enter string\n");
//	scanf("%s", str);
//	while (str[i] != NULL)
//	{
//		*temp = str[i];
//		for (int j = 0; j < strstr(str, temp); j++)
//		{
//
//		}
//	}
//}

void ex5()
{
	String original, str, helper;
	int N;
	int i = 0, k;
	printf("Enter string and number of loops\n");
	scanf("%s", original);
	strcpy(str, original);
	scanf("%d", &N);
	for (int j = 0; j < N; j++)
	{
		i = 0;
		while (str[i+1] != NULL)
		{
			i++;
		}
		helper[0] = str[i];
		for (k = 1; k <= i; k++)
		{
			helper[k] = str[k-1];
		}
		helper[k] = NULL;
		strcpy(str, helper);
	}
	printf("%s\n", str);
	k = strcmp(original, str);
	if (k == 0)
	{
		printf("Equal");
	}
	else
	{
		printf("Different: %d" , k);
	}
}

void ex6()
{
	String words[10];
	for (int i = 0; i < 100; i++)
	{
		printf("Enter word\n");
		scanf("%s", words[i]);
	}
	for (int i = 0; i < 100; i++)
	{
		printf("%s.\n" , words[i]);
	}

}

void ex7()
{
	int found = 0, place;
	char str1[100];
	char str2[3];
	char *temp;

	temp = str1;
	if (NULL != strstr(temp, str2))
	{
		printf("-1");
	}
	while (!found)
	{
		temp++;
		if (strstr(temp, str2) != NULL)
		{
			temp = strstr(str1, str2);
		}
		else found = 1;
	}
	temp--;
	for (int i = 0; i < 100; i++)
	{
		if (*temp == str1[i])
		{
			place = i;
		}
	}
	printf("%d", place);
}

void ex9()
{
	String str, ZUGI, LO_ZUGI;
	int i=0, place=0;
	char chr;
	printf("Enter character");
	chr = getchar();
	while (true)
	{
		str[i] = chr;
		if (chr == '.' && str[i - 1] == '*')
			break;
		i++;
		printf("Enter character");
		chr = getchar();
	}
	for (int j = 0; j <= i; j+=2)
	{
		LO_ZUGI[place] = str[j];
	}
	for (int j = 1; j <= i; j += 2)
	{
		ZUGI[place] = str[j];
	}
}

void ex10() //LOL
{
	
}

void ex11()
{
	String str1, str2, str3, helper;
	char *place;
	int len;
	printf("Enter 3 strings");
	scanf("%s%s%s", str1, str2, str3);
	place = strstr(str1, str2);
	if (place != NULL)
	{
		len = strlen(str2);
		*place = *(place + len);
		strcpy(helper, place);
		*place = *(place - len);
		strcpy(place, str3);
		*place = *(place + strlen(str3));
		strcpy(place, helper);
		printf("%s", str1);
	}
}

void ex12()
{
	String str;
	char *place;
	printf("Enter string\n");
	scanf("%s", str);
	for (int i = 0; i < strlen(str);)
	{
		if (str[i] == '*')
		{
			for (int j = i; j < strlen(str); j++)
			{
				*(str + j) = *(str + j + 1);
			}
		}
		else i++;
	}
	printf("%s", str);
}

void ex13()
{
	String str;
	int i = 0;
	char chr;
	while (true)
	{
		printf("Enter character");
		chr = getchar();
		str[i] = chr;
		if (chr == '.' && str[i - 1] == '*')
			break;
		i++;
		printf("Enter character");
		chr = getchar();
	}
	for (int j = 0; j < i; j++)
	{
		if (str[j]=='*')
		{
			if (str[j + 1] == '*')
			{
				printf("*");
				i++;
			}
			else if (str[j + 1] == ',')
			{
				printf("\n");
			}
			else printf("%c", str[j]);
		}
	}
}

void ex14()
{
	String str, num1, num2;
	int number1, number2;
	int place;
	printf("Enter number without 0");
	scanf("%s", str);
	place = 0;
	for (int i = 0; i < strlen(str)/2; i++)
	{
		num2[i] = str[place];
		place += 2;
	}
	place = 1;
	for (int i = 0; i < strlen(str) / 2; i++)
	{
		num1[i] = str[place];
		place += 2;
	}
	number1 = atoi(num1);
	number2 = atoi(num2);
	printf("%d", number1 + number2);
}

void ex16()
{
	String str;
	int num;
	printf("Enter number");
	scanf("%d", num);

}

void main()
{
	ex12();

	// Please stop so I can see what happend
	scanf("%d");
}