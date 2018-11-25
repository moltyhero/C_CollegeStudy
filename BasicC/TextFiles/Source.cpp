// Text files

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void main()
{
	FILE *Fin;
	int ch;

	Fin = fopen("text.txt", "rt");
	if (!Fin)
	{
		printf("Not good");
		exit(1);
	}
	
	do
	{
		ch = fgetc(Fin); // משיג את קובץ הטקסט
		// out char (ch) // יש להכניס קוד האסקי שמומר לנו

	} while (ch !=EOF);
	
	fclose(Fin);
	// Car = fgetc(מצביע לקובץ);

}

void main()
{
	FILE *FSource, *Fdes;
	int ch;
	FSource = fopen("textFile.txt", "rt");
	Fdes = fopen("textDes.txt", "wt");

	if (!FSource || !Fdes)
	{
		// Error
		exit(1);
	}

	do
	{
		ch = fgetc(FSource);
		if (ch != ' ' && ch != EOF)
		{
			fputc(ch, Fdes);
		}
	} while (ch !=EOF);

	fclose(FSource);
	fclose(Fdes);
}