#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
   int weight;
   int start;
   int end;
}node;

typedef struct ele
{
	int vet;
	struct ele  *child;
	struct ele  *set;
	int height;
}point;

void graph(int v,int e,node *store_g,point *store_v);
void kruskal_algo();
void swap(node *a,node *b);
int bubble_sort(node *weight,int size);
int Union(int a,int b);
point* Find(int a);

int e,v;

point *store_v;
node *store_g;

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
//	    printf("%d %d %d\n",(store_g + y)->weight,(store_g +y)->start,(store_g + y)->end);
    }   

}

void graph(int v,int e,node *store_g,point *store_v)
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


point* Find(int a)
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
        
     printf("Enter the parent a and b is %d %d",finda->vet,findb->vet) 
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
          
		for(int u=0;u<v;u++)
		{
			if((store_v+u)->vet == a)
			{
				store_A=store_v+u;
				break;
			}
		}
	       for(int u=0;u<v;u++)
	       {
		       if((store_v+u)->vet == b)
		       {
			       store_B=store_v+u;
			       break;
			}	       
		}

	   store_B->child=store_A;

	  return 1;
        }

      return 0;
}


void kruskal_algo()
{ 
	point *finds,*finde;
         int total=0,is; 
	for(int r=0;r<e || total!=v-1;r++)
	{
               // printf("The first and second is %d %d\n",(store_g+r)->start,(store_g+r)->end);
           if((is=Union((store_g+r)->start,(store_g+r)->end)))
	   {
	       total++;
	   }
        }  	   
}

int bubble_sort(node *a,int e)
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

void swap(node *a,node *b)
{
    node c;

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
