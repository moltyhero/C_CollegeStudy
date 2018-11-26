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
void PutFileIntoString();


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
		printf("4 Print the string\n");
		printf("5 Add to File\n");
		printf("6 Get from File\n");

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
				PrintStr();
				break;
			}
			case 5:
			{
				AddToFile();
				break;
			}
			case 6:
			{
				PutFileIntoString();
				break;
			}
			default:
			{
				break;
			}
		}
	}
	while (choice <= 6);

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

	nLength	= strlen(szNew);

	if (g_szMainString== NULL)
	{
		g_szMainString = _strdup(szNew);
	}
	else
	{
		g_szMainString = (char*)realloc(g_szMainString, sizeof(char) *
			(strlen(g_szMainString) + nLength + 1));
		strcat(g_szMainString, szNew);
	}
	
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
	printf("Enter the string\n");
	scanf("%s", szUpdated);

	for (int i = 0; i < nCharsToUpdate; i++)
	{
		g_szMainString[i+nLocation-1] = szUpdated[i];
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
	int nLength = strlen(g_szMainString);

	// Code section
	printf("Enter number of characters to delete\n");
	scanf("%d", &nCharsToDelete);

	g_szMainString = (char*)realloc(g_szMainString, sizeof(char)*(strlen(g_szMainString) - nCharsToDelete)+1);
	g_szMainString[nLength-nCharsToDelete] = 0;
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

	printf("Enter name of file to save the string into\n");
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

//-----------------------------------------------------------------------------
//								   Put File Into String
//								  		---------
//
// General : The function gets the string within a file and put it into the 
// global string
//
// Parameters: None
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void PutFileIntoString()
{
	// Files definitions
	FILE *fp;
	char cTemp;
	int i = 0;

	// Varriables definitions
	char szFileName[20];

	// Code section

	printf("Enter name of file to get the string from\n");
	scanf("%s", szFileName);
	if (!(fp = fopen(szFileName, "rt")))
	{
		exit(1);
	}

	g_szMainString = NULL;
	fscanf(fp, "%c", &cTemp);
	

	while (!feof(fp))
	{
		g_szMainString = (char*)realloc(g_szMainString, sizeof(char)*(i+1));
		g_szMainString[i] = cTemp;
		i++;
		fscanf(fp, "%c", &cTemp);
	}
	g_szMainString[i] = 0;

	if (fclose(fp))
	{
		exit(1);
	}
}

//-----------------------------------------------------------------------------
//								    Print String
//								  	---------
//
// General : The function prints the global string
// 
//
// Parameters: None
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void PrintStr()
{
	puts(g_szMainString);
}