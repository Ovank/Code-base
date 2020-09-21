#include<stdio.h>
#include<stdlib.h>

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

void graph_k(int v,int e,node *store_g,point *store_v);
void kruskal_algo();
void swap(node *a,node *b);
int bubble_sort(node *weight,int size);
int Union_k(int a,int b);
point* Find_k(int a);

int e,v;

point *store_v;
node1 *store_gr;

int main()
{  
	int a;
   	
   printf("Enter the number of vertices and edges in graph\n");

   scanf("%d%d",&v,&e);
 
    store_g=(node*)malloc(sizeof(struct element)*e);
    store_v=(point*)malloc(sizeof(struct ele)*v);

    graph(v,e,store_g,store_v);
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


point* Find(int a) //return the set element belongs to.
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

int Union(int a,int b) //Union by height.
{
      point *finda,*findb,*store_A,*store_B;
       
     
      finda=Find(a ); findb=Find(b);
        
     
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
             
           if((is=Union((store_g+r)->start,(store_g+r)->end)))
	   {
	       total++;
	   }
        }  	   
}

int bubble_sort(node *a,int e) //sort the weight of two edge.
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
