#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#include<ctype.h>

#define LENGTH 50
 
int main()
{
	char * Move;
	QUEUE Q;
	char EnteredLine[LENGTH];
	int Number;
	
	if((Q = CreateNewQueue(sizeof(int),3))== QUEUE_MEM_FAILURE)
	{
		fprintf(stderr,"Cannot create new queue due to memory issue\n");
		exit(0);
	}

	while(1)
	{
		if(IsQueueEmpty(Q))
		{
			printf("USAGE:<NUM> to ENQUEQE, e or E to EXIT\n");
		}
		else if(IsQueueFull(Q))
		{
			printf("USAGE: d or D to DEQUEUE, e or E to EXIT\n");
		}
		else
		{
		 	printf("USAGE: d or D to DEQUEUE,<NUM> to ENQUEQE, e or E to EXIT\n");
		}

		if(!fgets(EnteredLine,LENGTH,stdin))
			exit(2);
		
		for(Move = EnteredLine; *Move == ' ' || *Move == '\t'; Move++)
			;

		if(isdigit(*Move))
		{
			Number = atoi(Move);
			if(Enqueue(Q,&Number) == QUEUE_SUCCESS)
				printf("ENQUEUE is SUCCESS\n");
			else
				printf("CANNOT ENQUEUE: QUEUE IS FULL\n");
		}

		else if(*Move =='d' || *Move =='D')
		{
			if(Dequeue(Q, &Number)== QUEUE_SUCCESS)
				printf("RETRIEVED NUMBER = %d\n",Number);
			else
				printf("CANNOT DENQUEUE: QUEUE IS EMPTY\n");
		}
		else if(*Move =='e' || *Move == 'E')
		{
			while(Dequeue(Q, &Number)==QUEUE_SUCCESS)
			{
				printf("RETRIEVED NUMBER WHILE EXITING = %d\n",Number);
			}
			break;
		}
	}
	DisposeQueue(Q);
	printf("GoodBye\n");
	return 0;
}
		








 
