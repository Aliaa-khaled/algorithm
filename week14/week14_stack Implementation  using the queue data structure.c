
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node {
    int entry;
    struct queue_node *next;
} queue_node;

typedef struct queue {
    queue_node *front;
    queue_node *rear;
    int size;
} queue;

typedef struct stack {
    queue q;
} stack;


void initialize_queue(queue *qp);
int is_empty(queue *qp);
int is_full(queue *qp);
void enqueue(queue *qp, int item);
int dequeue(queue *qp);
int top_queue(queue *qp);
void destroy_queue(queue *qp);
void display_queue(queue *qp);
int size_queue(queue *qp);


void initialize_stack(stack *sp);
void push_stack(stack *sp, int item);
int pop_stack(stack *sp);
int top_stack(stack *sp);
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

    printf("Top element: %d\n", top_stack(&s));

    pop_stack(&s);
    printf("Stack contents after pop: ");
    display_stack(&s);

    printf("Top element after pop: %d\n", top_stack(&s));
}

void initialize_queue(queue *qp) {
    qp->front = NULL;
    qp->rear = NULL;
    qp->size = 0;
}

int is_empty(queue *qp) {
    return qp->front == NULL;
}

int is_full(queue *qp) {
    return 0;
}

void enqueue(queue *qp, int item) {
    if (!is_full(qp)) {
        queue_node *TempNode = NULL;
        TempNode = (queue_node *)malloc(sizeof(queue_node));
        TempNode->entry = item;
        TempNode->next = NULL;
        if (is_empty(qp))
        {
            qp->front = TempNode;
        }
        else
        {
            qp->rear->next = TempNode;
        }
        qp->rear=TempNode;
        qp->size++;
    }
}

int dequeue(queue *qp)
 {
    if (!is_empty(qp))
    {
        queue_node *TempNode = NULL;
        TempNode=qp->front;
        int item =TempNode->entry;
        qp->front=TempNode->next;
        free(TempNode);
        if (qp->front == NULL)
        {
            qp->rear = NULL;
        }
        qp->size--;
        return item;
    }
}

void destroy_queue(queue *qp)
{
    while (!is_empty(qp))
    {
        dequeue(qp);
    }
}

int top_queue(queue *qp) {
    if (!is_empty(qp)) {
        return qp->front->entry;
    }
}

int size_queue(queue *qp) {

    return qp->size;
}


void display_queue(queue *qp) {
    queue_node *TempNode = qp->front;
    while (TempNode != NULL) {
        printf("%d ", TempNode->entry);
        TempNode = TempNode->next;
    }
    printf("\n");
}

void initialize_stack(stack *sp) {
    initialize_queue(&(sp->q));
}

void push_stack(stack *sp, int item) {
    enqueue(&(sp->q), item);
    for (int i = 0; i < sp->q.size - 1; i++) {
        enqueue(&(sp->q), dequeue(&(sp->q)));
    }
}

int pop_stack(stack *sp) {
    return dequeue(&(sp->q));
}

int top_stack(stack *sp) {
    return sp->q.front->entry;
}

void display_stack(stack *sp) {
    display_queue(&(sp->q));
}

int size_stack(stack *sp) {
    return sp->q.size;
}
