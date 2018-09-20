#define _CRT_SECURE_NO_WARNINGS
#define n 10
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef char String[256];

void swapStrings(String *n1, String *n2)
{
	char* temp = _strdup(*n1);
	//*n1 = strdup(*n2);
	strcpy(*n1, *n2);
	strcpy(*n2, temp);
}

void swapInts(int *n1, int *n2)
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void sortStudents(String **name, int **classArr, int size)
{
	// Varriables
	int i = 0, j, sort = 0;

	// Code
	while (i < size - 1 && !sort)
	{
		sort = 1;
		for (j = 0; j < size - 1; j++)
		{
			if (*name[j] > *name[j + 1])
			{
				swapStrings(name[j], name[j + 1]);
				swapInts(classArr[j], classArr[j + 1]);
				sort = 0;
			}
		}
		i++;
	}
}

/*void main2()
{
	String name[] = { "Matan", "Dvir", "Ofir", "Tomer", "Omri" };
	int classArr[] = { 1, 2, 3, 4, 5 };
	int size = 5;

	sortStudents(*name, *classArr, 5);

	for (int i = 0; i < size; i++)
	{
		printf("Student %s in class %d\n", *name[i], classArr[i]);
	}

	getchar();
}*/