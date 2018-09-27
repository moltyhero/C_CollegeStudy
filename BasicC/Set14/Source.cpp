#define _CRT_SECURE_NO_WARNINGS
#define n 256
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef char String[n];

// Not working
void trag31()
{ // בהנחה שהפולינומים הנקלטים הם מהחזקה הגבוהה לנמוכה

	// Variables
	int exponent1, exponent2, number1, number2, progress = 3, first = 1;
	String original1, original2, endPolynom, temp;
	char *polynom1, *polynom2;

	// Code
	printf("Please enter polynom\n");
	gets_s(original1);

	_flushall();
	printf("Please enter polynom\n");
	_flushall();
	gets_s(original2);

	polynom1 = strtok(original1, " ");
	polynom2 = strtok(original2, " ");

	// Handle each couple until the final one
	while (polynom1!=NULL && polynom2!=NULL)
	{
		if (progress == 1)
		{
			number1 = atoi(polynom1); // Find the number
			polynom1 = strtok(NULL, " ");
			exponent1 = atoi(polynom1); //Find the exponent
		}
		else if (progress == 3)
		{
			number1 = atoi(polynom1); // Find the number
			polynom1 = strtok(NULL, " ");
			exponent1 = atoi(polynom1); //Find the exponent

			number2 = atoi(polynom2);
			polynom2 = strtok(NULL, " ");
			exponent2 = atoi(polynom2);
			first = 0;
		}
		else
		{
			number2 = atoi(polynom2);
			polynom2 = strtok(NULL, " ");
			exponent2 = atoi(polynom2);
		}


		if (exponent1>exponent2)
		{
			sprintf(temp, "%d", number1); // Transfer the number to string
			strcat(endPolynom, temp); // Add the number to the end string
			sprintf(temp, "%d", exponent1); // Add the exponent to the end string
			strcat(endPolynom, temp); // Add the exponent to the end string
			polynom1 = strtok(NULL, " ");
			progress = 1;
		}
		else if (exponent1 == exponent2)
		{
			number1 += number2;
			sprintf(temp, "%d", number1);
			strcat(endPolynom, temp);
			sprintf(temp, "%d", exponent1);
			strcat(endPolynom, temp);
			progress = 3;
		}
		else
		{
			sprintf(temp, "%d", number2);
			strcat(endPolynom, temp);
			sprintf(temp, "%d", exponent2);
			strcat(endPolynom, temp);
			polynom2 = strtok(NULL, " ");
			// progress = 2; Just for clarification
		}
	}

	if (polynom1 == NULL)
	{
		strcat(endPolynom, polynom2);
	}
	else if (polynom2 == NULL)
	{
		strcat(endPolynom, polynom1);
	}
}

void targ32()
{
	char mat[11][11];
	String word;
	int k = 1, found = 0;

	printf("Please enter the Matrix\n");
	for (int i = 0; i < 10; i++)
	{
		gets_s(mat[i]);
	}

	printf("Please enter the word to search\n");
	gets_s(word);
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (mat[i][j] == word[0]) // Check if the first letter is the same
			{
				for (int l = -1; l < 2; l++)
				{
					for (int m = -1; m < 2; m++)
					{
						if (i + l * strlen(word) > 0 && i + l * strlen(word) < 10 && j + m * strlen(word) > 0 && j + m * strlen(word) < 10)
						{
							k = 0;
							while (word[k] != NULL) // Check every letter
							{
								if (mat[i + l * k][j + m * k] != word[k])
									break;
								k++;
							}
							if (word[k] == NULL)
							{
								found = 1;
								printf("[%d][%d]", i, j);
							}
						}
						if (found)
							break;
					}
					if (found)
						break;
				}
				if (found)
					break;
			}
			if (found)
				break;
		}
		if (found)
			break;
	}
	if (!found)
	{
		printf("Not Found");
	}
}

void replace()
{
	char *ptr, *temp;
	String str, replaceStr, replaceTo, following;


	printf("Please enter a string\n");
	gets_s(str);
	printf("Please enter a string to replace\n");
	gets_s(replaceStr);
	printf("Please enter replacing string\n");
	gets_s(replaceTo);

	ptr = strstr(str, replaceStr);
	while (ptr!=NULL)
	{
		temp = (ptr + strlen(replaceStr));
		strcpy(following, temp);

		for (int i = 0; i < strlen(replaceTo); i++)
		{
			ptr[0] = replaceTo[i];
			ptr++;
		}

		strcpy(ptr, following);

		ptr = strstr(str, replaceStr);
	}

	printf("%s", str);
}

void lastIndexOf()
{
	char *ptr, *temp;
	String str, searchStr;

	printf("Please enter a string\n");
	gets_s(str);
	printf("Please enter a string to search\n");
	gets_s(searchStr);

	ptr = strstr(str, searchStr);
	temp = ptr;
	while (ptr!=NULL)
	{
		temp = ptr;
		ptr++;
		ptr = strstr(ptr, searchStr);
	}
	ptr = str;

	for (int i = 0; i < strlen(str); i++)
	{
		if (temp == (ptr + i))
		{
			printf("%d", i);
		}
	}
}

int main()
{
	lastIndexOf();
	scanf("%d");
	return 0;
}