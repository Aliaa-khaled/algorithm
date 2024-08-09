
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
    int entry;
    struct stack_node *next;
} stack_node;

typedef struct stack {
    stack_node *top;
} stack;

typedef struct queue {
    stack s1;
    stack s2;
} queue;

void initialize_stack(stack *sp);
int is_empty(stack *sp);
int is_full(stack *sp);
void push_stack(stack *sp, int item);
int pop_stack(stack *sp);
int top_stack(stack *sp);
void destroy_stack(stack *sp);
void display_stack(stack *sp);
int size_stack(stack *sp);

void initialize_queue(queue *qp);
int is_empty_queue(queue *qp);
void enqueue(queue *qp, int item);
int dequeue(queue *qp);
void destroy_queue(queue *qp);


int main() {
    queue q;
    initialize_queue(&q);

    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 0);
    enqueue(&q, 6);

    dequeue(&q);
    destroy_queue(&q);

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

void initialize_queue(queue *qp) {
    initialize_stack(&qp->s1);
    initialize_stack(&qp->s2);
}

int is_empty_queue(queue *qp) {
    return is_empty(&qp->s1) && is_empty(&qp->s2);
}

void enqueue(queue *qp, int item) {
    push_stack(&qp->s1, item);
}

int dequeue(queue *qp) {
    if (is_empty(&qp->s2)) {
        while (!is_empty(&qp->s1)) {
            push_stack(&qp->s2, pop_stack(&qp->s1));
        }
    }
    return pop_stack(&qp->s2);
}

void destroy_queue(queue *qp) {
    destroy_stack(&qp->s1);
    destroy_stack(&qp->s2);
}

