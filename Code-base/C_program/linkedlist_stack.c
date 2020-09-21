#include<stdio.h>

struct element 
{
  int data;
  struct elemnt * next;
}element;

typedef  element* list;
  
int main()
{
}

list create_element(int data)
{
   list x;
   
   x = ( list ) malloc( sizeof( element ) );
   
   x->data = data;
   
   return x;
}   

list element_serch(list start,int key)
{
    while(start != NULL )
    {
       if(start->data == key)
       {
         return start;
       }
       
       start = start->next ;
   }
   
   return NULL;
}      

int insert_element(list start,list element)
{
      if(element != NULL )
      {
        element->next=start;
        
      
