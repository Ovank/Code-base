#include<stdio.h>
#include<stdlib.h>

typedef struct element  //stack data type
{
  int size;   //stores the number of element in stack.
  int dsize;  //store the size of each element in stack.
  int count;  //hold the current number of elements in stack.
  void *data; //pointer to the memory for storage of stack element.
}element;

typedef element* gstack;

gstack createGStack(int stackSize,int dsize);//create a new stack.
int pushGStack(gstack s,void *dp);  //push new element in the stack.
int popGStack(gstack s,void *dp); //pop the last element from stack.
int freeGStack(gstack s);//emty the memory assigned to the stack;
int isGStackFull(gstack s);//check wether stack is full.
int isGStackEmpty(gstack s);//check wether stack is empty.
void print_operation();  //disply the user menu.
void MemCpy(void *des,void *src,int dsize);  //copy the contents from one address to another

int main()
{
   int size,dsize,element,number,number2,choice,status;
   
   void *pass,*pass2;
   
  
   gstack s1;   //creating the stack with given size.
  
   system("clear");
  
   print_operation();  //print user menu.

   printf("Enter your choice\n");
  
   scanf("%d",&choice);
 
   while(choice !=6)
{
   switch(choice)
 	{
		case 0:
		        printf("Enter the size of stack\n");

                         scanf("%d",&size);
                        
                        printf("Enter the size of data type\n");
                        
                        scanf("%d",&dsize);  
  
                          if((s1=createGStack(size,dsize))==NULL)   //creating the stack with given size.
                          {
                             printf("Error in creating an stack\n");
                          }
                          
                          break;   
                             
		case 1:
 			printf("Enter the element for inserting\n");
                        scanf("%d",&element);
                        
                        pass= &element;
                        if(( status=pushGStack(s1,pass))==0)
				{
					printf("Error !");
				}	
			break;

                case 2: 
                         pass=&number2;
                        if((element=popGStack(s1,pass)))
			{      
			        
 		         	printf("The last element in stack is %d.\n",number2); 
			}
			else
  			{
				printf("Error !\n");
			}
			
			break;

                case 3: 
                
                         element=freeGStack(s1);
		        	break;
		        			
		case 4:
           		if((element=isGStackFull(s1)))
			{
			  printf("Stack is full\n");
                        }
                        else
                        {
                            printf("stack is not full\n");
			}
    			break;
		case 5:
			 if((element=isGStackEmpty(s1)))
 				{
					printf("Stack is empty\n");
				}
			else
				{
					printf("stack is not empty\n");
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
        print_operation();
        printf("Enter your choice\n");
        scanf("%d",&choice);
}
   
       
}


gstack createGStack(int stackSize,int dsize)//create a new stack
{
   gstack stack1;
   void *data_A;
   
   stack1=(gstack)malloc(sizeof(gstack));  //create a stack.
   
   data_A=malloc(dsize*stackSize);    //allocate memory for storing the elements in stack.
   
    if(stack1!=NULL && data_A!=NULL)
    {
      stack1->size=stackSize-1; //assigning the size of stack
      stack1->dsize=dsize;   //assigning the size of data to be stored 
      stack1->count=-1;
   
      stack1->data=data_A;  //assiging the memory containor to data 
  
     return stack1;
   }
   
   return NULL;  
}


int pushGStack(gstack s,void *dp)  //function for pushing the element in stack.
{
   int check;
   
   
   if((check=isGStackFull( s )))
   { 
      printf("stack is full\n");
     return 0;
   }
    
    (s->count)++;
    
    MemCpy((s->data + (s->dsize)*(s->count)),dp,s->dsize);
    
    
     
     return 1;
}

int popGStack(gstack s,void *dp)  //function for geting the last element from the stack.
{
   int check;
   
   if((check=isGStackEmpty(s)))
   {
     return 0;
   } 
    
     MemCpy(dp,s->data+(s->dsize)*(s->count),s->dsize); 
   
   (s->count)--; 
   
   return 1;
    
}

int isGStackFull(gstack s)  //function for checking the status of stack.
{
   if(s->count==s->size)
   {
     return 1;
   }
   
   return 0;  
}


int isGStackEmpty(gstack s)  //function for checking the status of stack
{

   if(s->count==-1)
   {
      return 1;
   }
   
   return 0;    
}

int freeGStack(gstack s)//function for freeing the memory of stack.
{
   if(s==NULL)
   {
     return 0;
   }
   
   free(s->data);
   free(s);
   
   return 1;
}

void print_operation()  //function print user menu.
{  
   printf("0.Create a stack\n");
   printf("1.Insert a element in stack\n");
   printf("2.Pop element from stack.\n");
   printf("3.free the space of stack\n");
   printf("4.Check wether stack is full\n");
   printf("5.check wether stack is empty\n");
   printf("6.Exit\n");
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
    
