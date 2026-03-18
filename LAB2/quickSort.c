#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(1) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}


void quickSort(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main(){

    /*int n;

    printf("enter the number of elementrs to be inserted into the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }


    printf("elements before sorted:\n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
    quickSort(arr,0,n-1);
    printf("elements after sorted:\n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }*/
    int n;

    for(n=10000; n<=100000; n+=10000){

        int arr[n];

        srand(time(NULL));

        for(int i=0;i<n;i++){
            arr[i] = rand()%10000;
        }

        clock_t start,end;

        start = clock();

        quickSort(arr,0,n-1);

        end = clock();

        double time_taken = (double)(end-start)/CLOCKS_PER_SEC;

        printf("%d \n%f\n", n, time_taken);
    }
    return 0;
}

