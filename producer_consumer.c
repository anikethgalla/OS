#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 5
sem_t mutex,full,empty;
int buffer[MAX];
int in=0;
int out=0;
void* producer(void* arg){
    for(int i=0;i<MAX;i++){
        
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in]=i;
        printf("Produced: %d\n",i);
        in=(in+1)%MAX;

        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg){
    for(int i=0;i<MAX;i++){
        sem_wait(&full);
        sem_wait(&mutex);

        int item =buffer[out];
        printf("Consumer: %d\n",item);
        out=(out+1)%MAX;

        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
    }
    return NULL;
}
int main(){
    sem_init(&mutex,0,1);
    sem_init(&empty,0,MAX);
    sem_init(&full,0,0);
    pthread_t p,c;
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);
}