#include<stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(&arr[j],&arr[j+1]);
                }
            }
        }
}


void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]); 
    }
}


void InsertionSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int n = 10;
    int arr1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    BubbleSort(arr1, n);
    printf("Bubble Sort: ");
    printArray(arr1, n);

    SelectionSort(arr2, n);
    printf("Selection Sort: ");
    printArray(arr2, n);

    InsertionSort(arr3, n);
    printf("Insertion Sort: ");
    printArray(arr3, n);
}