#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int queue_item;

typedef struct node_type
{
	queue_item info;
	struct node_type *next;
} node;

typedef struct
{
	node *head, *rear;
} queue;

void queue_init(queue *q);

int queue_empty(queue q);

void enqueue(queue *q, queue_item x);

queue_item dequeue(queue *q);

queue_item queue_top(queue q);

void queue_print(queue q);

queue copy(queue q);

