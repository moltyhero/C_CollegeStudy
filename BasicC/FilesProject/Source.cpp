#define _CRT_SECURE_NO_WARNINGS
#define LEN 20
#define MAX 10
#define COLS 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <malloc.h>

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
	Date *pDate; // Pointer to date structer
} Person;

// Gets an array of names, array of dates, pointer to an array of person, the size of the array, and the current serial to be given
// Add a person from the names array with his matching date from the dates array to the person array
void addPerson(const char *names[MAX], const int dates[MAX][COLS], Person** personArr, int size, int serial) // Pressed 1
{
	*personArr = (Person*)realloc(*personArr, (size +1) * sizeof(Person));

	Person temp;
	//temp.serial_num = size;
	strcpy(temp.full_name, names[size]);
	
	//Date date;
	temp.serial_num = serial;
	temp.pDate = (Date*)malloc(sizeof(Date));
	temp.pDate->day = dates[size][0];
	temp.pDate->month = dates[size][1];
	temp.pDate->year = dates[size][2];


	(*personArr)[size] = temp;

	printf("The new added person is %s, %d/%d/%d\n", temp.full_name, temp.pDate->day, temp.pDate->month, temp.pDate->year);
}

// Gets an array of person and it's size, print it's contents
void printArr(Person* personArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Person number %d is %s, born in %d/%d/%d \n", personArr[i].serial_num, personArr[i].full_name, personArr[i].pDate->day, personArr[i].pDate->month, personArr[i].pDate->year);
	}
}

// Compares 2 dates for quesort function specified in case 3 on the main function
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

// The methods gets the person array, file name (f_name), and size of the array, and copies the contents of the array to the file
void saveArrToFile(Person *personArr, const char *f_name, int size)
{
	FILE *file = fopen(f_name, "wt");
	if (!file)
	{
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%d %s %d %d %d\n", personArr[i].serial_num, personArr[i].full_name, 
				personArr[i].pDate->day, personArr[i].pDate->month, personArr[i].pDate->year);
	}
	
	fclose(file);
}

// The method takes the file with the specified name "f_name" and copies all it's contents to the array, reseting it's size
void saveFileToArr(Person **personArr, const char *f_name, int *size)
{
	FILE *file = fopen(f_name, "rt");
	if (!file)
	{
		exit(1);
	}
	*size = 0;
	while (!feof(file))
	{
		*personArr = (Person*)realloc(*personArr, ((*size) + 1) * sizeof(Person));
		(*personArr)[*size].pDate = (Date*)malloc(sizeof(Date));
		fscanf(file, "%d %s %d %d %d\n", &((*personArr)[*size].serial_num), &((*personArr)[*size].full_name),
				&((*personArr)[*size].pDate->day), &((*personArr)[*size].pDate->month), &((*personArr)[*size].pDate->year));

		(*size)++;
	}

	if (fclose(file))
	{
		exit(1);
	}
}

int main()
{
	#pragma region 	Pre-defined

	// Arrays of names
	const char *names[MAX] = { "Sasson_Sassoni","Pooh","James_Bond","Elvis_is_Alive!",
		"Shilgiya","Cleopatra","Sissoo_VeSimmhoo" }; // Continue entering...
	// Matrix of dates of birth
	const int dates[MAX][COLS] = {
		{10,1,1988},
		{12,12,1948},
		{4,12,1970},
		{11,11,1890},
		{11,11,1948},
		{1,10,1213},
		{12,11,1948} };

	// The file name
	const char *f_name = "Persons.txt";

	#pragma endregion

	#pragma region Written code
	char choice; // User current choice of action
	Person* personArr = NULL; // The array of persons
	int size = 0; // Size of the person array
	int currentSerial = 1; // Current serial to be assigned

	scanf("%c", &choice);

	while (choice !='E' || choice !='e') // The program exit when the user enters 'e' or 'E'
	{
		switch (choice)
		{
			case '1':
				if ((size + 1) > 7)
				{
					printf("No persons left to add");
				}
				else
				{
					addPerson(names, dates, &personArr, size, ++currentSerial);
					size++;
				}
				break;

			case '2':
				printArr(personArr, size);
				break;

			case '3':
				qsort(personArr, size, sizeof(Person), checkLatestDate);
				break;

			case '4':
				saveArrToFile(personArr, f_name, size);
				break;

			case '5':
				saveFileToArr(&personArr, f_name, &size);
				break;

			default:
				break;
		}
		scanf("%c", &choice);
	}
	
	#pragma endregion
	return 0;
	
}