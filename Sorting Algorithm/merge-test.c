#include<stdio.h>
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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
        //sprintf(filename, "dataset/n75000/n75000data%d.txt", i); // Adjust the folder and file naming structure as needed
	sprintf(filename, "dataset/worst/Ddata-n%d.txt", num);
	
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

        //printf("Test Case %d - MERGE: ", i);
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        mergeSort(arr,0, n);
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
