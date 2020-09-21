/*##############################################################

  Author--OM_vats Assignement---"2nd" Date --- jan 12 2020

##################################################################*/



#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<stdlib.h>
#include <sys/wait.h>

int main() 
{

		for(int i=0;i<3;i++) // loop will run n times (n=3)
   			 { 
       				 if(fork() == 0) 
       					 { 
         					   printf("hello world %d\n",(i+1)); 
       						     exit(0);//terminate the process.

      					  } 
   		
				 wait(NULL); 	//Here wait function suspends the parent process and wait till the child process is terminated. 
   			 } 
	 
	 return 0; 
} 

