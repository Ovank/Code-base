/*##############################################################

  Author--OM_vats  Date --- jan 15  2020

  program to excute different program with switches.

##################################################################*/



#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

char * join (char *b)
{

	char *a= (char *) malloc (sizeof(char)* 20);
	int i=0;

	char c[5]="/bin/";

	for(int y=0;y<5;y++)
	{
		*(a+y)=*(c+y);
	}

	while(*(b+i) != '\0')
	{
		*(a+5+i)=*(b+i);
		i++;
	}

	*(a+5+i)='\0';

	return a;
}

int main(int argc,char *argv[])
{

	char *binaryPath;
	
	for(int f=1;f<argc-1;)
	{
		binaryPath=join(argv[f]);
		
		if(fork() == 0)
		{
		//	printf("%s %s\n",binaryPath,argv[f+1]);
	  		execl(binaryPath, binaryPath,argv[f+1], NULL);

			exit(0);
		}
		usleep(f*1000);

		f+=2;
	}

}

