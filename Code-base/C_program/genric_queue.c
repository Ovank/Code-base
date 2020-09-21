#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

typedef struct queue
{
	int size;
	int dsize;
	int front;
	int rear;
	void *data;
}queue;

typedef  queue* gqueue;


    gqueue createGQueue(int queueSize, int dsize);
    int enGQueue(gqueue q, void *dp);
    int deGQueue(gqueue q, void *dp);
    int freeGQueue(gqueue q);
    int isGQueueFull(gqueue q);
    int isGQueueEmpty(gqueue q);
    void print_menu();
    void MemCpy(void *dest,void *src,int size);

void main()
{
   int size,dsize,element,number,number2,choice,status;

   void *pass,*pass2;


   gqueue s1;

   system("clear");

   print_menu();  //print user menu.

   printf("Enter your choice\n");

   scanf("%d",&choice);

   while(choice !=6)
{
   switch(choice)
 	{
		case 0:
		        printf("Enter the size of Queue\n");

                         scanf("%d",&size);

                        printf("Enter the size of data type\n");

                        scanf("%d",&dsize);

                          if((s1=createGQueue(size,dsize))==0)   //creating the Queue with given size.
                          {
                             printf("Error in creating an Queue\n");
                          }

                          break;

		case 1:
 			printf("Enter the element for inserting\n");
                        scanf("%d",&element);

                        pass= &element;
                        if(( status=enGQueue(s1,pass))==0)
				{
					printf("Error !");
				}
			break;

                case 2:
                         pass=&number2;
                        if((element=deGQueue(s1,pass)))
			{

 		         	printf("The front element in Queue is %d.\n",number2);
			}
			else
  			{
				printf("Error !\n");
			}

			break;

                case 3:

                         element=freeGQueue(s1);
		        	break;

		case 4:
           		if((element=isGQueueFull(s1)))
			{
			  printf("Queue is full\n");
                        }
                        else
                        {
                            printf("Queue is not full\n");
			}
    			break;
		case 5:
			 if((element=isGQueueEmpty(s1)))
 				{
					printf("Queue is empty\n");
				}
			else
				{
					printf("Queue is not empty\n");
				}
			break;
               default :
                         printf("Invalid choice\n");
			break;
	}
         getchar();
         printf("Press any key to continue\n");
         getchar();

        system("clear");
        print_menu();
        printf("Enter your choice\n");
        scanf("%d",&choice);
}


}



gqueue createGQueue(int queueSize, int dsize)
{
      gqueue q1 = (gqueue)malloc(sizeof(struct queue)); //declearing a queue datatype.
	void *memory;

	memory=malloc(queueSize*dsize); //assign memory for storing the element in queue.

        q1->front=0;  //initilise the front of queue
	q1->rear=0;
	q1->data=memory;

	return q1;
}

int enGQueue(gqueue q, void *dp)
{
	int check;

         printf("Check !\n");

	if((check=isGQueueFull(q)))
	{
	  printf("The queue is full\n");

	  return 0; //fail.
	}

	printf("Check 2\n");

        q->rear=(q->rear+1)%(q->size); //to adjust the position of rear in circular queue.

        printf("%d\n",q->rear);

        MemCpy((q->data+(q->rear)*(q->dsize)),dp,q->dsize) ;//copy the information from source to destination bitwise.

        return 1; //success
}


int deGQueue(gqueue q,void *dp)
{

    int check;

    if(check=isGQueueEmpty(q))
    {
      return 0;  //fail.
    }

    MemCpy(dp,q->data+q->front*q->dsize,q->dsize);//get the stored value and copy tothe location pointed by dp.
    q->front=(q->front+1)%q->size; //adjust the front of queue.

    return 1;  //success.

}

int isGQueueFull(gqueue q)
{
    int rear=((q->rear+1)%(q->size));

    printf("%d",rear);

    if( rear == q->front )
      {
         return 1;
      }

     return 0;
}

int isGQueueEmpty(gqueue q)
{
    if((q->rear) == q->front )
      {
         return 1;
      }

     return 0;
}

void print_menu()  //function print user menu.
{
   printf("0.Create a Queue\n");
   printf("1.Enqueue a element in Queue\n");
   printf("2.dequeu element from Queue.\n");
   printf("3.free the space of Queue\n");
   printf("4.Check wether Queue is full\n");
   printf("5.check wether Queue is empty\n");
   printf("6.Exit\n");
}

int freeGQueue(gqueue q)
{
	if(q== NULL)
	{
	  return 0;
	}

     free(q->data);
     free(q);

     return 1;
}

void MemCpy(void *dest, void *src,int n)  //function copy contents from one source to another destination.
{
   // Typecast src and dest addresses to (char *)
   char *csrc = (char *)src;
   char *cdest = (char *)dest;

   // Copy contents of src[] to dest[]
   for (int i=0; i<n; i++)
       cdest[i] = csrc[i];
}
