#include<stdio.h>
#include<stdlib.h>

#define MAX_SHARE 1000


typedef struct element
{
   int size;
   int count;
   int store[MAX_SHARE];
}element;

typedef element* stack_share;

//protoype of function.

int push(stack_share A,int i);
int pop(stack_share A,int *j);
int is_stack_empty(stack_share A);
int is_stack_full(stack_share A);
int* find_span(int A[],int size);

int main()
{       
	int share_status[MAX_SHARE],*span,size;
        
        
	printf("Enter the size of data\n");

	scanf("%d",&size);
         
        
	printf("Enter the data of share:\n");

	for(int u=0;u<size;u++)
	{       
	        
		scanf("%d",&share_status[u]);
	}

	span=find_span(share_status,size);
        
       
        printf("The span of given data is as follows:\n");

	for(int y=0;y<size;y++)
	{
		printf("%d ",span[y]);
	}

}

int push(stack_share A,int i)
{
	int check;

	if((check=is_stack_full(A)))
	{
		 return 0;
	}
         
	 ++(A->count);
	 A->store[A->count]=i;

	 return 1;
}

int pop(stack_share A,int *j)
{
	int check;

	if((check=is_stack_empty(A)))
	{
		return 0;
	}

	*j=A->store[A->count];
	(A->count)--;
	
	return 1;	
}

int is_stack_empty(stack_share A)
{ 
	if(A->count==-1)
	{
		return 1;
	}

	return 0;
}

int is_stack_full(stack_share A)
{
	if(A->count==A->size)
	{
		return 1;
	}

	return 0;
}

int* find_span(int share_status[],int size)
{        
		
	int h_i,check,flag;
	
	int *span;
	
	span=(int *)malloc(size*sizeof(int));

 	stack_share hold;  //store the temproray share for comparision.
 	
 	hold=malloc(sizeof(stack_share));
	hold->count=-1;
	hold->size=MAX_SHARE;
	
	for(int y=0;y<size;y++)
        {  
            flag=1;
           
           while((check=pop(hold,&h_i)))
           {   
                
             	 if(share_status[h_i]> share_status[y])
             		 {   
              
                 		check=push(hold,h_i);
                 		check=push(hold,y);
                  
                 		 span[y]=y-h_i;                
                 		flag=0;
                 
                 		break;
            		}
          }
        
            if(flag==1)
       		 {
        	  check=push(hold,y);
        	  span[y]=y+1;
        	}  
      } 	 
       
	return span;	
}	


