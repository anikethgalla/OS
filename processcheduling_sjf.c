#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(){
    int n=3;
    int at[]={0,1,2};
    int bt[]={5,3,1};

    int rem[3];
    int min;
    int shortest;
    int time=0;
    int finish_time=0;
    int complete=0;

    for(int i=0;i<n;i++){
        rem[i]=bt[i];
    }

    while(complete!=n){
        min=INT_MAX;
        shortest=-1;
        for(int i=0;i<n;i++){
            if(at[i]<=time && rem[i]>0 && rem[i]<min){
                min=rem[i];
                shortest=i;
            }
        }

        if(shortest==-1){
            time++;
            continue;
        }

        rem[shortest]--;
        time++;

        if(rem[shortest]==0){
            complete++;
            finish_time=time;
            printf("Process %d is completed at time %d\n",shortest+1,finish_time);
        }
    }

}