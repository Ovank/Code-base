
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>


int main(int argc,char *argv[])
{


        if(fork() == 0)
        {	
		printf("first child is running ...\n");

        	int pfd[2];  //pipe file descripter.
		pipe(pfd);

			if(fork() == 0)
			{
				printf("second child process started ...\n");

        		        close(pfd[1]);
				dup2(pfd[0],0);
				close(pfd[0]);
				printf("excuting \"wc\" command ...\n");
               			 execlp(argv[2],argv[2],(char *) 0);
		
			}
			else
				{
					printf("excuting \"ls\" command ...\n");
             				   close(pfd[0]);
             				   dup2(pfd[1],1);
					   close(pfd[1]);
					   execlp(argv[1],argv[1],(char *)0);
			}

		exit(1);
        }
}

