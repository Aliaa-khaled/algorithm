#include <stdio.h>
#include "stack.h"

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
