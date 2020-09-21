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

struct student *addSNodeSorted(struct student *start,struct student s);

int isPresentSNodeSorted(struct student *start,struct student s);

struct student* deleteSNodeSorted(struct student *start,struct student s);

void printLL(struct student *start);

struct student getinformation();

int getword(char *info,int size);

struct student *create_node();

void  printmenu();

int getroll(long long int *Roll);
 
int main()
{
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
                                 start=addSNodeSorted(start,new1);
                                 
                                 printf("Entry successiful \n");
                                 
                                 printf("\n\nPress any key to continue...\n"); 
                                 getchar();
                                 getchar();
				 break;

			case 2:  
				 system("clear");
 				 new1=getinformation();
 				 if((check=isPresentSNodeSorted(start,new1)))
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
 			         start=deleteSNodeSorted(start,new1);
 			         
 			         printf("Info was deleted\n");
 			         
 			         
 			         printf("\n\nPress any key to continue...\n");
 			         getchar();
 			         getchar();
				 break;
 			case 4: 
 				system("clear");
 				printLL(start);
 				
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
struct student *create_node(struct student info)
{
   struct student *newN;
   

   newN=(struct student *)malloc(sizeof(struct student));

  newN->next=NULL;
  
  strcpy(newN->F_name,info.F_name);
  strcpy(newN->S_name,info.S_name);
  newN->R_number=info.R_number;

  return newN;
}

struct student *addSNodeSorted(struct student *start,struct student s)
{
    struct student *new_s,*prev=NULL,*store;
    
    
    new_s=create_node(s);

    store=start;

    if(start == NULL )
    {    
	    
	    store=new_s;
	    return store;
    }    
	    

   while(start != NULL)
	{
	   if(start->R_number > new_s->R_number )
		{
                        if(prev == NULL)
			{
			   new_s->next=start;
			   
 			   return new_s;
			}
		  new_s->next=start;
		  prev->next=new_s;
                  
                   return store;
		}
  		 	
           prev=start;
	   start=start->next;
	}
         
	prev->next=new_s;
          
   return store;
}
       
int isPresentSNodeSorted(struct student *start,struct student s)
{   
   int count=0;
    while( start != NULL)
	{
	   if(start->R_number == s.R_number && strcmp(start->F_name,s.F_name)==0 && strcmp(start->S_name,s.S_name)==0 s)
		{
		    return count;
		}
	  start=start->next;
	  count++;
	}

return 0;
}

struct student *deleteSNodeSorted(struct student *start,struct student s)
{
  struct student *prev=NULL,*store;

    store=start;

   while(start != NULL)
        {
           if( start->R_number == s.R_number)
                {
                        if(prev == NULL)
                        {
                           store=start->next;
                        
                            free(start);

                           return store;
                        }
        
                  prev->next=start->next;
                    free(start);
                   return store;
                }

            prev=start;
           start=start->next;
        }

   return store;
 
}

void printLL(struct student *start)
{
   
   printf("NAME --------***********################-------------------------------################***********--------  Roll Number\n\n\n");
   
   while(start != NULL )
	{
         printf("%s %s         --------------------------------------------------------------------------------        %lld\n",start->F_name,start->S_name,start->R_number);
          
         start=start->next;
         
        }
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

void printmenu()
{
     printf("STUDENT INFORMATION SYSTEM -(SIS) \n");
    
     printf("\n1.Add a new student to the system.\n");
     
     printf("2.Check for student info in systen\n");

     printf("3.Delete student info from the system\n");
     
     printf("4.Print the stored information of student\n");
     
     printf("5.exit!\n");
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
