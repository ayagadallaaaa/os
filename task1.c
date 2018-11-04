#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
int count[128]={0};
pthread_mutex_t lock;
char *line="Ahmed Ahmed Mohamed";
void* search(void *arg){
    int x=(int )arg;
    int i;
    for (i=0;line[i];i++){
        if((int)line[i]==x){
            count[x]++;
        }
    }
   }
int main (){
    int i;
    pthread_t tid[128];
    for (i=32;i<123;i++){
        pthread_create(&tid[i], NULL, &search , (void *)i);  
    }
    
    for(i=32; i<123;i++){
		pthread_join(tid[i],NULL);
    }
    for(i=32; i<123;i++){
    if(count[i] >0)   
    printf("%c %d\n",(char)i,count[i]);        
    }
                    return 0;
}
