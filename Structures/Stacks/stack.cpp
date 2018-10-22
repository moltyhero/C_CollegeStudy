#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void  stack_init(stack *s) 
{
	s->top = -1;
}

int stack_empty(stack s)
{
	return (s.top == -1);
}

int stack_full(stack s)
{
	return (s.top == STACK_MAX_SIZE-1);
}

void stack_push(stack * s, stack_item x)
{
	if (!stack_full(*s)) 
	{
		s->data[++s->top] = x; 
	}
}

stack_item stack_pop(stack * s)
{
	if (!stack_empty(*s))
		return s->data[s->top--];
	return 0;
}

stack_item stack_top(stack s)
{
	if (!stack_empty(s))
		return s.data[s.top];
	return 0;
}

void stack_print(stack s)
{
	while (!stack_empty(s))
	{
		printf("%d \n" ,stack_pop(&s));
	}
}
