typedef int stack_item;

struct node_type
{
	stack_item info;
	struct node_type *next;
};

typedef struct
{
	struct node_type *top;
} stack;

void  stack_init(stack *s);

int stack_empty(stack s);

int stack_full(stack s);

void  stack_push(stack *s, stack_item x);

stack_item stack_pop(stack *s);

stack_item stack_top(stack s);

void stack_print(stack *s);