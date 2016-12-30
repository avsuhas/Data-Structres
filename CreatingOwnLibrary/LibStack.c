#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
	int Capacity;
	char *StackPointer;
	int TopOfStack;
	int SizeOfData;
};
	
STACK CreateNewStack(int SizeOfData, int MaxElementsToStore)
{
	STACK S;
	if( (S = (STACK)malloc (sizeof(struct Stack))) == NULL)
	{
		return STACK_MEM_FAILURE;
	}
	if((S->StackPointer =(char *)malloc(MaxElementsToStore * SizeOfData)) == NULL)
	{
		return STACK_MEM_FAILURE;
	}
	S->Capacity = MaxElementsToStore;
	S->SizeOfData = SizeOfData;
	InitTopOfStack(S);
	return S;
}

void InitTopOfStack(STACK S)
{
	S->TopOfStack = INIT_TOP_OF_STACK;
}

void DisposeStack(STACK S)
{
	if(S!=  NULL)
	{
		if(S->StackPointer != NULL)
		{
			free(S->StackPointer);
		}
		free(S);
	}
}

int Push(void * Element,STACK S)
{
	if(IsStackFull(S))
		return STACK_FULL;
	
	memcpy (S->StackPointer, Element, S->SizeOfData);
	S->StackPointer = S->StackPointer + S->SizeOfData;
	++S->TopOfStack;

	return STACK_SUCCESS;
}

int Pop(STACK S,void * Elements) 
{
	 if(IsStackEmpty(S))
                return STACK_EMPTY;
	S->StackPointer = S->StackPointer- S->SizeOfData;
	--S->TopOfStack;
	memcpy(Elements,S->StackPointer,S->SizeOfData);

	return STACK_SUCCESS;
}

int IsStackFull(STACK S)
{
	return S->TopOfStack == (S->Capacity-1);
}

int IsStackEmpty(STACK S)
{
	return S->TopOfStack == INIT_TOP_OF_STACK;
}

 
