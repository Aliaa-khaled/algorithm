
#include <stdio.h>
#include <stdlib.h>

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

int main() {
    stack s;
    initialize_stack(&s);

    push_stack(&s, 4);
    push_stack(&s, 5);
    push_stack(&s, 0);
    push_stack(&s, 6);

    printf("Stack contents: ");
    display_stack(&s);

    printf("Stack size: %d\n", size_stack(&s));

    printf("the Top stack: %d\n", top_stack(&s));

    pop_stack(&s);
    printf("the Top stack after pop the first element: %d\n", top_stack(&s));

    destroy_stack(&s);

}

void initialize_stack(stack *sp) {
    sp->top = NULL;
}

int is_empty(stack *sp) {
    return sp->top == NULL;
}

int is_full(stack *sp) {
    return 0;
}

void push_stack(stack *sp, int item) {
    if (!is_full(sp)) {
        stack_node *TempNode = NULL;
        TempNode = (stack_node *)malloc(sizeof(stack_node));
        TempNode->entry = item;
        TempNode->next = sp->top;
        sp->top = TempNode;

    }
}

int pop_stack(stack *sp)
 {
    if (!is_empty(sp))
    {
        stack_node *TempNode = NULL;
        TempNode=sp->top;
        int item =TempNode->entry;
        sp->top=TempNode->next;
        free(TempNode);
        return item;
    }
}

void destroy_stack(stack *sp)
{
    while (!is_empty(sp))
    {
        pop_stack(sp);
    }
}

int top_stack(stack *sp) {
    if (!is_empty(sp)) {
        return sp->top->entry;
    }
}

int size_stack(stack *sp) {
    int size = 0;
    stack_node *TempNode = sp->top;
    while (TempNode != NULL) {
        size++;
        TempNode = TempNode->next;
    }
    return size;
}


void display_stack(stack *sp) {
    stack_node *TempNode = sp->top;
    while (TempNode != NULL) {
        printf("%d ", TempNode->entry);
        TempNode = TempNode->next;
    }
    printf("\n");
}
