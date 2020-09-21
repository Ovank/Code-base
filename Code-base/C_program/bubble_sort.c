#include<stdio.h>

void modif_bubble_sort(int *array,int size);
void bubble_sort(int *array,int size);
void swap(int *a,int *b);

int main()
{
	 int number[]={10,9,8,7,6,5,4,3,2,1};
	 bubble_sort(number,10);

	 for(int f=0;f<10;f++)
	 {
		 printf("%d ",number[f]);
	 }	 
}

void bubble_sort(int *array,int size)
{
	for(int t=0;t<size;t++)
	{
		for(int j=0;j<size-t-1;j++)
		{
			if(*(array+j)>*(array+j+1))
			{
				swap(array+j,array+j+1);
	                }
		}	
	}
}

void swap(int *a,int *b)
{
	int store;
	store=*a;
	*a=*b;
	*b=store;
}

/* This is modified verson of bubble sort which take O(n) complexity for best case  i.e when array is sorted.
 */

void modif_bubble_sort(int *array,int size)
{
        for(int t=0;t<size;t++)
        {
		int flag=0;

                for(int j=0;j<size-t-1;j++)
                {
                        if(*(array+j)>*(array+j+1))
                        {
                                swap(array+j,array+j+1);
				flag=1;
                        }
		
		}

		if(flag==0)
		{
			break;
		}	
                
        }
}

