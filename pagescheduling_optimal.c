#include <stdio.h>

int main(){
    int pages[] = {7,0,1,2,0,3,0,4};
    int frames[3] = {-1,-1,-1};
    int n = 8, faults = 0;

    for(int i=0;i<n;i++){
        int hit = 0;

        printf("Page %d -> ", pages[i]);

        // Check hit
        for(int j=0;j<3;j++){
            if(frames[j] == pages[i]){
                hit = 1;
                break;
            }
        }

        if(!hit){
            int pos = -1;
            int farthest = i;

            // Find optimal replacement
            for(int j=0;j<3;j++){
                int k;
                for(int k = i+1; k<n; k++){
                    if(frames[j] == pages[k])
                        break;
                }

                // If page not found in future
                if(k == n){
                    pos = j;
                    break;
                }

                // Find farthest use
                if(k > farthest){
                    farthest = k;
                    pos = j;
                }
            }

            frames[pos] = pages[i];
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