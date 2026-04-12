#include <stdio.h>
#include <stdlib.h>
int main(){
    int n=3;
    int at[]={};
    int bt[]={5,2,3};
    int rem[3];
    int tq=2;
    int completed=0;
    int time=0;

    for(int i=0;i<n;i++){
        rem[i]=bt[i];
    }
    while(completed<n){
        for(int i=0;i<n;i++){
            if(at[i]<time && rem[i]>0){
                if(rem[i]>tq){
                    rem[i]-=tq;
                    time+=tq;
                }
                else{
                    time+=rem[i];
                    rem[i]=0;
                    printf("Process %d completed at time: %d\n",i+1,time);
                    completed++;
                }
            }
        }
        time++;
    }
}