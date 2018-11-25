// MagicPen.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

// Global darriable definition
char *g_szMainString = NULL;

// Functions prototypes
void AddText();
void Update();
void DeleteChars();
void AddToFile();
void PrintStr();


//-----------------------------------------------------------------------------
//									 Magic Pen
//									-----------
//
// General : The program handles text inputs.
//
// Input : Strings.
//
// Process : Management of string in files and in the program itself.
//
// Output : None.
//
//-----------------------------------------------------------------------------
// Programmer : Matan Oded
// Date : 15.11.2018
//-----------------------------------------------------------------------------
int main()
{
	// Varriables
	int choice;

	// Code section

	do
	{
		// Menu
		printf("\nSelect an option:\n");
		printf("1 Add\n");
		printf("2 Update\n");
		printf("3 Delete\n");
		printf("4 Add to File\n");

		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
			{
				AddText();
				break;
			}
			case 2:
			{
				Update();
				break;
			}
			case 3:
			{
				DeleteChars();
				break;
			}
			case 4:
			{
				AddToFile();
			}
			default:
			{
				break;
			}
		}
	}
	while (choice != 5);

	// Please stop so I can see what happend
	scanf("%d");
}

//-----------------------------------------------------------------------------
//								   	 Add Text
//									---------
//
// General : The function adds text to the global string
//
// Parameters: None
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void AddText()
{
	// Varriables definitions
	int nLength;
	char *szNew;

	// Code section

	printf("Enter length of the string\n");
	scanf("%d", &nLength);

	szNew = (char*)malloc((nLength+2)*sizeof(char));
	printf("Enter the string\n");
	scanf("%s", szNew);
	strcat(szNew, " ");

	if (g_szMainString== NULL)
	{
		g_szMainString = (char*)malloc(sizeof(char) * (nLength + 1));
	}
	else
	{
		g_szMainString = (char*)realloc(g_szMainString, sizeof(char) *
			(strlen(g_szMainString) + nLength + 1));
	}
	strcat(g_szMainString, szNew);
	free(szNew);

}

//-----------------------------------------------------------------------------
//								   		Update
//									  ---------
//
// General : The function updates the text to the global string
//
// Parameters: None
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void Update()
{
	// Varriables definitions
	int nLocation, nCharsToUpdate;
	char *szUpdated;

	// Code section

	printf("Enter start position of update\n");
	scanf("%d", &nLocation);

	printf("Enter number of characters\n");
	scanf("%d", &nCharsToUpdate);

	szUpdated = (char*)malloc((nCharsToUpdate + 1) * sizeof(char));
	printf("Enter the string");
	scanf("%s", szUpdated);

	for (int i = nLocation-1; i < nCharsToUpdate; i++)
	{
		g_szMainString[i] = szUpdated[i-nLocation+1];
	}
}

//-----------------------------------------------------------------------------
//								   	  Delete Chars
//									---------
//
// General : The function deletes a number of characters from the global string
//
// Parameters: None
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void DeleteChars()
{
	// Varriables definitions
	int nCharsToDelete;

	// Code section
	printf("Enter number of characters to delete\n");
	scanf("%d", &nCharsToDelete);

	g_szMainString = (char*)realloc(g_szMainString, strlen(g_szMainString) - nCharsToDelete);
	if (g_szMainString[strlen(g_szMainString)] != '\0')
	{
		g_szMainString = (char*)realloc(g_szMainString, strlen(g_szMainString) + 1);
		strcat(g_szMainString, "\0");
	}
}

//-----------------------------------------------------------------------------
//								   Add To File
//								  	---------
//
// General : The function creates/replaces a file with text to the global
// string in it
//
// Parameters: None
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void AddToFile()
{
	// Files definitions
	FILE *fp;

	// Varriables definitions
	char szFileName[20];

	// Code section

	printf("Enter name of file to save the string into");
	scanf("%s", szFileName);
	if (!(fp = fopen(szFileName, "wt")))
	{
		exit(1);
	}
	
	fprintf(fp, "%s", g_szMainString);

	if (fclose(fp))
	{
		exit(1);
	}
	free(g_szMainString);
}