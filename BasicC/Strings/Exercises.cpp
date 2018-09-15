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

void main()
{
	ex7();

	// Please stop so I can see what happend
	scanf("%d"); scanf("%d");
}