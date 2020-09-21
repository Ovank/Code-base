#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
int strcmp(const char *s1, const char *s2);

int main()
{
   genericLL g1,g2;
   
   g1=createGLL(20,(int (*)(void *,void *))strcmp);
   g2=createGLL(20,(int (*)(void *,void *))strcmp);
   
   //insert data to the first linked list.
   char *name[]={ "om","vibhu","aman","aayush","vats"},*first1,*second1;
   
   char nam[20];
   
   for(int f=0;f<5;f++)
   {
      printf("%s ",name[f]);
      
    }
    
    printf("\n");  
      
   
   //inserting data in normal node.
   addNodeGLL(g1,name[0]);
   addNodeGLL(g1,name[1]);
   addNodeGLL(g1,name[2]);
   addNodeGLL(g1,name[3]);
   addNodeGLL(g1,name[4]);
   
   //inserting data in sorted order.
   addNodeGLLSorted(g2,name[0]);
   addNodeGLLSorted(g2,name[1]);
   addNodeGLLSorted(g2,name[2]);
   addNodeGLLSorted(g2,name[3]);
   addNodeGLLSorted(g2,name[4]);
   
   int first,second,check;
   
   //checking presence of name in the list.
   first=isPresentGLL(g1,name[1]);
   second=isPresentGLL(g2,name[1]);
   
   if(first)
   { 
     check=getNodeDataGLL(g1,first,nam);
     printf("yes,\"%s\" is present in list at %d position\n",nam,first);
   }
   else
   {
     printf("NO,it is not present\n");
   }    
    
   
   if(second)
   { 
      check=getNodeDataGLL(g2,first,nam);  
     printf("yes,\" %s \" it is there at %d\n",nam,second);
   }
   else
   {
     printf("NO\n");
   }    
   
   check=deleteNodeGLL(g1,name[1]);
    
   first=isPresentGLL(g1,name[1]);
   
   if(first)
   { 
     check=getNodeDataGLL(g1,first,nam);
     printf("yes,it is present in list at %d position\n",first);
   }
   else
   {
     printf("NO,it is not present\n");
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
     
     int pos=1;
    
     while(  element != NULL )
     {  
        element=element->next;
        if(++pos == i)
         break;
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

