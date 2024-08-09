
#include <stdio.h>
#include <stdlib.h>
#define max_size 100

typedef struct queue {
    int front, rear, size;
    int array[max_size];
} queue;


void initialize_queue(queue *qp);

int is_empty(queue *qp);
int is_full(queue *qp);

void enqueue(queue *qp, int item);
int dequeue(queue *qp);

int top_queue(queue *qp);
void destroy_queue(queue *qp);
void display_queue(queue *qp);
int size_queue(queue *qp);

int main() {
    queue q;
    initialize_queue(&q);

    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 0);
    enqueue(&q, 6);

    printf("queue contents: ");
    display_queue(&q);

    printf("queue size: %d\n", size_queue(&q));

    printf("the Top queue: %d\n", top_queue(&q));

    dequeue(&q);
    printf("the Top queue after pop the first element: %d\n", top_queue(&q));

    destroy_queue(&q);

}

void initialize_queue(queue *qp) {
    qp->front = 0;
    qp->rear = -1;
    qp->size = 0;
}

int is_empty(queue *qp) {
    return qp->rear == -1;
}

int is_full(queue *qp) {
    return qp->rear ==max_size-1 ;
}

void enqueue(queue *qp, int item) {
    if (!is_full(qp)) {
        qp->rear = (qp->rear + 1) % max_size;
        qp->array[qp->rear] = item;
        qp->size++;
    }
}

int dequeue(queue *qp)
 {
    if (!is_empty(qp))
    {
        int item = qp->array[qp->front];
        qp->front = (qp->front + 1) % max_size;
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
        return qp->array[qp->front];
    }
}

int size_queue(queue *qp) {

    return qp->size;
}


void display_queue(queue *qp) {
    int i = qp->front;
    for (int count = 0; count < qp->size; count++) {
        printf("%d ", qp->array[i]);
        i = (i + 1) % max_size;
    }
    printf("\n");
}


