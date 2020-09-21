/*##############################################################

  Author--OM_vats Assignement---"2nd" Date --- jan 12 2020

##################################################################*/



#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

void invert(char * a)  //function for inverting the string and print it.
{
	int s=0;

	 while( *(a+s) != '\0')  //calculate the size of the string 
       		 {
               		 s++;
       		 }

	char temp[s];  //temprory storage 

	for(int d=0;d<s;d++)  //invert the string.
	{
		temp[d]=*(a + s-1 - d);

	}

	temp[s]='\0';  //terminate the sting.

	printf("%s ",temp);  //prints the inverted string.

}

int main(int argc,char *argv[])
{
	
	for(int d=1;d < argc ;d++)
	{	
		if(fork() == 0)	{ 
			invert( *(argv+d));  //invert the given string.
			exit(0); //terminates the process.
		}
			
		usleep(d*1000);  /* wait 1ms for child 1, 2ms for child 2,... */
	}

}
