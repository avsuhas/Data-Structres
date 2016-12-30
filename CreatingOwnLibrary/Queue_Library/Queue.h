/* Queue.h */

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SUCCESS 0
#define INVALID_QUEUE ((void *)0)
#define QUEUE_MEM_FAILURE ((void *)0)
#define QUEUE_FULL 1
#define QUEUE_EMPTY 2
 

typedef struct Queue * QUEUE;

QUEUE CreateNewQueue(int SizeOfData, int Capacity);
int Enqueue(QUEUE Q,void * data);
int Dequeue(QUEUE Q,void * data);
int DisposeQueue(QUEUE Q);
int IsQueueFull(QUEUE Q);
int IsQueueEmpty(QUEUE Q);

#endif
