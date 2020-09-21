#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 50  //size of each string.

struct student
{
  char F_name[MAX_SIZE];  //first name.
  char S_name[MAX_SIZE];  //last name.
  long long int R_number; //roll number.
  
  struct student *next;   //pointer to next structure.

};   

struct node
{

   void *data;
   struct node* next;
};

struct gll
{

   int dsize;  
   int (*compareFn)(void *,void *);
   struct node *list;

};


typedef struct gll* genericLL;


genericLL createGLL(int dsize,int (*cfunction)(void *,void *));
//In this function call int (*cfunction)(void *,void *) is a pointer to a function.In this deleraction cfunction is a pointer which point to the function and int is data type which function return and the function take two parameter which are of void datatype.
void addNodeGLL(genericLL g,void *d);
void addNodeGLLSorted(genericLL g,void *d);
int isPresentGLL(genericLL g,void *d);
int deleteNodeGLL(genericLL g,void *d);
int getNodeDataGLL(genericLL g,int i,void *d);
void MemCpy(void *,void *,int size);
int compare_lli(long long int *, long long int *);
int strcmp1(struct student *,struct student *);



void printLL(genericLL g);

struct student getinformation();

int getword(char *info,int size);

struct student *create_node();

void  printmenu();

int getroll(long long int *Roll);

int main()
{
   genericLL g1;
    
    
    g1=createGLL(sizeof(struct student), (int (*)(void *,void *))strcmp1);      
    int choice,check;
    
   
 
    struct student new1;
    
    struct student *start;
    
    start=NULL;
    
    printmenu();
    
    printf("\n\n select the operation \n");
     
    scanf("%d",&choice);
    
    while(choice != 5)
	{
              
             switch(choice)
                  {
                     
                       case 1:   
                                 system("clear");
                                 new1=getinformation();
                                 
                                 printf("%s %s %lld",new1.F_name,new1.S_name,new1.R_number);
                                 addNodeGLL(g1,&new1);
                                 
                                 printf("Entry successiful \n");
                                 
                                 printf("\n\nPress any key to continue...\n"); 
                                 getchar();
                                 getchar();
				 break;

			case 2:  
				 system("clear");
 				 new1=getinformation();
 				 if((check=isPresentGLL(g1,&new1)))
 				 {
 				   printf("The student info is present in system\n");
 				 }
 				 else
 				 {
 				   printf("The student info is not present in systen\n");
 				 }
 				 
 				 
 				 printf("\n\nPress any key to continue...\n");
 				 getchar();
 				 getchar();
				 break;
 			case 3: 
 			         system("clear");
 			         new1=getinformation();
 			         check=deleteNodeGLL(g1,&new1);
 			         
 			         printf("Info was deleted\n");
 			         
 			         
 			         printf("\n\nPress any key to continue...\n");
 			         getchar();
 			         getchar();
				 break;
 			case 4: 
 				system("clear");
 				printLL(g1);
 				
 				printf("\n\nPress any key to continue...\n");
 				getchar();
 				getchar();
 				break;
 		 	default:
 		 	 	 printf("Invalid choice...\n\n");
 		 	 	 
 		 	 	 
 		 	 	 printf("\n\nPress any key to continue...\n");
 		 	 	 getchar();
 		 	 	 getchar();
				 break;
 		 	 	 
 		 }
		
		system("clear");

 		 printmenu();
    
    		printf("\n\n select the operation \n");
     
    		scanf("%d",&choice);
 	}	 	 	  		         	      
   
   
   
   
   
   
   
}

genericLL createGLL(int dsize,int (*cfunction)(void *,void *)) //parameters are data size of each elemnt and function pointer for comparision
{

   genericLL g1;

   g1=(genericLL)malloc(sizeof(struct gll));  //assigne memory for genric list control menu.

  
   g1->dsize=dsize;  //assigne the size of element of linked list which store the data;

   
   g1->compareFn=cfunction;   //store the address of the comparision function given by user.

   g1->list=NULL;
   
   //printf("list is created\n");
   
   return g1;

}


void addNodeGLL(genericLL g,void *d)//the function take address of list menue and address of data to be copied in the list.
{
        
	struct node *element,*start;


        element=(struct node *)malloc(sizeof(struct node)); //allocate memory for the node. 
        element->data=malloc(g->dsize); //allocate the memory for storing the data.default datatype of void type.
        element->next=NULL;  //assigne the address as NULL.

        // printf("memory is allocated \n");
         
        MemCpy(element->data,d,g->dsize);  //copy the memory to the destination func(dest,source)
         
         // printf("data is copied to memory\n");
   
	start=g->list;   //gets the address of starting list
	
 	if(g->list == NULL ) //first element in the list.
	 {
	    g->list=element;
            
	   return;  //terminates the function.
	}
	
 	while(start->next != NULL)
 	{
	   start=start->next;  //move to the next node.
	}

	start->next=element;   //link the new element to the list.
	
	//printf("Node is added\n");
	
} //the function has O(n) complexity where n is number of elements stored in the list.

//this function assume that the list is already sorted in the required order and new element will take desirable place to keep list as sorted. 

void addNodeGLLSorted(genericLL g,void *d)
{
    struct node *element,*start,*prev=NULL;
    
    int check;

    element=(struct node *)malloc(sizeof(struct node)); //allocate memory for the node.
     
    element->data=malloc(g->dsize); //allocate the memory for storing the data.default datatype of void type.
    
    element->next=NULL;  //assigne the address as NULL.

    MemCpy(element->data,d,g->dsize); //copies the data to the assigned memory.
    
    start=g->list; //takes the address of the starting of list.
    
    if(start == NULL )
    {
       g->list=element;
       return;
    }
       
    while(start != NULL )
    {
      if((check=(g->compareFn)(element->data,start->data)) < 0) //comparision function is called for comparision. second parameter is greater than first parameter.
	     {
		 
                     if(prev == NULL )//position of new element is at the begining of the list 
			{
			       element->next=g->list; //add new node to the list.
				g->list=element;  //update the head of the list.
				
				return ;
			}
			
			//insert the node to the list.
			element->next=start;
			prev->next=element;
			
			return ;
		
	  }
       
      prev=start;   //store the present pointer to the previous pointer.
      start=start->next; //move to the next element.
   }

   prev->next=element; //assigne to the last node.
   
   
}//the function have O(n) time complexity.     

//the function return posotion of the data if data is prsent in the list elsee it return 0.
  
int isPresentGLL(genericLL g, void *d)//take pointer to the list menue and pointer to genric data type.
{
   struct node *element;
   
   int check,pos=0;
   
   element=g->list;  //take the address of the bening of the list.
   
   while(element != NULL )
   {   
       pos++; //increment the pos,as we move to next data in the list.
      if((check=(g->compareFn)(element->data,d)) == 0) //case when both the data are same.
      {
         return pos;
      }
    
            element=element->next;
  }
  
  return 0;          
}//the complexity of the function is of order O(n).

//the function return the posotion of the deleted node from the list otherwise it return 0.

int deleteNodeGLL(genericLL g, void *d)//parameters to the function is the address of list menue and the address to the data.
{   
    struct node *element,*prev; 
    int check,pos=0;
    
    
    element=g->list; //takes the address of the first element of the list.
     
     while(element != NULL )
   {   
       pos++; //increment the pos,as we move to next data in the list.
      if((check=(g->compareFn)(element->data,d)) == 0) //case when both the data are same.
      {
          if(prev == NULL ) //first element of the list.
          {
            g->list=element->next; //assigne second lemnt to the head.
          }
          else
          {
             prev->next=element->next;
          }
          
          free(element->data); //release the memory of allocated to the data.
          free(element);  //release the memory alloated to the node.
            
            return pos;   
      }
            prev=element;
            element=element->next;
  }
  
  return 0;   //if data is not present in the list.  
}//The complexity of this function is O(n).

int getNodeDataGLL(genericLL g, int i, void *d)
{
     struct node *element;
     
     element=g->list;
     
     int pos=0;
    
     while(  element != NULL )
     {  
        if(++pos == i)
         break;
        element=element->next;
        
     }
     
     
     if(element != NULL )
     {    
         MemCpy(d,element->data,g->dsize); //coies the data to the destination.
        return 1;
     }
     
     return 0;      
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

struct student getinformation()
{
    struct student new_Student;
    
    int check;
    
    while(printf("Enter the first name of student:-"),getchar(),check=getword(new_Student.F_name,MAX_SIZE),check == EOF )
       {
            printf("This feild can't be left empty\n");
             getchar();
             printf("Please Enter to continue\n");
             getchar();
             system("clear");
        }
      
      while(printf("Enter the last name of student:-"),check=getword(new_Student.S_name,MAX_SIZE),check == EOF )
       {
            printf("This feild can't be left empty\n");
             getchar();
             printf("Please Enter to continue\n"); 
             getchar();
             system("clear");
        }

      while(printf("Enter the roll number of student:-"),check=getroll(&(new_Student.R_number)), check == EOF )
       {
            printf("This feild can't be left empty\n");
             getchar();
             printf("Please Enter to continue\n");
             getchar();
             system("clear");
        }
      
      
     return new_Student ;
}

void printmenu()
{
     printf("STUDENT INFORMATION SYSTEM -(SIS) \n");
    
     printf("\n1.Add a new student to the system.\n");
     
     printf("2.Check for student info in systen\n");

     printf("3.Delete student info from the system\n");
     
     printf("4.Print the stored information of student\n");
}

int getroll(long long int *Roll)
{
	char a;

	a=getchar();

	if(a=='\n')
	{
		 return EOF;
	}
        
	*Roll=(a-'0');
        while(a=getchar(),a != '\n' )
	{
	     *Roll=(*Roll)*10+(a-'0');
        }
  return 1;	
}

int getword(char *word,int size)
{
   char a;
   char worda[100];
   int g=0;
   while(scanf("%c",word),worda[g++]=*word,*word++!='\n');

   if(worda[0]=='\n')
   {
      return EOF;
   }
   *(--word)='\0';
   return 1;
}


void printLL(genericLL g)
{
   struct student info;
   int check,l=0;
   printf("NAME --------***********################-------------------------------################***********--------  Roll Number\n\n\n");
   
   
   while((check=getNodeDataGLL(g,++l,&info)))
	{
         printf("%s %s         --------------------------------------------------------------------------------        %lld\n",info.F_name,info.S_name,info.R_number);
          
         
        }
}

int
compare_lli ( long long *a,  long long int *b)
{
  const long long int *da = (const long long int *) a;
  const long long int *db = (const long long int *) b;

  return (*da > *db) - (*da < *db);
}

int strcmp1(struct student *a,struct student *b)
{
    return compare_lli(&(a->R_number),&(b->R_number));
}     
