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
	nodePtr temp = (node*)malloc(sizeof(node));
	temp->info = x;
	temp->next = p->next;
	temp->prev = p;
	p->next = temp;
}

void deleteNode(nodePtr *p)
{
	if ((*p)->prev == NULL)
		*p = (*p)->next;
	(*p)->prev->next = (*p)->next;
	(*p)->next->prev = (*p)->prev;
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
		printf("Close to the start. distance is: %d\n", j);
	}
	else
	{
		printf("Close to the end. distance is: %d\n", i);
	}
	
}

void createListNode(nodePtr *rear, nodePtr *front)
// Create new list, returns pointers to the first and last
{
	int x;
	nodePtr temp, newTemp;

	// First
	printf("Enter value\n");
	scanf_s("%d", &x);
	temp = (node*)malloc(sizeof(node));
	temp->info = x;
	temp->prev = NULL;
	*front = temp;

	// The rest
	printf("Enter value\n");
	scanf_s("%d", &x);
	while (x!=-1)
	{
		newTemp = (node*)malloc(sizeof(node));
		newTemp->info= x;
		newTemp->prev = temp;
		temp->next = newTemp;
		temp = newTemp;
		printf("Enter value\n");
		scanf_s("%d", &x);
	}
	temp->next = NULL;
	*rear = temp;
}

void main()
{
	nodePtr first, last, ptr;
	first = (node*)malloc(sizeof(node));
	last = (node*)malloc(sizeof(node));

	createListNode(&last, &first);

	

	nodePtr p = first->next->next;
	closer(p);
	addNext(p, p->info);

	ptr = first;
	while (ptr->next!=NULL)
	{
		printf("%d, ", ptr->info);
		ptr = ptr->next;
	}

	scanf_s("%d");
}