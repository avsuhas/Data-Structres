/* Stack header */



#ifndef STACK_H
#define STACK_H

#define STACK_SUCCESS	  0
#define STACK_FULL	  1
#define STACK_EMPTY	  2
#define STACK_MEM_FAILURE ((void *)0)

#define INIT_TOP_OF_STACK	-1

typedef struct Stack * STACK;

STACK CreateNewStack(int SizeOfData, int MaxElementsToStore);
void DisposeStack( STACK S );
int Push (void *Element,STACK S);
int Pop(STACK S,void *Element );
int IsStackFull(STACK S);
int IsStackEmpty(STACK S);
void InitTopOfStack(STACK S);

#endif
