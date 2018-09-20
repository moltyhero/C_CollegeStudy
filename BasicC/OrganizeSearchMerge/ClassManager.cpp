#define _CRT_SECURE_NO_WARNINGS
#define n 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float avg(int grades[])
{
	float sum = 0;
	int i = 0;

	while (grades[i]!=-1)
	{
		sum += grades[i];
		i++;
	}
	return sum / i;
}

float avg3(int grades1[], int grades2[], int grades3[])
{
	float sum = 0;
	int i, mone=0;

	i = 0;
	while (grades1[i] != -1)
	{
		sum += grades1[i];
		i++;
		mone++;
	}
	i = 0;
	while (grades2[i] != -1)
	{
		sum += grades2[i];
		i++;
		mone++;
	}
	i = 0;
	while (grades3[i] != -1)
	{
		sum += grades3[i];
		i++;
		mone++;
	}
	return sum / i;
}

int commonGrade(int grades[])
{
	int i, maxNumber, maxCounter=0;
	int* gradesCounter = (int*)calloc(101, sizeof(int));

	i = 0;
	while (grades[i] != -1)
	{
		gradesCounter[grades[i]]++;
		i++;
	}
	for (int j = 1; j < 100; j++)
	{
		if (gradesCounter[j]>maxCounter)
		{
			maxNumber = j;
		}
	}
	return maxNumber;
}

int commonGrade3(int grades1[], int grades2[], int grades3[])
{
	int i, maxNumber, maxCounter = 0;
	int* gradesCounter = (int*)calloc(101, sizeof(int));

	i = 0;
	while (grades1[i] != -1)
	{
		gradesCounter[grades1[i]]++;
		i++;
	}
	i = 0;
	while (grades2[i] != -1)
	{
		gradesCounter[grades2[i]]++;
		i++;
	}
	i = 0;
	while (grades3[i] != -1)
	{
		gradesCounter[grades3[i]]++;
		i++;
	}
	for (int j = 1; j < 100; j++)
	{
		if (gradesCounter[j] > maxCounter)
		{
			maxNumber = j;
		}
	}
	return maxNumber;
}

int* above90Grades(int grades[])
{
	int i = 0, j=0;
	int* above90 = (int*)malloc(sizeof(int));
	if (!above90)
	{
		printf("Not enogth memory");
		return 0;
	}
	while (grades[i] != -1)
	{
		if (grades[i] >= 90)
		{
			above90 = (int*)realloc(above90, ++j * sizeof(int));
			above90[j-1] = grades[i];
		}
		i++;
	}
	return above90;
}

int main()
{
	// Varriables
	int* class1 = (int*)malloc(sizeof(int));
	int* class2 = (int*)malloc(sizeof(int));
	int* class3 = (int*)malloc(sizeof(int));
	int grade, place;

	// Code
	// TODO: create an array and copy the pointer to each class
	scanf("%d", &grade);
	place = 0;
	while (grade != -1)
	{
		class1[place] = grade;
		class1 = (int*)realloc(class1, (place + 2) * sizeof(int));
		place++;
		printf("Enter grade for class 1");
		scanf("%d", &grade);
	}
	class1[place] = -1;
	class1 = (int*)realloc(class1, (place + 2) * sizeof(int));

	scanf("%d", &grade);
	place = 0;
	while (grade != -1)
	{
		class2[place] = grade;
		class2 = (int*)realloc(class2, (place + 2) * sizeof(int));
		place++;
		printf("Enter grade for class 2");
		scanf("%d", &grade);
	}
	class2[place] = -1;
	class2 = (int*)realloc(class2, (place + 2) * sizeof(int));

	scanf("%d", &grade);
	place = 0;
	while (grade != -1)
	{
		class3[place] = grade;
		class3 = (int*)realloc(class3, (place + 2) * sizeof(int));
		place++;
		printf("Enter grade for class 3");
		scanf("%d", &grade);
	}
	class3[place] = -1;
	class3 = (int*)realloc(class3, (place + 2) * sizeof(int));
	

	// Please stop so I can see what happend
	scanf ("%d");
	return 1;
}