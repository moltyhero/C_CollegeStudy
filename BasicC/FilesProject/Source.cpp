#define _CRT_SECURE_NO_WARNINGS
#define LEN 20
#define MAX 10
#define COLS 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct
{
	int day;
	int month;
	int year;
} Date;

typedef struct
{
	int serial_num;
	char full_name[LEN];
	Date *pDate;
} Person;

Person* addPerson(const char *names[MAX], const int dates[MAX][COLS], Person** personArr, int size, int serial) // Pressed 1
{
	*personArr = (Person*)realloc(personArr, (1+size) *sizeof(Person));
	Person temp;
	temp.serial_num = size;
	strcpy(temp.full_name, names[size]);
	
	Date date;
	temp.serial_num = serial;
	temp.pDate->day = dates[size][0];
	temp.pDate->month = dates[size][1];
	temp.pDate->year = dates[size][2];

	*personArr[size] = temp;

	printf("The new added person is %s, %d\%d\%d", temp.full_name, temp.pDate->day, temp.pDate->month, temp.pDate->year);
}

void printArr(Person* personArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Person number %d is %s, born in %d\%d\%d", personArr[i].serial_num, personArr[i].full_name, personArr[i].pDate->day, personArr[i].pDate->month, personArr[i].pDate->year);
	}
}

int checkLatestDate(const void* person1, const void* person2)
{
	if (((Person*)person1)->pDate->year> ((Person*)person2)->pDate->year)
		return 1;
	else if (((Person*)person1)->pDate->year < ((Person*)person2)->pDate->year)
		return -1;
	else
	{
		if (((Person*)person1)->pDate->month > ((Person*)person2)->pDate->month)
			return 1;
		else if (((Person*)person1)->pDate->month < ((Person*)person2)->pDate->month)
			return -1;
		else
		{
			if (((Person*)person1)->pDate->day > ((Person*)person2)->pDate->day)
				return 1;
			else if (((Person*)person1)->pDate->day < ((Person*)person2)->pDate->day)
				return -1;
			else return 0;
		}
	}
}

void saveArrToFile(Person *personArr, const char *f_name, int size)
{
	FILE *file = fopen(f_name, "wt");
	if (!file)
	{
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%d %s %d %d %d", personArr[i].serial_num, personArr[i].full_name, 
				personArr[i].pDate->day, personArr[i].pDate->month, personArr[i].pDate->year);
	}
	
	fclose(file);
}

void main()
{
	#pragma region 	Pre-defined

	// Arrays of names
	const char *names[MAX] = { "Sasson_Sassoni", "Pooh", "James_Bond" }; // Continue entering...
	// Matrix of dates of birth
	const int dates[MAX][COLS] = {
	{10, 1, 1988},
	{12, 12, 1948},
	{4, 12, 1970}
	};

	// The file name
	const char *f_name = "Persons.txt";

	#pragma endregion

	#pragma region Written code
	int choice;
	Person* personArr;
	int size = 0, currentSerial = 1;

	scanf("%d", choice);

	switch (choice)
	{
		case 1:
			if ((size + 1) > MAX)
			{
				printf("No persons left to add");
			}
			else
			{
				addPerson(names, dates, &personArr, size, ++currentSerial);
				size++;
			}
			break;

		case 2:
			printArr(personArr, size);
			break;

		case 3:
			qsort(personArr, MAX, sizeof(Person), checkLatestDate);
			break;

		case 4:
			saveArrToFile(personArr, f_name, size);


		default:
			break;
	}
	#pragma endregion

	
}