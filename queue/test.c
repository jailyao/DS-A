#include <stdio.h>
#include "queue.h"

int main(void) {
    EleType E = 0;
    Queue Q = InitQueue(NULL);
    if (!Q) {
        printf("Initialize queue failed!\n");
        return -1;
    }
    printf("Initialize queue succeed!\n");

    for (int i = 0; !QueueFull(Q); i++) {
        if (!EnQueue(Q, i)) {
            printf("Queue insert %d failed!\n", i);
            return -1;
        }
        printf("Queue insert: %d\n", i);
    }
    printf("Queue is full!\n");

    if (!DeQueue(Q, &E)) {
        printf("Queue is empty!\n");
        return -1;
    }
    printf("Queue delete element: %d\n", E);

    if (!GetHead(Q, &E)) {
        printf("Queue is empty!\n");
        return -1;
    }
    printf("Queue head element: %d\n", E);

    printf("Queue length: %d\n", QueueLength(Q));

    ClearQueue(Q);

    if (!QueueEmpty(Q)) {
        printf("Queue clear failed!\n");
        return -1;
    }
    printf("Queue clear succeed!\n");

    DestroyQueue(Q);
    printf("Queue destroyed!\n");

    return 0;
}