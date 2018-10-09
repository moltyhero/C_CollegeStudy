#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef char String[256];
typedef struct
{
	char name[256];
	float mark;
} Stu_Type;

void createFile()
{
	FILE *Fin;
	Stu_Type arr[5] = { {"yosi", 90 },
	{"Beni", 45} };
	Fin = fopen("Stu.DAT", "wb");
	fwrite(arr, sizeof(Stu_Type), 5, Fin);
	fclose(Fin);
}

void handleLowStudents()
{
	Stu_Type stu;
	FILE *Fin, *Ftemp;
	Fin = fopen("stu.DAT", "rb");
	Ftemp = fopen("Temp.DAT", "wb");
	if (Fin == NULL || Ftemp == NULL)
		exit(1);
	fread(&stu, sizeof(Stu_Type), 1, Fin);
	while (!feof(Fin))
	{
		if (stu.mark < 80)
		{
			stu.mark += 5;
		}
		fwrite(&stu, sizeof(Stu_Type), 1, Ftemp);
		fread(&stu, sizeof(Stu_Type), 1, Fin);
	}
	fclose(Fin);
	fclose(Ftemp);

	Fin = fopen("stu.DAT", "wb");
	Ftemp = fopen("Temp.DAT", "rb");
	if (Fin == NULL || Ftemp == NULL)
		exit(1);
	fread(&stu, sizeof(Stu_Type), 1, Ftemp);
	while (!feof(Ftemp))
	{
		printf("%s %f\n", stu.name, stu.mark);
		fwrite(&stu, sizeof(Stu_Type), 1, Fin);
		fread(&stu, sizeof(Stu_Type), 1, Ftemp);
	}
	fclose(Fin);
	fclose(Ftemp);
	scanf("%d");
}

// Get a file of numbers, order them and print them
void orderNumbers()
{
	int arrInt[] = { 2,5,2,7,4,9,4,7 };
	int min, num;
	FILE *originalFile, *tempFile, *EndFile;

	originalFile = fopen("Numbers.DAT", "wb");
	for (int i = 0; i < 8; i++)
	{
		fwrite(arrInt, sizeof(int), 1, originalFile);
	}
	fclose(originalFile);

	originalFile = fopen("Numbers.DAT", "rb");
	tempFile = fopen("Temp.DAT", "wb");
	if (originalFile == NULL || tempFile == NULL)
		exit(1);
	fread(&num, sizeof(int), 1, originalFile);

}
