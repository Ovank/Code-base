
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
   int data;
   struct node *lchild;
   struct node *rchild;
   struct node *parent;
}treenode;


int isEmpty(treenode *t);
treenode *insertNode(treenode *t,int val);
int getCount(treenode *t);
int inorder(treenode *t);
int preorder(treenode *t);
int postorder(treenode *t);
int numcmp(int *,int *);
void printmenu();

int main()
{
    
   treenode *t1;
   
    t1=NULL;
   
    int num,check,select;
 
    printmenu();

    scanf("%d",&select);


   while(select != 7)
	{
		switch(select)
 			{
				case 1:
				        printf("Enter the value to insert in tree\n");
					scanf("%d",&num);
					
					t1=insertNode(t1,num);
                                        getchar();
                                        break;
				case 2:
					check=isEmpty(t1);
					if(check)
					{
						printf("Yes,tree is empty\n");
					}
					else
					{
						printf("No,tree is not empty\n");
					}
				        
                                        getchar();
                                        break;
                                case 3: 
				         printf("Total number of elements in the tree is %d.\n",num=getCount(t1));
 					 getchar();
					 break;
				case 4:
					printf("Inorder transveral of the tree is:-\n");
					
					check=inorder(t1);
                                        
                                         printf("\n");
					getchar();
					break;
				case 5:
                                        printf("Preorder transveral of the tree is:-\n");

                                       check= preorder(t1);

                                         printf("\n");
                                        getchar();
                                        break;
				case 6:
                                        printf("Postorder transveral of the tree is:-\n");

                                        check=postorder(t1);

                                         printf("\n");
                                        getchar();
                                        break;
			      default :  
                                          printf("Invalid choise! ..");
                                             getchar(); 
					break;
		}
	
		printmenu();
                scanf("%d",&select);
  }	
				 
}

int isEmpty(treenode *t)
{
   if(t == NULL)
	{
	   return 1;
	}

   return 0;

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

    
int getCount(treenode *t)
{
   
   treenode *start;

   start=t;

   while(start != NULL )
	{
	   return 1+getCount(start->lchild) + getCount(start->rchild) ;
        }
}

int inorder(treenode *t)
{   
   int k;
    if(t == NULL )
    {

	return 0;
    }
    
    else
    {
 	printf("%d ",t->data);
	 k=inorder(t->lchild);
         k=inorder(t->rchild);
    }
   
    return 1;
}


int preorder(treenode *t)
{  
	int k;

    if(t == NULL )
    {

        return 0;
    }

    else
    {
        k=preorder(t->lchild);
        k=preorder(t->rchild);
        printf("%d ",t->data);
    }

    return 1;
}

int postorder(treenode *t)
{  
	int k;
    if(t == NULL )
    {

        return 0;
    }

    else
    {
        
        k=postorder(t->lchild);
        printf("%d ",t->data);
        k=postorder(t->rchild);
    }

    return 1;
}

int numcmp(int *a,int *b)
{
    return *a-*b ;

}

void printmenu()
{
   printf("1.Insert a new element in the tree.\n");
   printf("2.Check wether tree is empty.\n");
   printf("3.Get total number of element in tree\n");
   printf("4.Print inorder transversal of tree\n");
   printf("5.Print postorder transversal of tree\n");
   printf("6.Print preorder transversal of tree\n");

   printf("Select the option for operation\n");
}		
