#include<stdlib.h>
#include<stdio.h>

#define MAX(a,b)  a>b ? a : b
#define MIN(a,b)  a>b ? b : a

typedef enum {false,true} bool;

typedef struct element
{
   int data;
   int BF;
   struct element *lchild;
   struct element *rchild;
   struct element *parent;
}treenode;


treenode* insAVL(treenode *t,int val); //insert element in tree return 1 successful insertion elese 0.
int serchAVL(treenode *t,int val);//search for 'val' in tree if present return number of comprasion elese 0. 
treenode* delAVL(treenode *t,int val);//delete 'val' in tree if successful return 1 else 0.
int trvsAVL(treenode *t);// print in-order transerval of tree.
int printBF(treenode *t);//print balance factor of the tree.
int height(treenode *t);//print the height of the tree.
treenode* alloc_t(); //allocate memory for AVL tree node.
treenode* find(treenode* t,int val,int np); //
treenode* rotate(treenode*zp,treenode *yp,treenode*xp,bool R1,bool R2);
treenode* insucc(treenode*,int key);

int main()
{

  treenode* t1=NULL;

  int t;

    t1=insAVL(t1,4);
    t1=insAVL(t1,7);
    t1=insAVL(t1,8);
    t1=delAVL(t1,8);
    t1=insAVL(t1,5);
   /* t1=insAVL(t1,4);
    t1=insAVL(t1,2);
   */ 

  int y;
  
    if((y=printBF(t1)) == 0)
     {
       printf("Tree is empty\n");
     };
}


int height(treenode *t)
{
    if(t == NULL )
     {
         return -1;
     }
    else
     {
         int lheight,rheight;
	 
	 lheight=height(t->lchild);
         rheight=height(t->rchild);

         return 1+ MAX(lheight,rheight);     
     }
}

int printBF(treenode *t)
{   
   int l;
    if(t == NULL )
	{
	   return 0;
	}
    else
     {
         printf("Balace factor \n root %d --- %d",t->data,t->BF);
         if(t->lchild == NULL)
         {
            printf("lchild NULL is 0");
         }
         else
         {
            printf("lchild %d --- %d",t->lchild->data,t->lchild->BF);
         }
         if(t->rchild == NULL)
         {
            printf("rchild NULL --- 0\n");
         }
         else
         {
            printf("rchild %d --- %d\n",t->rchild->data,t->rchild->BF);
         }            
         l=printBF(t->lchild);
         l=printBF(t->rchild);
     }
  
   return 1;
}

int trvsAVL(treenode * t)
{ 
   int l;
    if(t == NULL )
     {
        return 0;
     }
    else
     {
         l=trvsAVL(t->lchild);
         printf("%d",t->data);  
         l=trvsAVL(t->rchild);
     }
  
   return 1;
}

int serchAVL(treenode *t,int val)
{
  
  int comp=0,total;
  
  bool found=false;

  while(t != NULL && found == false)
  {
     if(t->data==val)
     {
        comp++;
        found = true;
     }
     else if(t->data < val)
     {
        comp++;
        t=t->rchild;
     }
     else
     {
        comp++;
        t=t->lchild;
    }
   }
   
   if(found == true)
   {
      return comp;
   }
   
   return 0;              
} 



treenode* insAVL(treenode *t,int val)
{  
   treenode *new,*store,*zp=NULL,*yp=NULL,*xp=NULL,*store_xl,*store_xr,*store_y,*temp;
   
   bool found=false,R1=false,R2=false;

   new = alloc_t(val);   //allocate memory for new node in AVL tree.
   
    printf("%c",'h');

   if(t == NULL ) //AVL tree is empty.
   {  
     return new;
   }   
   else
   { 

     store=t;  //hold the starting point of tree.
      
      xp=find(t,val,1);
      
     if(xp->data >= val)
     {
        xp->lchild=new;
        new->parent=xp;
        xp->BF+=1;
        yp=xp,xp=xp->lchild;
     }
     else
      {
         xp->rchild=new;
         new->parent=xp;
         xp->BF=(xp->BF)-1;
         yp=xp,xp=xp->rchild;
      }
   }  
          
      zp=yp->parent;
      
      
      
    
    //loop to find the first element in the tree where subtree get imbalance.
     while( zp != NULL && found != true )
     {   
         if(yp->BF != 0)  //if BF is not equal to zero then their must be increase in height of path followed.
         {
             if(zp->lchild == yp )//if left side.
             {
                zp->BF+=1;
             }
             else //or right side.
             {
               zp->BF-=1;
             }
         }
          
          /* Under following if condition the use of R1,R2 help in deciding which type of rotation 
             should be applied to the tree to make it height balanced.'left side of tree is TRUE' and 'right side of tree is FALSE'.
            if R1 = true,R2=true LL type of rotation ,if R1=false,R2=false RR type of rotation and other cases we do LR rotation.
          */    
         if(abs(zp->BF)>1)
          {
             found = true;

             if(zp->lchild == yp)
             {
                R1=true; 
             }
          
             if(yp->lchild == xp)
             {
                R2=true;
             }
             
          }
          
          if(found != true)
          zp=zp->parent,yp=yp->parent,xp=xp->parent;
     } 
    
        if(zp != NULL)
        {
           temp=rotate(zp,yp,xp,R1,R2);
           
           if(temp->parent == NULL )
           { 
              store=temp;
           }  
        }   
    
    return store;    
   }
	
treenode* delAVL(treenode* t,int val)
{
    int isp;

    treenode *prev=NULL;
    
    
    if((isp=serchAVL(t,val)))
    {
        treenode  *del_p,*tr,*zp,*xp,*yp,*inS,*temp;
        
        int check;
        
        del_p=find(t,val,0);
        
        
        
        if(( del_p->rchild == NULL && del_p->lchild == NULL) || (del_p->rchild == NULL) || (del_p->lchild==NULL))
        {
           
           if(del_p->lchild != NULL || del_p->rchild != NULL )
           {  
              
              if(del_p->lchild == NULL)
              {
                 temp=del_p->rchild;
               }
               else
               { 
                 temp=del_p->lchild;
                }
                
              if(del_p->parent->lchild == del_p)
              {
                 del_p->parent->lchild = temp;
                 
              }
              else
              {
                 del_p->parent->rchild=temp;
              }       
           }
           else
           { 
             if(del_p->parent->rchild == del_p)
             {
             del_p->parent->rchild= NULL; 
             }
             else
             {
              del_p->parent->lchild=NULL ;
             } 
           } 
          inS=del_p->parent;
          free(del_p);
        }
        else
        {
           inS=insucc(del_p,val);
           
           del_p->data=inS->data;
           tr=inS->parent;
           free(inS);
           inS=tr;
        }
        
        
         if(inS->rchild == NULL)
          {
             inS->BF+=1;
          }
          else
          {
             inS->BF-=1;
          }
          
         
            while(inS != NULL )
             {  
               bool R1=false,R2=false,rot=false;
               
                 if(abs(inS->BF) >1 )
                 {
                   zp=inS;
                   
                   if((check=height(inS->lchild)-height(inS->rchild))<0)
                   {
                     yp=inS->rchild;
                   }
                   else
                   {
                      yp=inS->lchild;
                      R1=true;
                   }
                   
                   if((check=height(yp->lchild)-height(yp->rchild))<0)
                   {
                     xp=yp->rchild;
                   }
                   else
                   {
                      xp=yp->lchild;
                      R2=true;
                   }
                   
                  inS=rotate(zp,yp,xp,R1,R2);
                  
                  rot=true;
                 }
                           
                 if(inS->BF == 0 && rot == false)
                 {
                    if(inS->parent->lchild == inS)
                    {
                       inS->parent->BF+=1;
                    }
                    else
                    {
                      inS->parent->rchild-=1;
                    }
                }
 		prev=inS;               
                 inS=inS->parent;
             }
             
          return prev;   
   }                      
       return t;             
}    

	
treenode* alloc_t(int val)
{
  treenode *new; 
   new=(treenode * )malloc(sizeof(treenode));
   
   new->data=val;
   new->BF=0;
   new->lchild=NULL;
   new->rchild=NULL; 
   new->parent=NULL;

return new;
}

treenode* find(treenode *t,int val,int np)
{

  treenode *xp;
  
    while(t != NULL  ) //move till we reach end of AVL Tree.
       {   
           if(np ==0 && t->data==val)
           {
              return t;
           }    
           if(t->data >= val ) //move  left.
            {   
              xp=t;
 	      t=t->lchild;
            }
           else //move right
            {  
              xp=t;  
               t=t->rchild;
            }
     }
     
     return xp;
}     


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
          pos=t;
        }
        
        return pos;  
}    

treenode *rotate(treenode *zp,treenode *yp,treenode* xp,bool R1,bool R2)
{  
    treenode *store_y,*store_xl,*store_xr;
      if( ((R1 == true && R2 == true ) || (R1 == false && R2 == false))  && zp != NULL)  //LL or RR rotation.
    {
       if(yp->lchild == xp)
        {
          store_y=yp->rchild;
          yp->rchild=zp;
          yp->parent=zp->parent;
          zp->parent=yp;
          zp->lchild=store_y;
          if(zp->lchild != NULL)
          zp->lchild->parent=zp;
       }
       else
       {
          store_y=yp->lchild;
          yp->lchild=zp;
          zp->rchild=store_y;
          yp->parent=zp->parent;
          zp->parent=yp;
          if(zp->rchild != NULL)
          zp->rchild->parent=zp;
       }
       zp->BF=0,yp->BF=0;
       
       return yp;  
    }
    if( (( (R1 == true && R2 == false ) || (R1 == false && R2 == true)) ) && zp != NULL)
    {
      if(yp->rchild == xp)
      {
        store_xr=xp->rchild,store_xl=xp->lchild;
        xp->parent=zp->parent;
        xp->lchild=zp,xp->rchild=yp;
        zp->parent=xp,yp->parent=xp;
        yp->lchild=store_xl,zp->rchild=store_xr;
        if(yp->lchild != NULL)
        yp->lchild->parent=yp;
        if(zp->rchild != NULL)
        zp->rchild->parent=zp;
      }
      else
      {
         store_xr=xp->rchild,store_xl=xp->lchild;
        xp->lchild=zp,xp->rchild=yp;
        xp->parent=zp->parent;
        zp->parent=xp, yp->parent=xp;
        yp->lchild=store_xr,zp->rchild=store_xl;
        if(yp->lchild != NULL)
        yp->lchild->parent=yp;
        if(zp->rchild != NULL )
        zp->rchild->parent=zp;
      }
      
      zp->BF=height(zp->lchild) - height(zp->rchild);
      yp->BF=height(yp->lchild) - height(yp->rchild);
      xp->BF=height(xp->lchild) - height(xp->rchild);
        
        
        return xp;  
    }
   
         
}      
           
