
#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#include<string.h>

struct Queue
{
	int Capacity;
	int SizeOfData;
	int CountOfElements;
	char *Last;
	char *Head;
	char *Tail;
	char *QPointer;
};

QUEUE CreateNewQueue(int SizeOfData,int Capacity)
{
	QUEUE Q;
	if(Capacity<1 || SizeOfData <1)
	{
		return INVALID_QUEUE;
	}
	if((Q=(QUEUE)malloc(sizeof(struct Queue))) == NULL)
	{
		return QUEUE_MEM_FAILURE;
	}
	if((Q->QPointer = (char *)malloc(Capacity *SizeOfData)) == NULL)
	{
		return QUEUE_MEM_FAILURE;
	}
	Q->Head = Q->Tail = Q->QPointer;
	Q->Last = Q->QPointer + Capacity *SizeOfData;
	Q->Capacity =Capacity;
	Q->SizeOfData=SizeOfData;
	Q->CountOfElements= 0;
	return Q;
}

int Enqueue(QUEUE Q,void *item)
{
	if(IsQueueFull(Q))
	 return QUEUE_FULL;
	
	memcpy(Q->Head,item,Q->SizeOfData);
	if((Q->Head+=Q->SizeOfData)== Q->Last)
		Q->Head=Q->QPointer;
	Q->CountOfElements++;
		return QUEUE_SUCCESS;
}

int Dequeue(QUEUE Q,void *item)
{
	 if(IsQueueFull(Q))
          return QUEUE_FULL;
	memcpy(item,Q->Tail,Q->SizeOfData);
	 if((Q->Tail+=Q->SizeOfData)== Q->Last)
                Q->Tail=Q->QPointer;
        Q->CountOfElements--;
                return QUEUE_SUCCESS;
}

int DisposeQueue(QUEUE Q)
{
	if(Q!=NULL)
	{
		if(Q->QPointer != NULL)
		{
			free(Q->QPointer);
		}
		free(Q);
	}
	return QUEUE_SUCCESS;
}


int IsQueueFull(QUEUE Q)
{
	return Q->CountOfElements == Q->Capacity;
}

int IsQueueEmpty(QUEUE Q)
{
	  return Q->CountOfElements == 0;
}










