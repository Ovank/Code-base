#include<stdio.h>
#include<stdlib.h>


typedef struct element
{
   int data;
   struct element *lchild;
   struct element *rchild;
   struct element *parent;
}treenode;

treenode *addnode(treenode *,int val);
treenode *serch_tree(treenode *,int val);
treenode *delete_node(treenode *,int val);

int main()
{
}

treenode *addnode(treenode *t,int val)
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
		        
			t->lchild=addnode(t->lchild,val); //recursion call to the left side of the tree.
			(t->lchild)->parent=t;
		}
	   else
		{        
                        
			t->rchild=addnode(t->rchild,val); //recursion call to the right side of the tree.
			(t->rchild)->parent=t;
		}
        
   
        return t;  //returning pointer to the parent.
}
   
treenode *serch_tree(treenode *t,int val)
{   
   int check;
     
     if(t == NULL )
     {
       return NULL;
     }  
     else if((check=numcmp(&val,&(t->data))==0)
     {
        return t;
     }
     
     else if(check < 0)
     {
        t=serch_tree(t->lchild,val);
     }
     else
     {
        t=serch_tree(t->rchild,val)
        
     }
     
}  


treenode *delete_node(treenode *t,int val)
{
   
   treenode *l;
   
   l=serch_tree(t,val);
   
   if( (l->lchild  && l->rchild ) == NULL )
   {
      (l->parent)->lchild = NULL;
      (l->parent)->rchild = NULL;
      
      free(l);
      
   }
   else if((l->lchild || l->rchild )== NULL  )
   {
      if((l->lchild) == NULL)
      {
        l->parent->   
