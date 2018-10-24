#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Queue.h"

int distanceBetweenElements(queue q, int x, int y)
{
	int temp = NULL, mone=0;
	while (!queue_empty(q))
	{
		if (queue_top(q) == x || queue_top(q) == y)
		{
			if (temp)
			{
				if (temp == queue_top(q))
				{
					mone = 0;
				}
				else
				{
					return mone;
				}
			}
			else temp = queue_top(q);
		}
		else
		{
			mone++;
		}
		dequeue(&q);
	}
	return -1;
}

int findLowestElementOnBoth(queue q1, queue q2)
{
	int min;
	queue temp1 = copy(q1);
	queue temp2 = copy(q2);

	min = dequeue(&temp1);
	while (!queue_empty(temp1) && !queue_empty(temp2))
	{
		if (min)
		{

		}
	}
}

void main()
{
	// Varriables
	queue q;
	int x;

	// Code
	queue_init(&q);
	printf("Enter value\n");
	scanf("%d", &x);
	while (x != -1)
	{
		enqueue(&q, x);
		printf("Enter value\n");
		scanf("%d", &x);
	}

	//queue_print(q);
	
	printf("%d\n", distanceBetweenElements(q, 1, 3)); // Ex1

	// Please stop so I can see what happend
	scanf ("%d");
}