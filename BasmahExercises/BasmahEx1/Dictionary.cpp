#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Adds a word to the dictionary
void AddNewWord(char* iszNewWord, char* iszWordDef)
{
	FILE *fp;
	if (!(fp = fopen("Dictionary.dat", "at")))
	{
		printf("Could not open file");
		exit(1);
	}
	fprintf(fp, "%s %s\n", iszNewWord, iszWordDef);
	if (fclose(fp))
	{
		printf("Could not close file");
		exit(1);
	}
}

// Connects a word and it's definition 
void JoinStrings(char** iopszFirstString,
				 char* iszSecondString)
{
	*iopszFirstString = (char*)realloc(*iopszFirstString, sizeof(char) *
		(strlen(*iopszFirstString) + strlen(iszSecondString)));
	strcat(*iopszFirstString, "-");
	strcat(*iopszFirstString, iszSecondString);
}

// Gets a word and returns a string which contains the word and it's definiton
char* GetWordDefinition(char* iszWord)
{
	FILE *fp;
	char* currentReadWord = (char*)malloc(sizeof(char)*21);
	char* currentReadDefinition = (char*)malloc(sizeof(char)*201);

	if (!(fp = fopen("Dictionary.dat", "rt")))
	{
		printf("Could not open file\n");
		exit(1);
	}

	fscanf(fp, "%s %s", currentReadWord, currentReadDefinition);
	while (strcmp(currentReadWord, iszWord) && !feof(fp))
	{
		fscanf(fp, "%s %s", currentReadWord, currentReadDefinition);
	}

	if (fclose(fp))
	{
		printf("Could not close file\n");
		exit(1);
	}

	if (!feof(fp))
	{
		JoinStrings(&currentReadWord, currentReadDefinition);
		free(currentReadDefinition);
		return currentReadWord;
	}
	else return NULL;
}

// Prints all the words (without definition) that start in a given letter
void PrintWordOf(char icStartChar)
{
	FILE *fp;
	char* currentReadWord = (char*)malloc(sizeof(char)*21);
	char* currentReadDefinition = (char*)malloc(sizeof(char)*201);

	if (!(fp = fopen("Dictionary.dat", "rt")))
	{
		printf("Could not open file\n");
		exit(1);
	}

	fscanf(fp, "%s %s", currentReadWord, currentReadDefinition);

	while (!feof(fp))
	{
		if (currentReadWord[0] == icStartChar)
		{
			printf("%s\n", currentReadWord);
		}
		fscanf(fp, "%s %s", currentReadWord, currentReadDefinition);
	}

	free(currentReadWord);
	free(currentReadDefinition);

	if (fclose(fp))
	{
		printf("Could not close file\n");
		exit(1);
	}

}

int main()
{
	// Varriables
	int choice;
	char* word = (char*)malloc(sizeof(char) * 21);
	char* definition = (char*)malloc(sizeof(char) * 201);
	char letter;

	// Code

	do
	{
		// Menu
		printf("\nSelect an option:\n");
		printf("1 to get a definition\n");
		printf("2 to insert a word\n");
		printf("3 to print every word that start with a letter\n");

		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
			{
				printf("\nEnter a word to find it's definition\n");
				scanf("%s", word);
				char *definition = GetWordDefinition(word);
				printf("%s\n", definition);
				break;
			}
			case 2:
			{
				printf("\nEnter a new word and it's definition to insert into the dictionary\n");
				scanf("%s", word);
				scanf("%s", definition);
				AddNewWord(word, definition);
				break;
			}
			case 3:
			{
				printf("\nEnter a letter to find all the words that start with that letter\n");
				letter = getchar();
				letter = getchar();
				PrintWordOf(letter);
				break;
			}
		}
	}
	while (choice!=4);
	free(word);
	free(definition);

	// Please stop so I can see what happend
	getchar();
	getchar();
}