#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<pthread.h>
#include<time.h>
#include "sharedll.h"

#define NUMOF_LL 5
#define MAX_THREADS 4

int main()
{
    pthread_t t[MAX_THREADS];
    pthread_attr_t attr;
    
    int status,i;
    // Initialising heads to all LLs
        int j=I_LL(NUMOF_LL);
        
        
    pthread_attr_init(&attr);

    // Do mutex_init for all mutexes
    for(i=0;i<NUMOF_LL;i++)
        pthread_mutex_init(&mutexes[i],NULL);
    
    
    printf("\nThe operation is going to run %d times\n",MAX_THREADS);
    
    for(i=0;i<MAX_THREADS;i++)
    {
        struct params* data;
        /* Allocate a structure for passing it to the thread */
        data=(struct params*)malloc(sizeof(struct params));

        int ll_num,op_num,value; // LL number and operation code
        
        printf("\nSelect a linked list for use. (starting from 0)?\n");
        scanf("%d",&ll_num);
        
        printf("\nEnter an option: \n");
        printf("1.Insert Node\n");
        printf("2.Delete Node\n");
        printf("3.Search for Node\n");
        
        scanf("%d",&op_num);
        
        printf("\nEnter value: \n");
        scanf("%d",&value);
        
        data->LL_num=ll_num;
        data->val=value;
        
        if(op_num==1){
            status=pthread_create(&t[i],&attr,I_Node,data);
        } else if(op_num==2) {
            status=pthread_create(&t[i],&attr,D_Node,data);
        } else{
            status=pthread_create(&t[i],&attr,D_Node,data);
        }
        if(status!=0){
            fprintf(stderr, "pthread_create() failed: %s.\n", status == EAGAIN?"Insufficient resources to create another thread OR A  system-imposed  limit on the number of threads was encountered.":status == EINVAL?"Invalid settings in attr.":status == EPERM?"No permission to set the scheduling policy and parameters specified in attr.":"Unknown Error");
            exit(1);
        }
    }

    // Joining all threads
    for(i=0;i<MAX_THREADS;i++){
        status=pthread_join(t[i],NULL);
        if(status != 0) {
            fprintf(stderr, "pthread_join() failed: %s.\n", status == EDEADLK?"A deadlock was detected (e.g., two threads tried to join with each other); or thread specifies the calling thread.":status == EINVAL?"thread is not a joinable thread OR Another thread is already waiting to join with this thread.":status == ESRCH?"No thread with the ID thread could be found.":"Unknown Error");
            exit(1);
        }
    }

    // Destroy all mutexes
    for(i=0;i<NUMOF_LL;i++)
        pthread_mutex_destroy(&mutexes[i]);

    // Final printing
    P_all_LL();
    
    P_i_ll(1);

    // Final Exit
    pthread_exit(0);
    return 0;
}

