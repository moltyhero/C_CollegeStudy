#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef int itemType;

typedef struct node 
{
	int info;
	struct node* left;
	struct node* right;
}tree_node, *tree_Ptr;

void tree_init(tree_Ptr T, int x)
{

	T->left = NULL;
	T->right = NULL;
	T->info = x;
}

void setLeft(tree_Ptr T, int x)
{
	tree_Ptr temp = (tree_Ptr)malloc(sizeof(tree_node));
	temp->left = NULL;
	temp->right = NULL;
	temp->info = x;
	T->left = temp;
}

void setRight(tree_Ptr T, int x)
{
	tree_Ptr temp = (tree_Ptr)malloc(sizeof(tree_node));
	temp->left = NULL;
	temp->right = NULL;
	temp->info = x;
	T->right = temp;
}

void byLevel(tree_Ptr p, int x)
{
	if (x == 0)
		printf("%d\n", p->info);
	else
	{
		byLevel(p->left, x - 1);
		byLevel(p->right, x - 1);
	}
}

void preScan(tree_Ptr p)
{
	if (p == NULL)
		return;
	printf("%d\n", p->info);
	preScan(p->left);
	preScan(p->right);
}

void postOrder(tree_Ptr p)
{
	if (p == NULL)
		return;
	postOrder(p->left);
	postOrder(p->right);
	printf("%d\n", p->info);
}

void inScan(tree_Ptr p)
{
	if (p == NULL)
		return;
	inScan(p->left);
	printf("%d\n", p->info);
	inScan(p->right);
}

int isLeaf(tree_Ptr p)
{
	return (p->left == NULL && p->right == NULL);
}

int max(int x, int y)
{
	if (x >= y)
		return x;
	return y;
}

int height(tree_Ptr T)
{
	if (T == NULL)return -1;
	else return max(height(T->left), height(T->right)) + 1;
}

void insertTree(tree_Ptr *t, int key)
{
	tree_Ptr p, q;
	if (*t == NULL)
	{
		p = (tree_Ptr)malloc(sizeof(tree_node));
		p->info = key;
		p->left = NULL;
		p->right = NULL;
		*t = p;
	}
	else {
		p = *t;
		q = (tree_Ptr)malloc(sizeof(tree_node));
		while (p != NULL && p->info != key) { q = p; p = (key < p->info) ? p->left : p->right; }
		if (p == NULL)
		{
			p = (tree_Ptr)malloc(sizeof(tree_node));
			p->info = key;
			p->left = NULL;
			p->right = NULL;
			if (q->info > key)
				q->left = p;
			else
				q->right = p;
		}
	}
}

// Build a binary search tree with random keys
tree_Ptr buildTree()
{
	srand(time(NULL));
	int randomNum = rand() % 100 + 1;
	tree_Ptr t = NULL;
	int n, i, key;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		key = rand() % 100;
		insertTree(&t, key);
	}
	return t;
}

tree_Ptr find(tree_Ptr t, int x)
{
	if (t == NULL)
		return 0;
	else if (t->info == x)
		return t;
	else if (x < t->info)
		find(t->left, x);
	else find(t->right, x);
}

tree_Ptr findParent(tree_Ptr t, int x)
{

	if ((t->left == NULL && t->right == NULL) || t == NULL)
		return 0;
	else if (t->left->info == x || t->right->info == x)
		return t;
	else if (x < t->info)
		findParent(t->left, x);
	else findParent(t->right, x);
}

void printTree(tree_Ptr t, int h)
{
	int i;
	if (t!=NULL)
	{
		printTree(t->left, h + 1);
		for (i = 0; i < h; i++)
		{
			printf("      ");
		}
		printf("%d\n", t->info);
		printTree(t->right, h + 1);
	}
}


void remove(tree_Ptr t, int v)
{
	tree_Ptr temp = find(t, v);
	if (temp != NULL)
	{
		if (isLeaf(temp)) // Is a leaf, free him
		{
			free(temp);
		}
		else if (temp->left == NULL || temp->right == NULL) // Has one child, let his parent have his child
		{
			t = findParent(t, v);
			if (temp->left != NULL) // Has a child in the left
			{
				if (t->left == temp) // Switch the left child with the child's left child
				{
					t->left = temp->left;
				}
				else
				{
					t->right = t->left; // Switch the right child with the child's left child
				}
			}
			else // Has a child in the right
			{
				if (t->left == temp) // Switch the left child with the child's right child
				{
					t->left = temp->right;
				}
				else
				{
					t->right = t->right; // Switch the right child with the child's right child
				}
			}
		}
		else // Has 2 childs
		{

		}

	}
}

int main()
{
	tree_Ptr T;
	T = (tree_Ptr)malloc(sizeof(tree_node));
	tree_init(T, 5);
	setLeft(T, 3);
	setRight(T, 2);
	setLeft(T->left, 1);
	byLevel(T, 1);
	while (1);

	return 1;
}