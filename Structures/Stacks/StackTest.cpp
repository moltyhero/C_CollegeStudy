#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

int findMax(stack s)
{
	int max = 0;
	while (!stack_empty(s))
	{
		if (stack_top(s) > max)
			max = stack_top(s);
		stack_pop(&s);
	}
	printf("Max is %d" , max);
	return max;
}

void moveMaxToHead(stack *s)
{
	int max;
	stack temp;

	stack_init(&temp);
	max = findMax(*s);

	while (!stack_empty(*s))
	{
		if (!stack_top(*s) == max)
		{
			stack_push(&temp, stack_pop(s));
		}
		else
		{
			stack_pop(s);
			while (!stack_empty(temp))
			{
				stack_push(s, stack_pop(&temp));
			}
			break;
		}
	}
	stack_push(s, max);

}

void moveMaxesToHead(stack *s)
{
	int max;
	int mone = 0;
	stack temp;

	stack_init(&temp);
	max = findMax(*s);

	while (!stack_empty(*s))
	{
		if (!stack_top(*s) == max)
		{
			stack_push(&temp, stack_pop(s));
		}
		else
		{
			stack_pop(s);
			mone++;
		}
	}
	while (!stack_empty(temp))
	{
		stack_push(s, stack_pop(&temp));
	}
	for (int i = 0; i < mone; i++)
	{
		stack_push(s, max);
	}
}

void sortStack(stack *s)
{
	stack temp;
	stack_init(&temp);

	while (!stack_empty(*s))
	{
		moveMaxesToHead(s);
		stack_push(&temp, stack_pop(s));
	}
	while (!stack_empty(temp))
	{
		stack_push(s, stack_pop(&temp));
	}

}

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

	findMax(s);

	// Please stop so I can see what happend
	scanf ("%d");
}