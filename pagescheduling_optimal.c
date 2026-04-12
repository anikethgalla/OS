#include <stdio.h>

int main(){
    int pages[] = {7,0,1,2,0,3,0,4};
    int frames[3] = {-1,-1,-1};
    int n = 8, faults = 0;
    int hit;
    int pos;
    for(int i=0;i<n;i++){
        hit=0;
        for(int j=0;j<3;j++){
            if(frames[j]==pages[i]){
                hit=1;
            }
        }

        if(!hit){
            pos=0;
            int far=i;
            for(int j=0;j<3;j++){
                int k;
                for(int k=i+1;k<n;k++){
                    if(frames[j]==pages[k]) break;

                    if(k==n){pos=j;break;}
                    if(k>far){pos=j;far=k;}
                }
            }
        frames[pos]=pages[i];
        faults++;
        }
    }
    printf("Faults: %d\n",faults);
}