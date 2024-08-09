
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
   printf("queue contents: ");
    display_queue(&q);

    destroy_queue(&q);

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

