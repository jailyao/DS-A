#ifndef __QUEUE_H__
#define __QUEUE_H__


typedef int EleType;
typedef int QuePtr;
typedef struct _Queue *Queue;

Queue InitQueue(Queue Q);
void DestroyQueue(Queue Q);
void ClearQueue(Queue Q);
/** if empty, return 1, else return 0 */
int QueueEmpty(Queue Q);
int QueueFull(Queue Q);
int GetHead(Queue Q, EleType *E);
int EnQueue(Queue Q, EleType E);
int DeQueue(Queue Q, EleType *E);
int QueueLength(Queue Q);



#endif