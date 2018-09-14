#define _CRT_SECURE_NO_WARNINGS
#define n 10
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

	// Please stop so I can see what happend
	scanf ("%d");
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

	// Please stop so I can see what happend
	scanf("%d");
}

void main()
{
	ex1();
}