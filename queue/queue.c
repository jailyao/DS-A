#include <stdlib.h>
#include "queue.h"

#define MAX_QUEUE_SIZE  100

enum {
    INSERT,
    DELETE,
};

struct _Queue
{
    EleType data[MAX_QUEUE_SIZE];
    QuePtr head;
    QuePtr tail;
    int flag;
};

Queue InitQueue(Queue Q) {
    Queue q = (Queue)malloc(sizeof(struct _Queue));
    q->head = q->tail = 0;
    q->flag = DELETE;
    return q;
}

void DestroyQueue(Queue Q) {
    free(Q);
}

void ClearQueue(Queue Q) {
    Q->head = Q->tail;
    Q->flag = DELETE;
}

int QueueEmpty(Queue Q) {
    if ((((Q->tail - Q->head + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE) == 0) && (Q->flag == DELETE))
        return 1;
    return 0;
}

int QueueFull(Queue Q) {
    if ((((Q->tail - Q->head + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE) == 0) && (Q->flag == INSERT))
        return 1;
    return 0;
}

int GetHead(Queue Q, EleType *E) {
    if (QueueEmpty(Q))
        return 0;
    *E = Q->data[Q->head];
    return 1;
}

int EnQueue(Queue Q, EleType E) {
    if (QueueFull(Q))
        return 0;
    Q->data[Q->tail] = E;
    Q->tail = (Q->tail + 1) % MAX_QUEUE_SIZE;
    Q->flag = INSERT;
    return 1;
}

int DeQueue(Queue Q, EleType *E) {
    if (QueueEmpty(Q))
        return 0;
    *E = Q->data[Q->head];
    Q->head = (Q->head + 1) % MAX_QUEUE_SIZE;
    Q->flag = DELETE;
    return 1;
}

int QueueLength(Queue Q) {
    return ((Q->tail - Q->head + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE);
}