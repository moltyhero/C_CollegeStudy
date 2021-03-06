#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void  stack_init(stack *s) 
{
	s->top = -1;
	s->data = NULL;
}

int stack_empty(stack s)
{
	return (s.top == -1);
}

int stack_full(stack s)
{
	return 0;
}

void stack_push(stack *s, stack_item x)
{
	stack_item *temp = (stack_item*)realloc(s->data, sizeof(stack_item) * (s->top + 2));
	if (temp == NULL)
		return;
	else 
	{
		s->data = temp;
		s->data[++s->top] = x;
	}
}

stack_item stack_pop(stack * s)
{
	if (!stack_empty(*s))
	{
		stack_item x = s->data[s->top--];
		s->data = (stack_item*)realloc(s->data, sizeof(stack_item) * s->top + 1);
		return x;
	}
}

stack_item stack_top(stack s)
{
	if (!stack_empty(s))
		return s.data[s.top];
	return 0;
}

void stack_print(stack *s)
{
	stack tempPrint;
	stack helper;
	stack_init(&tempPrint);
	stack_init(&helper);

	while (!stack_empty(*s))
	{
		stack_push(&tempPrint, stack_top(*s));
		stack_push(&helper, stack_pop(s));
	}

	while (!stack_empty(tempPrint))
	{
		stack_push(s, stack_top(tempPrint));
	}

	while (!stack_empty(helper))
	{
		stack_push(&tempPrint, stack_top(helper));
	}
	
	while (!stack_empty(tempPrint))
	{
		printf("%d \n" ,stack_pop(&tempPrint));
	}
}
