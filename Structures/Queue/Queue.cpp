#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Queue.h"

void queue_init(queue *q)
{
	q->head = q->rear = NULL;
}

int queue_empty(queue q)
{
	return (q.head == NULL);
}

void enqueue(queue *q, queue_item x)
{
	node *a = (node*)malloc(sizeof(node));
	a->info = x; a->next = NULL;
	if (queue_empty(*q))
	{
		q->head = q->rear = a;
	}
	else
	{
		q->rear->next = a;
		q->rear = a;
	}
}

queue_item dequeue(queue *q)
{
	queue_item x;
	node *ptr = q->head;
	if (!queue_empty(*q))
	{
		x = q->head->info;
		q->head = q->head->next;

		if (q->head == NULL)
		{
			q->rear = NULL;
		}
		free(ptr);
		return x;
	}
	
}

queue_item queue_top(queue q)
{
	if (!queue_empty(q))
	{
		return q.head->info;
	}
}

queue copy(queue q)
{
	queue newQ;
	queue temp;

	queue_init(&newQ);
	queue_init(&temp);

	while (!queue_empty(q))
	{
		enqueue(&newQ, queue_top(q));
		enqueue(&newQ, dequeue(&q));
	}

	while (!queue_empty(temp))
	{
		enqueue(&q, dequeue(&temp));
	}
}

void queue_print(queue q)
{
	queue temp = copy(q);

	while (!queue_empty(temp))
	{
		printf("%d, ", dequeue(&temp));
	}
}