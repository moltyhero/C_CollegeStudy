#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>	
#include <stdio.h>
#include <string.h>

#define N 5
#define MAXLEN 80

void swap(char *s1, char *s2)
{
	char temp[MAXLEN];
	strcpy(temp, s1);
	strcpy(s1, s2);
	strcpy(s2, temp);
}

void mysort(char *a[])
{
	int i = 0, j, sort = 0;
	while ((i < N-1) && sort==0)
	{
		sort = 1;
		for (j = 0; j < N-i-1; j++)
		{
			if (strcmp(a[j], a[j + 1]) > 0)
			{
				swap(a[j], a[j + 1]);
				sort = 0;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		printf("%s ", a[i]);
	}
}

void main3(void)
{
	char *b[N];
	int i;
	puts("Enter 5 names");

	for (i = 0; i < N; i++)
	{
		b[i] = (char*)malloc(MAXLEN);
		scanf("%s", b[i]);
	}
	mysort(b);
	scanf("%d");
}