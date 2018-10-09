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

int main()
{
	int x;
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

	fp = fopen("FileDAT.DAT", "r+b");

	return 0;
}