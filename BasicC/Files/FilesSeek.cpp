#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

// This program updates directly the grade of the student

typedef struct
{
	char name[20];
	int mark;
} student;

int main2()
{
	//int x;
	student arr[3] = { {"Yosi", 85}, {"Moshe", 90}, {"Yona", 60} };
	student stu;

	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", arr[i].name, arr[i].mark);
	}

	FILE *fp;
	fp = fopen("FileDAT.DAT", "wb");
	fwrite(arr, sizeof(student), 3, fp);
	fclose(fp);

	
	return 0;
}

int main()
{
	//int x;
	student arr[3] = { {"Yosi", 85}, {"Moshe", 90}, {"Yona", 60} };
	student stu;

	FILE *fp;

	// Change moshe grade
	fp = fopen("FileDAT.DAT", "r+b");
	fwrite(arr, sizeof(student), 3, fp);
	fclose(fp);

	fp = fopen("FileDAT.DAT", "r+b");

	fread(&stu, sizeof(student), 1, fp);
	int b = 0;
	while (!feof(fp) && b != 1)
	{
		if (!strcmp("Moshe", stu.name))
		{
			//printf("11\n");
			stu.mark = 95;
			fseek(fp, -(long)sizeof(student), SEEK_CUR);
			fwrite(&stu, sizeof(student), 1, fp);
			//fseek(fp, 0, SEEK_CUR); // Should be useless?
			b = 1;
		}
		fread(&stu, sizeof(student), 1, fp);
	}
	fclose(fp);
	fp = fopen("FILEDAT.DAT", "rb");
	fread(arr, sizeof(student), 3, fp);
	fclose(fp);
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", arr[i].name, arr[i].mark);
	}

	scanf("%d");

	return 0;
}