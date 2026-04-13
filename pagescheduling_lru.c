#include <stdio.h>

int main(){
    int pages[] = {7,0,1,2,0,3,0,4};
    int frames[3] = {-1,-1,-1};
    int n = 8, faults = 0;

    // To track last used time
    int time[3] = {0,0,0};
    int counter = 0;

    for(int i=0;i<n;i++){
        int hit = 0;

        printf("Page %d -> ", pages[i]);
        counter++;

        // Check hit
        for(int j=0;j<3;j++){
            if(frames[j] == pages[i]){
                hit = 1;
                time[j] = counter;  // update recent use
                break;
            }
        }

        if(!hit){
            int pos = 0;

            // Find least recently used
            for(int j=1;j<3;j++){
                if(time[j] < time[pos]){
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            time[pos] = counter;
            faults++;

            printf("Fault ");
        }
        else{
            printf("Hit   ");
        }

        // Print frames
        for(int j=0;j<3;j++){
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);

    return 0;
}