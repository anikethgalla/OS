#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
sem_t mutex;
sem_t S[N];

int state[N];
int LEFT(int i){return (i+N-1)%N;}
int RIGHT(int i){return (i+1)%N;}

void test(int i){
    if(state[i]==HUNGRY && state[LEFT(i)]!=EATING && RIGHT(i)!=EATING){
        state[i]=EATING;

        sem_post(&S[i]);
    }
}

void take_forks(int i){
    sem_wait(&mutex);
    state[i]=HUNGRY;

    printf("Philosopher %d is Hungry\n",i);

    test(i);
    sem_post(&mutex);

    sem_wait(&S[i]);
}

void put_forks(int i){
    sem_wait(&mutex);

    state[i]=THINKING;
    printf("Philosopher %d is thinking\n",i);

    test(LEFT(i));
    test(RIGHT(i));

    sem_post(&mutex);
}

void* philosopher(void*arg){
    int i=*(int*)arg;
    while(1){
        printf("Philosopher %d is Thinking\n",i);
        sleep(1);

        take_forks(i);

        printf("Philosopher %d is Eating\n",i);
        sleep(1);

        put_forks(i);
    }
}

int main(){
    pthread_t thread[N];
    int id[N];


    sem_init(&mutex,0,1);

    for(int i=0;i<N;i++){
        sem_init(&S[i],0,0);
    }

    for(int i=0;i<N;i++){
        id[i]=i;
        pthread_create(&thread[i],NULL,philosopher,&id[i]);
    }

    for(int i=0;i<N;i++){
        pthread_join(thread[i],NULL);
    }
}
