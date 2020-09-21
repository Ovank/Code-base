#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
   int data;     //store data of the node.
   struct element *child; //hold the address of parent in the spanging tree.
   int  *next; //hold the address of array of connected component of node in the graph.
   struct element  *set; //hold the address of the set it belong to.
   int height; //hold the height of union tree.

}node;

typedef struct element1
{
   int weight;  //store the weight of edge.
   int start;  //store the starting vertex
   int end;   //store the terminal vertex.
}node1;

typedef struct ele
{
	int vet;   //store the vertex
	struct ele  *child; //store the address of parent of the vertex.
	struct ele  *set;//store the address of the set.
	int height;//store the height
}point;

int Union(node *a,node *b);
node* Find(int a);
node* graph(int size);
void spaning_tree(node *a,int b);
void graph_k(int v,int e,node1 *store_g,point *store_v);
void kruskal_algo();
void swap(node1 *a,node1 *b);
int bubble_sort(node1 *weight,int size);
int join(int a,int b);
point* Find_k(int a);

node * G_store;
int size;

int e,v;

point *store_v;
node1 *store_g;


int main()
{  
    
    int a,choice;
    
    printf("Select the operation\n");
    
    printf("find spanning tree\n");
    printf("find minimum spanning tree\n");
    
    scanf("%d",&choice);
    
    
    switch(choice)
    
    {
    
      case 1:
    	
    printf("Enter the number of vertices in the graph\n");

    scanf("%d",&size);

    G_store =graph(size);
    spaning_tree(G_store,size);


    for(int y=0;y<size;y++)
    {  
       printf("%d --->> ",(G_store+y)->data);	    
       if((G_store+y)->child != NULL)
       {
	       printf("%d",((G_store+y)->child)->data);
       }
       else
       {
          printf("head node");
       }
       printf("\n\n");
    } 
    
     break;
    case 2:
    
    
   	
   printf("Enter the number of vertices and edges in graph\n");

   scanf("%d%d",&v,&e);
 
    store_g=(node1*)malloc(sizeof(struct element1)*e);
    store_v=(point*)malloc(sizeof(struct ele)*v);

    graph_k(v,e,store_g,store_v);
    a=bubble_sort(store_g,e);
    kruskal_algo();

     for(int y=0;y<v;y++)
    {  
       printf("%d --->> ",(store_v+y)->vet);	    
       if((store_v+y)->child != NULL)
       {
	       printf("%d",((store_v+y)->child)->vet);
       }
       else
       {
          printf("head node");
       }
       printf("\n\n");
    } 
    break;
  }    

}


node* graph(int size)
{
   int u=0;
   
   int num,csize;

   G_store=(node*)malloc(size*sizeof(node));

   while(size-->0)
	{
		printf("Enter the number of connected component of vertices\n");
                 scanf("%d",&csize);
              
  			printf("Enter the tree node \n");
                         scanf("%d",&num);
                         
                         int *store;
                          
                         store=(int *)malloc(sizeof(int)*(csize+1));

			printf("Enter the components of the node\n");
			
                         (G_store + u)->data=num;
                         (G_store + u)->set = ( G_store + u);
			 (G_store + u)->child=NULL;
			 (G_store + u)->height=0;
                         
		          *store=csize+1;	 

			for(int f=1;f<csize+1;f++)
 			{
 				scanf("%d",(store+f));
			}

           ( G_store + u++ ) -> next = store;
           
	}
  
    return  G_store;
}


node* Find(int a)
{ 
	node *temp;

    	  for(int f=0;f<size;f++)
          {
	      if((G_store+f)->data == a)
                {  
			 temp=G_store + f;
                   while( temp->set != temp )
		   {
		       temp=temp->set;
		   }
		    
		    return temp;  
                }
           }
}

int Union(node* a,node* b) //Union by height.
{ 
      node *finda,*findb;
       
      finda=Find(a -> data ); findb=Find(b -> data);

      if(finda != findb  )  //check two node belong to same set or not.
        { 
		if(finda->height > findb->height)
		{

                    findb->set=finda;
		}
	       else if(finda->height < findb->height)
	       {
	            finda->set=findb;  
	       }
		else      //in case height of tree is same.
		{
			finda->set=findb;
			finda->height+=1;
		}

	   b->child=a;

	  return 1; 
        }

      return 0;
}

void spaning_tree(node *tree,int s)
{  
	node *temp;
	int a;
      for(int y=0;y<s;y++)
      {
          for(int d=1;d<*((tree+y)->next);d++)
	  {       
		  temp=Find(*((tree+y)->next+d));
		  a= Union(tree+y,temp);
	  }
      }
}

void graph_k(int v,int e,node1 *store_g,point *store_v) //store the graph in adjancey list.
{
    
	int weig,st,end;

	for(int y=0;y<e;y++)
	{
	   printf("Enter the weight of edge\n");

	   scanf("%d",&weig);

	   printf("Enter the two vertices\n");

	   scanf("%d%d",&st,&end);

	   (store_g +y)->weight=weig;
	   (store_g+y)->start=st;
	   (store_g+y)->end=end;

	}
        
	printf("Enter all the vertices of the graph\n");

	for(int y=0;y<v;y++)
	{
		scanf("%d",&((store_v+y)->vet));

		(store_v+y)->child=NULL;
		(store_v+y)->set=store_v+y;
                (store_v+y)->height=0; 
	}	
 
}	


point* Find_k(int a) //return the set element belongs to.
{
	point *temp;

    	  for(int f=0;f<v;f++)
          {
	      if((store_v+f)->vet == a)
                {
			 temp=store_v + f;
                   while( temp->set != temp )
		   {
		       temp=temp->set;
		   }

		    return temp;
                }
           }
}

int join(int a,int b) //Union by height.
{
      point *finda,*findb,*store_A,*store_B;
       
     
      finda=Find_k(a ); findb=Find_k(b);
        
     
      if(finda != findb  )  //check two node belong to same set or not.
        {    
		//printf("True\n");

		if(finda->height > findb->height)
		{

                    findb->set=finda;
		}
	       else if(finda->height < findb->height)
	       {
	            finda->set=findb;
	       }
		else      //in case height of tree is same.
		{
			finda->set=findb;
			finda->height+=1;
		}
          
		for(int u=0;u<v;u++) //find the position of a in arrya.
		{
			if((store_v+u)->vet == a)
			{
				store_A=store_v+u;
				break;
			}
		}
	       for(int u=0;u<v;u++) //find the address of b in array.
	       {
		       if((store_v+u)->vet == b)
		       {
			       store_B=store_v+u;
			       break;
			}	       
		}
            
	      if(store_B->child == NULL) //make  a as child of b /make b as child of a
	      {
	         store_B->child=store_A;
	      }
	      else
	      {
	          store_A->child=store_B;
	      }	
	  return 1;
        }

      return 0;
}


void kruskal_algo()//Find the minimum spanning tree.
{ 
	point *finds,*finde;
         int total=0,is; 
	for(int r=0;r<e || total!=v-1;r++)
	{
             
           if((is=join((store_g+r)->start,(store_g+r)->end)))
	   {
	       total++;
	   }
        }  	   
}

int bubble_sort(node1 *a,int e) //sort the weight of two edge.
{
      for(int y=0;y<e-1;y++)
      {
      		for(int l=0;l<e-y-1;l++)
		{
		    if((a+l)->weight>(a+l+1)->weight)
			    swap(a+l,a+l+1);
		}
      }

}

void swap(node1 *a,node1 *b) 
{
    node1 c;

    c.weight=a->weight;
    c.start=a->start;
    c.end=a->end;

    a->weight=b->weight;
    a->start=b->start;
    a->end=b->end;

    b->weight=c.weight;
    b->start=c.start;
    b->end=c.end;
}
