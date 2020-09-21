#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct element
{
   int size;
   int count;
   int* data;
}queue;



int inqueue_p(queue* q1,int val);
int dequeue_p(queue* q1,int *val);
queue* create_q(int n);
int isEmpty(queue* q1);
int isFull(queue* q1); 
void swap(int *a,int *b);
void printMenu();
int generate();
void tossR(queue *q);

int main()
{    
     srand(time(NULL));
    int size,check;
    char a='y';
   
    printf("Emter the size of queue\n");
    
    scanf("%d",&size);
  
    queue* q1=create_q(size);

    printMenu();
   
    scanf("%d",&size);

    while(size !=5 )
      {
        
        switch(size)
          {
            case 1:   
 		      while(a=='y')
 		    {
 		        tossR(q1);
 		        //getchar();
 		        printf("Do you want to continue(y/n)\n");
 		        getchar();
 		        scanf("%c",&a);     
 		    }
 		    
                    break;
             case 2:
                        if(check=isEmpty(q1))
			{
			  printf("The queue is empty\n");
			}
			else
			{
 			  printf("Queue is not empty\n");
			}
			break;
	   case 3:
                        if(check=isFull(q1))
                        {
                          printf("The queue is Full\n");
                        }
                        else
                        {          
                          printf("Queue is not Full\n");
                        }
 			break;
           case 4:
                      
                     printf("The priority queue is\n");
                         
                         for(int i=1;i<q1->count;i++)
			  {
				printf("%d ",*(q1->data + i));
                          }
                       printf("\n");
                        break;
  	  default :
			printf("Invalid choice\n");
                        break;
         }     
               getchar();
               system("clear");
               getchar();
               printMenu();
                 
               scanf("%d",&size);
      }
				   
}

queue* create_q(int n)
{
  queue* q1;

  q1=(queue *)malloc(sizeof(queue));
  
  q1->size=n;
  q1->count=0;
   
  q1->data=(int *)malloc(sizeof(int)*(n+1));
 
  return q1;
}

int inqueue_p(queue* q1,int val)
{ 
   if(q1->count<=q1->size)
  {
    
    (q1->count)++;
    
    *(q1->data+q1->count)=val;
    
   
    int count1; 
    count1=q1->count;
     
     while(*(q1->data+count1/2) < *(q1->data+count1) && count1/2 > 0)
      {  
        swap(q1->data+(count1)/2,q1->data+count1);
        count1/=2;
      }
    return 1;
   }
   
  return 0;       
} 

int dequeue_p(queue* q1,int* val)
{
    if(q1->count == 0)
     {
        return 0;
     }
     else
     {  
        int ra=1;
        *val=*(q1->data+ra);
        
        *(q1->data+ra)=0;
        swap( q1->data+q1->count,q1->data+1);
        
        q1->count--;
        while(*(q1->data+ ra) < ( *(q1->data+2*ra) || *(q1->data+2*ra+1)) && 2*ra <= q1->size)
           { 
               if(*(q1->data+2*ra) < *(q1->data+2*ra+1))
		{
  			swap(q1->data+2*ra+1,q1->data +ra);
                        ra=2*ra+1;
		}
		else
		{
		   swap(q1->data+2*ra,q1->data+ra);
		   ra=2*ra;
 	        }
	   }
       return 1;		
      }
   return 0;
}

int isEmpty(queue* q1)
{
    if(q1->count == 0)
     {
        return 1;
     }
    else
     {
        return 0;
     }
}

int isFull(queue* q1)
{
    if(q1->count == q1->size)
      {
         return 1;
      }
  
    return 0;
} 

void swap(int *a,int *b)
{
     int temp;
     
     temp=*a;
     *a=*b;
     *b=temp;
}

void printMenu()
{
     printf("Select one of the operation\n\n");
     printf("1.Enter coinn-toss result\n");
     printf("2.Check the queue is empty\n");
     printf("3.Check the queue is full\n");
 
     printf("\nEnter your choice\n");
}
int generate()
{
   return rand();
   
}   

void tossR (queue* q1)
{
       int size,status,num;
        int toss=(generate())%2;
        
           if(toss == 1)
                      {   
                          num=generate()%50;   
                           
                          if((status = inqueue_p(q1,num)))
				{
				   printf("The toss result is \"Head\"\n The enter element is %d \n",num);
				   
                                }
                          else
                            {
                                printf("Queue is full\n");
                            }
		      }
		      else
			{      
			      size=-1;
                              if(status = dequeue_p(q1,&size))
                                {
                                       printf("The toss result is \" Tail\"\n The element  with highest priority is %d\n",size);
                                         
				   
                                }
                               else
                                 {
                                       printf("Queue is empty\n");
                                 }
                       }  
}
