#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include<ctype.h>
#define LENGTH 50

int main()
{
	char * Move;
	STACK S;
	char EnteredLine[LENGTH];
	int Number;
	
	if((S = CreateNewStack(sizeof(int),3)) == STACK_MEM_FAILURE)
	{
		fprintf(stderr,"Cannot create new stack due to memory issues\n");
		exit(1);
	}

	while(1)
	{
		if( IsStackEmpty (S))
		{
			printf("USAGE:<NUM> to PUSH, e or E to EXIT\n");
		}
		else if( IsStackFull(S))
		{
			 printf("USAGE:P or p to POP, e or E to EXIT\n");
		}
		else
		{
			 printf("USAGE:P or p to POP,<NUM> to PUSH, e or E to EXIT\n");
		}

		if(!fgets(EnteredLine,LENGTH,stdin))
			exit(2);
		
		for(Move = EnteredLine; *Move ==' '|| *Move=='\t';Move++)
			;
	
		if(isdigit(*Move))
		{
			Number = atoi(Move);
			if(Push( &Number,S) ==STACK_SUCCESS)
				printf("PUSHING is SUCCESS\n");
			else
				printf("CANNOT PUSH: STACK FULL\n");
		}
		else if(*Move =='p' || *Move=='P')
		{
			if(Pop(S,&Number) == STACK_SUCCESS)
			printf("POPPED NUMBER = %d\n",Number);
			else
			printf("CANNOT POP: STACK EMPTY\n");
		}
		
		else if(*Move =='e' || *Move == 'E')
		{
			while(Pop(S,&Number) == STACK_SUCCESS)
			{
				printf("POPPED NUMBER WHILE EXITING = %d\n",Number);
			}
			break;
		}
	}
	DisposeStack(S);
	printf("Good Bye\n");
	return 0;
}
