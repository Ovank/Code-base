/*##############################################################

  Author--OM_vats  Date --- jan 15  2020

  program to excute n excutable file.

##################################################################*/



#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>




int main(int argv,char *argc[])
{
	
	int status=1;

	for(int s=1;s<argv;s++)
	{
	
		if( fork() == 0)
		{
			
			if(execv(argc[s],argc) == -1)
			{
				perror("Error\n");
			}

			exit(0);
		}

		wait(&status);
	}


}


