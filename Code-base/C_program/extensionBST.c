
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX(a,b) a>b ? a : b
#define MIN(a,b) a>b ? b : a

typedef struct node
{
   int data;
   struct node *lchild;
   struct node *rchild;
   struct node *parent;
}treenode;


int isEmpty(treenode *t);
treenode *insertNode(treenode *t,int val);
void printmenu();

int height(treenode *t);
int max(treenode *t);
int min(treenode *t);
int equal(treenode *t1,treenode *t2);
treenode *insucc(treenode *t,int key);
treenode *find(treenode *t,int key);
int numcmp(int *,int *);
void printparent(treenode *t);

int main()
{
 
  printmenu();  //prints the user memu.

  int choice,element,val=0;

  scanf("%d",&choice);
  

  treenode *t1=NULL,*t2=NULL,*t3;


 while(choice != 8)  //run until user enter digit 8.
 {

  switch(choice)
  {

  case 1:                                    //take a new node to add in tree.
    printf("Enter the element\n");

    scanf("%d",&element);
      
    t1=insertNode(t1,element);

    break;

  case 2:                                       //find the height of tree.
    printf("The height of the tree is ");

    element=height(t1);

    printf("%d\n",element);

    break;
  case 3:                                               //find maximum element in the tree.
    printf("The maximum element in the tree ");

    element=max(t1);
   printf("%d",element);

    break;
  case 4:                                               //find minimum element in tree.
    
    element=min(t1);
    
    if(element == INT_MAX)
    {
      printf("Tree is empty\n");
    }  
    else
    {
      printf("The minimum element in the tree ");
      printf("%d\n",element);
    }  
    break;
  case 5:                                       //finds in-order successer of an elemtnt in tree.
    printf("Enter the number to find in-order successor in the tree\n");

    scanf("%d",&element);
      
      t3=find(t1,element);
      t3=insucc(t3,element);
   if(t3 == NULL )
   {
	   printf("No in-oder succeser in the tree\n");
   }   
   else
   {
         printf("The in-order successor of the element is %d\n",t3->data);
   }

    break;
    
  case 6:
        printf("Enter element in second tree \n");
         scanf("%d",&val);
        t2=insertNode(t2,val);
	break;

        
  case 7:
         if(val=equal(t1,t2))
         {
            printf("The trees are equal\n");
         }
         else
         {
            printf("The trees are not equal\n");
         }         
          
          break;     

  default :
    printf("Invalid choice\n ");
    break;
  }

  printmenu();

  scanf("%d",&choice);
}

}



treenode *insertNode(treenode *t,int val)
{
    int check;

           if(t == NULL ) //add node only when you at end of the tree.
                {

	                t=(treenode *)malloc(sizeof(treenode));  //allocate memory for storing the data.

                        t->data=val;  //copying the value.
	                t->lchild=NULL; //making pointer to point to null.
	                t->rchild=NULL;//making pointer to point to null
                        t->parent=NULL; //assigning the parent node address
                }

	 else if( (check=numcmp(&val,&(t->data)))<= 0)
		{

			t->lchild=insertNode(t->lchild,val); //recursion call to the left side of the tree.
			(t->lchild)->parent=t;
		}
	   else
		{

			t->rchild= insertNode(t->rchild,val); //recursion call to the right side of the tree.
			(t->rchild)->parent=t;
		}


        return t;  //returning pointer to the parent.
}



int numcmp(int *a,int *b)
{
    return *a-*b ;    //return negattive ,positive or zero depending on their difference.

}

void printmenu()  //function print menu.
{
   printf("1.Insert a new element in the tree.\n");
   printf("2.Find height of the tree.\n");
   printf("3.Find maximum element in tree.\n");
   printf("4.Find minimum element in tree\n");
   printf("5.To find  in-order successor \n");
   printf("6.Add new elemwnt in second tree\n");
   printf("7:check the two trees are equal\n");

   printf("Select the option for operation\n");
}

/*int height(treenode *t)
{
    if(t== NULL )
	{
 	  return 0;
	}
    
    int lheight=height(t->lchild);
    int rheight=height(t->rchild);
    
    return 1+ MAX(lheight,rheight);
  //return (1+MAX(height(t->lchild),height(t->rchild)));
}*/

int height(treenode* node)  //function print the height of the tree.
{ 
   if (node==NULL)  //whwn you reach end point.
       return 0; 
   else 
   { 
       // compute the depth of each subtree 
       int lDepth = height(node->lchild); 
       int rDepth = height(node->rchild); 
  
       // use the larger one 
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}  

int max(treenode* t)  //function to find maximum element in the tree.
{
   if(t == NULL )   //if tree is empty.
	{
	  return EOF;  //return -1
	}

   return MAX(t->data,max(t->rchild));  //else it recursively call itself.
}

int min(treenode *t)  //function to return minum element from tree.
{
   if(t ==NULL )  //if tree is empty.
	{
  	  return INT_MAX; 
	}

   return MIN(t->data,min(t->lchild));
}

int equal(treenode *t1,treenode *t2)
{
    if(t1 == NULL && t2 == NULL )  //then both trees are empty.
      {     
           return 1;
      }
    else if(t1 ==  NULL || t2 == NULL)  //when either of the tree are empty.
      {        
           return 0;
      }
    else if( numcmp(&(t1->data),&(t2->data)) != 0) //when elements are not equal in the tree.
      {  
        
         
         return 0;
      }
    else    //when the present element are equal,we move to the next node
     {  
       return MIN(equal((t1->lchild),(t2->lchild)),equal((t1->rchild),(t2->rchild))); //it return 0/1 basing on the elements are equal or not.
    }
}
/*
treenode * insucc(treenode *t,int key)
{
      int check;
    if(t == NULL )
	{
	   return NULL;
	}

   treenode* l;

   l=find(t,key);

    if(l->rchild != NULL )  //if right child of the node is not null.
     {
        t=l->rchild;
        while(t->lchild != NULL )
          {
            t=t->lchild;
          }

         return t;
     }
    else
     {   
        if(key > l->parent->data )
	{
		return NULL;
	}
	else
	{
		return l->parent;
	}	
    }
}
*/

treenode* insucc(treenode* t,int key)
{
   treenode* pos=t;
   
   if(t->rchild != NULL)
    {
       pos=t->rchild;
       
       while(pos->lchild !=NULL)
       {
          pos=pos->lchild;
       }
       
       return pos;
    }
    
    
    while(t->parent != NULL && t->parent->data<key  )
        {
              t=t->parent;                  
        }
        
        if(t != NULL)
        {
          pos=t->parent;
        }
        
        return pos;  
}         
treenode *find(treenode *t,int key)
{
    treenode *tr;
    int check;
   
   while(t != NULL)
   {
      if(t->data == key)
      {
         return t;
      }
      else if(t->data < key)
      {
        t=t->rchild;
      }
      else
      {
         t=t->lchild;
      }
   }
   
   return NULL;           
   

}

void printparent(treenode *p)
{
	 while( p != NULL )
	 {
		 printf("%d ",p->data);
		 p=p->parent;
	 }
}	 
