#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

int kdimut(char op1, char op2)
{
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
		return 1;
	else return 0;
}

int checkIfOperand(char c)
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return 1;
	return 0;
}


void inFixToPostFix(char inFix[256])
{
	stack s;
	int i=0;
	char postFix[256];
	char *postFixPtr = postFix;

	stack_init(&s);
	
	while (inFix[i]!='\0')
	{
		if (!checkIfOperand(inFix[i]))
		{
			postFixPtr[0] = inFix[i];
			postFixPtr++;
		}
		else
		{
			if (!stack_empty(s))
			{
				if (kdimut(inFix[i], stack_top(s)))
				{
					//postFixPtr[0] = inFix[i];
					stack_push(&s, inFix[i]);
				}
				else
				{
					while (!kdimut(inFix[i], stack_top(s)) && !stack_empty(s))
					{
						postFixPtr[0] = stack_pop(&s);
						postFixPtr++;
					}
					stack_push(&s, inFix[i]);
				}
			}
			else stack_push(&s, inFix[i]);
		}
		i++;
		
	}

	while (!stack_empty(s))
	{
		postFixPtr[0] = stack_pop(&s);
		postFixPtr++;
	}
	postFixPtr[0] = '\0';

	puts(postFix);
}

void main()
{
	// Varriables
	char str[] = "A*B";

	// Code
	inFixToPostFix(str);

	// Please stop so I can see what happend
	scanf ("%d");
}