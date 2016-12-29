#include<stdio.h>

#include<stdlib.h>


#define SIZE 5


int a[SIZE];

int count = 0;

int f = 0;

int r = -1;


void insert_data();

void delete_front();

void display();


int main()

{
	
	int choice;


	while(1)
	
	{

		
		printf("Enter Choice: 1:Enqueue, 2: Dequeue 3: Display, 4:exit\n");

		scanf("%d", &choice);

		
	
		switch(choice)
		
		{
			
			case 1: insert_data();
	
	           		            break;
			
			
		
			case 2: delete_front();

			break;

			
	
			case 3: display();

			break;



			case 4: exit(0);



			default: printf("Invalid input\n");

		}
	
	}

}




void insert_data( )

{
		
	
	if(count == SIZE)
	
	{
		
		printf("Queue is full\n");

	}
	
	else
	
	{
		
		count++;

		r = (r+1)%SIZE;
	

		printf("Enter data\n");

		scanf("%d", &a[r]);
	
	}

}



void delete_front( )

{

	
	if(count == 0)
	
	{
		
		printf("Queue is Empty\n");

	}
	
	else
	
	{
		
		count--;
		
		printf("The value been delete = %d\n", a[f]);

		
		f = (f+1)%SIZE;
	
	}


}



void display( )

{
	
	int i=f;
	
	int count1 = count;
	

	
	if(count == 0)
	
	{
		
		printf("Queue is empty\n");
	
	}
	
	else
	
	{
				

		while(count1 > 0)
		
		{
		
		
			printf("%d\n", a[i]);
			
			i = (i+1)%SIZE;
	
		
			count1 --;
		
		}
	
	}

}	
