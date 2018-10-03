#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct
{
	int hours;
	int minutes;
} Time;

typedef struct
{
	int serial;
	int price;
	int stock;
} Planet;

typedef struct
{
	int serial;
	char name[256];
	int releaseYear;
	int isAvailable;
	int numberOfcopies;
} Movie ;

typedef struct
{
	char classSubject[256];
	char teacherName[256];
	int roomNumber;
} LearningHour;

typedef struct
{
	int num1;
	int num2;
	int read = 0;
} BingoCell;

typedef struct
{
	int color;
	int num;
} Stone;


Time difference(Time Time1, Time Time2)
{
	Time newTime;
	if (Time1.hours > Time2.hours)
	{
		newTime.hours = Time1.hours - Time2.hours;
		newTime.minutes = Time1.minutes - Time2.minutes;
	}
	else
	{
		newTime.hours = Time2.hours - Time1.hours;
		newTime.minutes = Time2.minutes - Time1.minutes;
	}
	return newTime;
}

void planetSell()
{
	Planet planetArr[5];
	int serial, numberOfPlanets;

	scanf("%d %d", &serial, &numberOfPlanets);
	while (serial != -999)
	{
		for (int i = 0; i < 5; i++)
		{
			if (serial == planetArr[i].serial)
			{
				if (numberOfPlanets>planetArr[i].stock)
				{
					printf("Cannot make the sale");
				}
				else
				{
					planetArr[i].stock -= numberOfPlanets;
					printf("Left in stock for current planet: %d", planetArr[i].stock);
				}
				break;
			}
		}
		scanf("%d %d", &serial, &numberOfPlanets);
	}
}

void handleMovieStore()
{
	int n = 10, mone=0;
	Movie movies[10];
	Movie takenMovies[10];

	for (int i = 0; i < n; i++)
	{
		printf("Enter movie serial number, name, year of release, wheter is in the library and number of copies");
		scanf("%d %s %d %d %d", &movies[i].serial, &movies[i].name, &movies[i].releaseYear, &movies[i].isAvailable, &movies[i].numberOfcopies);	
	}

	for (int i = 0; i < n; i++)
	{
		if (movies[i].isAvailable == 0)
		{
			takenMovies[mone] = movies[i];
			mone++;
		}
	}
}

void handleSchedule(LearningHour schedule[5][9])
{
	char **classSubjects;
	char *ptr;
	int roomSum[101], subjectFound, moneSubjects = 0, highestRoomCount = 0, highestRoomCountNumber;


	classSubjects = (char**)malloc(sizeof(char**) * 45);
	if (classSubjects == NULL)
	{
		exit(NULL);
	}

	// Check how many subjects does the class learn
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			ptr = classSubjects[0];
			subjectFound = 0;
			while (ptr!=NULL && !subjectFound)
			{
				if (strcmp(ptr, schedule[i][j].classSubject) == strlen(schedule[i][j].classSubject))
				{
					subjectFound = 1;
				}
				else
				{
					ptr++;
				}
			}
			if (!subjectFound)
			{
				classSubjects[moneSubjects] = (char*)malloc(sizeof(char) * strlen(schedule[i][j].classSubject));
				if (classSubjects[moneSubjects] == NULL)
				{
					exit(NULL);
				}
				strcpy(classSubjects[moneSubjects], schedule[i][j].classSubject);
				moneSubjects++;
			}
		}
	}

	// Check in which room the class learn the most hours
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			roomSum[schedule[i][j].roomNumber]++;
		}
	}

	for (int i = 1; i < 101; i++)
	{
		if (roomSum[i] > highestRoomCount)
		{
			highestRoomCount = roomSum[i];
			highestRoomCountNumber = i;
		}
	}

	printf("The class learns %d different classes", moneSubjects);
	printf("Most hours are learned in room %d", highestRoomCountNumber);

	// Happy hour
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (schedule[i][j].roomNumber == 0)
			{
				printf("The class has happy hour on day %d", i);
				break;
			}
		}
	}
}

int searchNumbersInBingoArr (BingoCell arr[10][10], int num1, int num2)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j].num1 == num1 || arr[i][j].num2 == num1)
			{
				if (arr[i][j].num1 == num2 || arr[i][j].num2 == num2)
				{
					arr[i][j].read = 1;
				}
			}
		}
	}
	return 1;
}
void doubleBingo(BingoCell arr[10][10])
{
	time_t t;
	srand((unsigned)time(&t));

	int firstRand, secondRand, mone=0, madeIt = 0;

	while (!madeIt)
	{
		firstRand = 1 + rand() % 49;
		secondRand = 1 + rand() % 49;

		if (searchNumbersInBingoArr(arr, firstRand, secondRand))
		{
			mone++;
		}

		if (mone > 10)
		{
			for (int i = 0; i < 10; i++)
			{
				if (arr[i][i].read == 1)
				{
					for (int j = 0; j < 10; j++)
					{
						if (arr[i][j].read == 0)
						{
							madeIt = 0;
							break;
						}
					}
					if (madeIt)
					{
						printf("Row %d", i);
					}
					else
					{
						for (int j = 0; j < 10; j++)
						{
							if (arr[j][i].read == 0)
							{
								madeIt = 0;
								break;
							}
						}
						if (madeIt)
						{
							printf("Row %d", i);
							break;
						}
					}
				}
				if (madeIt)
					break;
			}
		}
	}
}

void stonesGame()
{
	time_t t;
	srand((unsigned)time(&t));

	Stone player1[20];
	Stone player2[20];

	for (int i = 0; i < 20; i++)
	{
		player1[i].num = 1 + rand() % 5;
		player2[i].num = 1 + rand() % 5;
		player1[i].color = 1 + rand() % 4;
		player2[i].color = 1 + rand() % 4;
	}
}