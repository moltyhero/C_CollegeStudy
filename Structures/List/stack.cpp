#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void  stack_init(stack *s)
{
	s->top = NULL;
}

int stack_empty(stack s)
{
	return (s.top == NULL);
}

int stack_full(stack s)
{
	return 0;
}

void stack_push(stack *s, stack_item x)
{
	struct node_type *temp = (node_type*)malloc(sizeof(struct node_type));
	temp->info = x;
	temp->next = s->top;
	s->top = temp;
}

stack_item stack_pop(stack * s)
{
	if (!stack_empty(*s))
	{
		struct node_type *temp = s->top;
		stack_item data = s->top->info;
		s->top = temp->next;
		free(temp);
		return data;
	}
}

stack_item stack_top(stack s)
{
	if (!stack_empty(s))
	{
		stack_item data = (s.top)->info;
		return data;
	}
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
		stack_push(s, stack_pop(&tempPrint));
	}

	while (!stack_empty(helper))
	{
		stack_push(&tempPrint, stack_pop(&helper));
	}

	while (!stack_empty(tempPrint))
	{
		printf("%d \n", stack_pop(&tempPrint));
	}
}