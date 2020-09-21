#include<stdio.h>

#define MAX_QUEUE 10

int inqueue(int element); //add element to the queue.
int dequeue() //remove the first element in the queue.

int front=0; //queue controler
int rear=0; //queue controler

int queue[MAX_QUEUE];

int main()
{


}

int inqueue(int element)
{
  if(front=(rear+1)%MAX_QUEUE)
  {
	  printf("Queue overflow\n");

	  return 0;
  }
  
   queue[(++rear)%MAX_QUEUE]=element;

   return 1
}

int dequeue()
{ 
	int store;

	if(front==rear)
	{
		printf("Queue underflow\n");
		return 0;
	}

	store=queue[front];
	front=(++front)%MAX_QUEUE;

	return store;
}
