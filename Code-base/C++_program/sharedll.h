
#define NUMOF_LL 5

struct Node {

	int data;
	struct Node *next;
};

struct Node* head[NUMOF_LL]; // head pointers to each linked list
         pthread_mutex_t mutexes[NUMOF_LL]; // One mutex for each Linked List 

// Structure used to pass values to threads
struct params{
    int LL_num; // Number(0-based index) of Linked List to work on
    int val; // Value to be searched/deleted/inserted
};

int I_LL(int numof_ll)
{        
         
       
         for(int i=0;i<NUMOF_LL;i++)
         {
                 head[i]=NULL;
         }
         
      return 1;   
}

void *I_Node(void* args){

    struct params* data; // Structure with our data
    data=(struct params*)args;
    
    int ll_n=data->LL_num;
    int val=data->val;
    
    struct Node* t=head[ll_n]; // head of linked list #ll_n
    
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    struct Node* prev;
   
    n->data=val;
    n->next=NULL; 
    
    pthread_mutex_lock(&mutexes[ll_n]);
    
    if(t==NULL){ //in case first element of the linklist.
        head[ll_n]=n;
    } else{
        while(t->next!=NULL){
            
            prev=t;
            t=t->next;
            
        }
        prev->next=n;
    }
    
    printf("\nInserted %d\n",val);
    
    pthread_mutex_unlock(&mutexes[ll_n]);
    
    /* Free the data malloced in the main thread */
    
    free(args);
    
    /* Exit the thread */
    pthread_exit(0);
    
}

void *D_Node(void* args)
{
    struct params* data; // Structure with our data
    
    data=(struct params*)args;
    
    int ll_n=data->LL_num;
    int val=data->val;
    
    struct Node* t=head[ll_n]; // head of linked list #ll_n
    
    if(t==NULL){
        printf("\nNot found!!\n");
    }
    
    pthread_mutex_lock(&mutexes[ll_n]);
    
    if(t->next==NULL){
        if(t->data==val){
            free(t);
            head[ll_n]=NULL;
            printf("\nDeleted %d\n",val);
        } else{
            printf("\nNot Found!!\n");
        }
    } else{
        int flag=0;
        while(t->next!=NULL){
            if(t->next->data==val){
                flag=1;
                struct Node* temp=t->next;
                t->next=t->next->next;
                free(temp);
                printf("\nDeleted %d\n",val);
                break;
            }
            t=t->next;
        }
        if(flag==0){
            printf("\nNot Found!!\n");
        }
    }
    
    pthread_mutex_unlock(&mutexes[ll_n]);
    /* Free the data malloced in the main thread */
    free(args);
    /* Exit the thread */
    pthread_exit(0);
}

void *S_Node(void* args)
{
    struct params* data; // Structure with our data
    data=(struct params*)args;
    
    int ll_n=data->LL_num; 
    int val=data->val;
     
    struct Node* t=head[ll_n]; // head of linked list #ll_n
    
    int found=0;
    
    pthread_mutex_lock(&mutexes[ll_n]);
    
    while(t!=NULL){
        if(t->data==val){
            //printf("\nFound %d\n",val);
            found=1;
            break;
        }
        t=t->next;
    }
    if(found==0){
        printf("\nNot found....\n");
    }
    pthread_mutex_unlock(&mutexes[ll_n]);
    /* Free the data malloced in the main thread */
    free(args);
    /* Exit the thread */
    pthread_exit(0);
}

// A normal function to print all LLs
void P_all_LL(){
    int i;
    struct Node* t;
    for(i=0;i<NUMOF_LL;i++){
        printf("\nPrinting list %d: \n",i);
        t=head[i];
        while(t!=NULL){
            printf("%d ",t->data);
            t=t->next;
        }
        printf("\n");
    }
}

void P_i_ll(int a) //print only one of the many linklist.
{
        struct Node* pll=head[a];
        
        while(pll!=NULL){
            printf("%d ",pll->data);
            pll=pll->next;
        }
        printf("\n");
}
