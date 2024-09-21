#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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

    //initial i =1; i<= numberofTestcases;
    for (int i = 1; i <= numberOfTestcases; i++) {
        //char filename[100];
        char filename[100];
        //sprintf(filename, "dataset/n1000/n1000data%d.txt", i);
        //sprintf(filename, "dataset/n100000/n100000data%d.txt", i); // Adjust the folder and file naming structure as needed
	sprintf(filename, "dataset/worst/Ddata-n%d.txt", num);

        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening the file %s\n", filename);
            return 1;
        }

        int n;
        fscanf(file, "%d", &n);

        int arr[n];
        //int *arr = calloc(n,sizeof(n));
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &arr[j]);
        }

        fclose(file);

        struct timespec start_time, end_time;
        double total_time;

        //printf("Test Case %d - INSERTION: ", i);
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        insertionSort(arr, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        total_time = getElapsedTime(start_time, end_time);

        //printArr(arr, n);
        //printf("Time taken: %.0lf nanoseconds\n", total_time);
        //printf("---------------------------------------------------------\n");

        totalTime += total_time;
        //free(arr);
    }
    //initial avgTime = totalTime / numberOfTestcases;
    double avgTime = totalTime / numberOfTestcases;
    printf("---------------------------------------------------------\n");
    printf("Average Time for %d test cases: %.2lf microseconds\n", numberOfTestcases, avgTime/1000);
printf("---------------------------------------------------------\n");
    return 0;
}
