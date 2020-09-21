#include<stdio.h>

#define SIZE_STACK 100

int pop();      //function used for deleting or geting the top element from stack.
int push(int element);  //function used for inserting a new element in the stack.

int stack[SIZE_STACK];

int top=-1;

int main()
{  
	printf("select the operation you want to perform\n");
	printf("1.Push a new element in the stack\n");
	printf("2.Pop the last element from stack\n");

	int select,element,find;

	scanf("%d",&select);

	switch(select)
	{
		case 1:  
			printf("Enter the element to add in stack\n");
			scanf("%d",&element);

			if(find=push(element))
			{
				printf("Element added succesfuly in the stack\n");
			
			}

			break;

		case 2:
		        element=pop();
			
			printf("The last element is %d.\n",element);
			break;
		Default:
			printf("Invalid choice\n");
			break;	
	}

}

int push(int element)
{
	if(top==SIZE_STACK)
	{
		printf("stack overflow\n");
		return 0;
	}

	stack[top++]=element;

	return 1;
}

int pop()
{
  if(top==-1)
  {
	  printf("stack underflow\n");

	  return 0;
  }

  return stack[top--];
}
