#include <stdio.h>
#include <math.h>

void sort(int arr[], int n){
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

    int start = head;

    // service right side
    for(int i=0;i<n;i++){
        if(req[i]>=start){
            total += abs(req[i]-head);
            head = req[i];
        }
    }

    // go to end
    total += abs((size-1)-head);
    head = size-1;

    // jump to start (circular)
    total += (size-1);   // IMPORTANT
    head = 0;

    // service left side
    for(int i=0;i<n;i++){
        if(req[i] < start){
            total += abs(req[i]-head);
            head = req[i];
        }
    }

    printf("Total Seek Time: %d\n", total);
}