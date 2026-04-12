#include <stdio.h>
#include <math.h>

void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}

int main(){
    int req[]={176,79,34,60,92,11,41};

    int n=7;
    int head=50;
    int size=200;
    int total=0;
    sort(req,n);
    int start =head;
    for(int i=0;i<n;i++){
        if(req[i]>=head){
            total+=abs(req[i]-head);
            head=req[i];
        }
    }

    total+=abs((size-1)-head);
    head=0;


    for(int i=0;i<n;i++){
        if(req[i]<start){
            total+=abs(req[i]-head);
            head=req[i];
        }
    }

    printf("%d",total);
}