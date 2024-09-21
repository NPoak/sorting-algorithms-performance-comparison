#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void swap (int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[],int n)
{
    for(int i =0 ; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}

double getElapsedTime(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec)*1e9 + (end.tv_nsec - start.tv_nsec)  ;
}


int main(void) {
    int numberOfTestcases = 1; // Change this to the number of test cases you have
    double totalTime = 0;
    int num = 100000;
    //printf("");

    for (int i = 1; i <= numberOfTestcases; i++) {
        char filename[100];
        sprintf(filename, "dataset/worst/Adata-n%d.txt", num); // Adjust the folder and file naming structure as needed

        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening the file %s\n", filename);
            return 1;
        }

        int n;
        fscanf(file, "%d", &n);

        int arr[n];
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &arr[j]);
        }

        fclose(file);

        struct timespec start_time, end_time;
        double total_time;

        //printf("Test Case %d - SELECTION: ", i);
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        selectionSort(arr, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        total_time = getElapsedTime(start_time, end_time);

        //printArr(arr, n);
        //printf("Time taken: %.0lf nanoseconds\n", total_time);
        //printf("---------------------------------------------------------\n");

        totalTime += total_time;
    }

    double avgTime = totalTime / numberOfTestcases;
    printf("---------------------------------------------------------\n");
    printf("Average Time for %d test cases: %.2lf microseconds\n", numberOfTestcases, avgTime/1000);
printf("---------------------------------------------------------\n");
    return 0;
}
