#ifndef STACK_H
#define STACK_H


typedef struct stack_node {
    int entry;
    struct stack_node *next;
} stack_node;

typedef struct stack {
    stack_node *top;
} stack;

void initialize_stack(stack *sp);
int is_empty(stack *sp);
int is_full(stack *sp);
void push_stack(stack *sp, int item);
int pop_stack(stack *sp);
int top_stack(stack *sp);
void destroy_stack(stack *sp);
void display_stack(stack *sp);
int size_stack(stack *sp);

#endif
