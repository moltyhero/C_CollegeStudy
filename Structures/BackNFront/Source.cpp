#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h> 

typedef struct node
{
	int info;
	struct node* next;
	struct node* prev;
} nodeType, *nodePtr;

void addNext(nodePtr p, int x) // add after p
{
	node temp;
	temp.info = x;
	temp.next = p->next;
	temp.prev = p;
	p->next = &temp;
}

void deleteNode(nodePtr p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
}

void closer(nodePtr p) // Find which edge p is closer to and print the distance
{
	nodePtr temp = p;
	int j;
	int i = j = 0;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		i++;
	}
	temp = p;
	while (temp->prev!=NULL)
	{
		temp = temp->prev;
		j++;
	}
	if (i>j)
	{
		printf("Close to the start. distance is: %d", j);
	}
	else
	{
		printf("Close to the end. distance is: %d", i);
	}
	
}

void createListNode(nodePtr *rear, nodePtr *front)
// Create new list, returns pointers to the first and last
{
	int x;
	nodePtr temp, newTemp;

	// First
	printf("Enter value");
	scanf("%d", &x);
	temp = (node*)malloc(sizeof(node));
	temp->info = x;
	temp->prev = NULL;
	*front = temp;

	// The rest
	printf("Enter value");
	scanf("%d", &x);
	while (x!=-1)
	{
		newTemp = (node*)malloc(sizeof(node));
		newTemp->info= x;
		newTemp->prev = temp;
		temp->next = newTemp;
		temp = newTemp;
	}
	*rear = temp;
}

void main()
{
	nodePtr first, last;
	first = (node*)malloc(sizeof(node));
	last = (node*)malloc(sizeof(node));

	createListNode(&first, &last);
}