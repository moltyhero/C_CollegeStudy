#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

void main()
{
	// Varriables
	int x;
	stack s;
	
	// Code
	stack_init(&s);
	stack_push(&s, 9);
	stack_push(&s, 5);
	stack_push(&s, 4);
	stack_push(&s, 10);
	stack_push(&s, 5);
	stack_print(s);
	stack_print(s);

	// Please stop so I can see what happend
	scanf ("%d");
}