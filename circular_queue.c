

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct queue
{
	int a[SIZE];
	int f;
	int r;
};

void insert_rear(struct queue *obj, int data);
void delete_front(struct queue *obj);
void display(struct queue *obj);

int count = 0;

int main()
{
	struct queue obj;
	obj.f = 0; //delete
	obj.r = -1; //insert
	int data;

	int choice;

	while(1)
	{
		printf("Enter choice: 1:Enque , 2:Dequeue, 3:display, 4:exit\n");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1:	printf("Inseret data\n");
				scanf("%d", &data);
				insert_rear(&obj, data);
				break;

			case 2: delete_front(&obj);
				break;

			case 3: display(&obj);
				break;

			case 4:exit(0);

			default: printf("Invalid input\n");
		}
	}
}

void insert_rear(struct queue *obj, int data)
{
	if(count == SIZE)
	{
		printf("Queue is full\n");
	}
	else
	{
		count++;
		
		obj->r = ( (obj->r)+1) % SIZE;

		printf("enter a data\n");
		obj->a[obj->r] = data;
	}
}

void delete_front(struct queue *obj)
{
	if(count == 0)
	{
		printf("Queue is empty\n");
	}
	else
	{
		count--;
		printf("Deleted element is %d\n", obj->a[obj->f]);
		
		(obj->f)= ((obj->f) + 1) % SIZE;
	}
 
			
}

void display(struct queue *obj)
{

	int i=obj->f;
	int count1= count;
	if(count == 0)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		while(count1>0)
		{
			printf("%d\n", obj->a[i]);
			i= (i+1)%SIZE;
			count1--;
		}
	}
}
