#include<stdio.h>
#include<stdlib.h>

#define fori(a,b,c) for(int i=a;i<b;i+=c)

typedef struct node
{
   int data;  //store data in the node of tree.
   struct node *lchild; //hold the address of left child of the tree.
   struct node *rchild; //hold the address right child of the tree.
   struct node* parent; //hold the address of parent of the node.
}treenode;

int l=0;

treenode *getTreeinPre(int a[],int asize,int b[],int bsize);
treenode *addnode(treenode *,int val);
int inorder(treenode *t);
int preorder(treenode *t);
int numcmp(int *,int *);

int main()
{
   treenode *t;
   
   int a[]={1,2,4,5,7};
   int b[]={5,4,1,2,7};
   
   t=getTreeinPre(a,5,b,5);
   
   int l=preorder(t);
   printf("\n");
   
   l=inorder(t);
   
}

treenode *addnode(treenode *t,int val)
{

   if(t == NULL )
   {
      t=(treenode *)malloc(sizeof(treenode));
      t->data=val; //assign the value to the tree node.
      t->parent=NULL; //assigne parent address as null.
      t->rchild=NULL;
      t->lchild=NULL;
   }
   else if( numcmp(&val,&(t->data)) <= 0)
   {
       t->lchild=addnode(t->lchild,val);
       (t->lchild)->parent=t; //assign address of parent element.
   }
   else
   {
      t->rchild=addnode(t->rchild,val);
      (t->rchild)->parent=t; //assigne  the address of parent element.
   }
   
  return t;
  
}           
         
treenode *getTreeinPre(int a [],int asize,int b[],int bsize)  //a-contain inorder transversal b-contain preorder transversal
{
   treenode *t;
   
   int index;
   t=NULL;
   
   if(asize == 0)
   {
     return t;
   }
     
   fori(0,asize,1)
   {
      if(b[l] == a[i] )
      {
         index=i;
      }
   }
  
   l++;
   t=addnode(t,a[index]);
  t->lchild=getTreeinPre(a,index,b,bsize);
  t->rchild=getTreeinPre(a+index+1,asize -index-1,b,bsize);
  
  return t;
}    
   
int inorder(treenode *t)
{  
   int l=0;
   
   if(t == NULL )
   {
     return l;
   }
   
   printf("%d",t->data);
   l=inorder(t->lchild);
   l=inorder(t->rchild);
   
   return l;           
}

int preorder(treenode *t)
{
   int l=0;
   
   if(t == NULL )
   {
     return l;
   }
   
   
   l=preorder(t->lchild);
   printf("%d",t->data);
   l=preorder(t->rchild);
   
   return l;
}          

int numcmp(int *a,int *b)
{
   return *a-*b;
}      
