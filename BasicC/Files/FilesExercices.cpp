#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
	char lastName[20];
	char firstName[20];
	int studentClass;
	char adress[256];
	int phone;
	int status;

} Student;

typedef struct
{
	char lastName[20];
	char firstName[20];
	char adress[256];
	int phone;
} Boger;

typedef struct
{
	int id;
	char lastName[20];
	char firstName[20];
	int initialMonths;
	int mounthsPassed;
	int behavior;
}  Prisoner;

typedef struct
{
	int day;
	int month;
	int year;
} Date;

typedef struct
{
	Date date;
	int participants;
} Event;

void handleStudentsFiles() // Ex 8
{
	Student stu;
	FILE *original;
	FILE *bogrim;

	Student arr[5] = { {"Yosi", "Han", 2, "kols", 50123, 1}, {"Bto", "Dvir", 2, "Yarqun", 213468, 1}, {"Matan", "Odded", 1, "Prazim", 132456, 1}, {"Tomer", "Rozi", 0, "asdasd", 456798, 1}, {"Ofir", "DelMaDigos", 2, "Rosh", 4659872, 1} };
    original = fopen("STUDENT.DAT", "wb");
    fwrite(arr, sizeof(Student), 5, original);
    fclose(original);
	Student muamdim2[5] = { {"Rami", "jkl", 0, "sad", 456798201, 1}, {"qwer", "yui", -1, "asddd", 258, 1}, {"asdjkasd", "qwoieu", 0, "aeae", 11145, 1}, {"rtgvb", "treq", 0, "ghjk", 45679, 1}, {"shlom", "fgh", 2, "jghgj", 1475, 1} };
	FILE *yud = fopen("MUMADIM.DAT", "wb");
	fwrite(muamdim2, sizeof(Student), 5, yud);
	fclose(yud);

	original = fopen("STUDENT.DAT", "r+b");
	bogrim = fopen("BOGRIM.DAT", "wb");
	if (!original || !bogrim)
	{
		exit(1);
	}

	// Code
	while (!feof(original))
	{
		fread(&stu, sizeof(Student), 1, original);
		if (stu.studentClass == 12)
		{
			stu.status = 0;
			fseek(original, -(long)sizeof(Student), SEEK_CUR);
			fwrite(&stu, sizeof(Student), 1, original);

			// New boger
			Boger b;
			strcpy(b.lastName, stu.lastName);
			strcpy(b.firstName, stu.firstName);
			strcpy(b.adress, stu.adress);
			b.phone = stu.phone;
			fwrite(&b, sizeof(Boger), 1, bogrim);
			fseek(bogrim, 0, SEEK_CUR); // Should be useless?
		}
	}

	fclose(original);
	fclose(bogrim);

	bogrim = fopen("BOGRIM.DAT", "wb");
	while (!feof(bogrim))
	{
		Boger b;
		fread(&b, sizeof(Boger), 1, bogrim);
		fseek(bogrim, 0, SEEK_CUR); // Should be useless?
		printf("Last Name: %s \n First Name: %s \n Adress: %s \n Phone: %d", b.lastName, b.firstName, b.adress, b.phone);
	}

	//Part 2 (B)
	FILE *mumadim = fopen("MUMADIM.DAT", "rb");
	original = fopen("STUDENT.DAT", "ab");
	if (!mumadim || !original)
	{
		exit(1);
	}
	while (!feof(mumadim))
	{
		fread(&stu, sizeof(Student), 1, mumadim);
		fwrite(&stu, sizeof(Student), 1, original);
	}

	fclose(original);
	fclose(mumadim);
}

void handlePrisonersFiles() // Ex 9
{
	// Varriables
	Prisoner pris;
	FILE *original = fopen("ASIRIM.DAT", "r+b");;

	if (!original)
	{
		exit(1);
	}

	// Code
	while (!feof(original))
	{
		fread(&pris, sizeof(Prisoner), 1, original);
		if (pris.behavior == 1)
		{
			pris.initialMonths -= 3;
			if (pris.initialMonths<pris.mounthsPassed)
			{
				printf("Prisoner: ID: %d \nFirst Name: %s \nLast Name: %s", pris.id, pris.firstName, pris.lastName);
				fseek(original, -(long)sizeof(Prisoner), SEEK_CUR);
				fwrite(&pris, sizeof(Prisoner), 1, original);
			}
			fseek(original, -(long)sizeof(Prisoner), SEEK_CUR);
			fwrite(&pris, sizeof(Prisoner), 1, original);
		}
	}

	fclose(original);
}

void handleEventManager() // Ex 10
{
	// Varriables
	Event e;
	FILE *original = fopen("HAPPY.DAT", "rb");
	int maxParticipants = 0, *moneEventsInDays = (int*)calloc(7, sizeof(int));
	int maxEventDay, maxEvents = 0;
	Date maxParticipantsDate;

	if (!original)
	{
		exit(1);
	}

	// Code
	while (!feof(original))
	{
		fread(&e, sizeof(Event), 1, original);
		if (e.participants > maxParticipants)
		{
			maxParticipants = e.participants;
			maxParticipantsDate = e.date;

			moneEventsInDays[e.date.day]++;
		}
	}

	fclose(original);

	printf("Date of the event with the most participants: %d-%d-%d", maxParticipantsDate.day, maxParticipantsDate.month, maxParticipantsDate.year);

	// B
	for (int i = 0; i < 7; i++)
	{
		if (moneEventsInDays[i] > maxEvents)
		{
			maxEvents = moneEventsInDays[i];
			maxEventDay = i;
		}
	}

	printf("Most events were held on day %d", maxEventDay);
}

int main()
{
	handleStudentsFiles();
	scanf("%d");
	return 0;
}