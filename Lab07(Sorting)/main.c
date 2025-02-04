#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int left, int right){
    int pivot = arr [right];
    int i = left -1;
    for(int j = left; j<right; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return i+1;
}

void quickSort(int arr[], int left, int right){
    if(left<right){
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr4[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr5[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;

    bubbleSort(arr1, n);
    printf("Bubble Sort: ");
    printArray(arr1, n);

    selectionSort(arr2, n);
    printf("Selection Sort: ");
    printArray(arr2, n);

    insertionSort(arr3, n);
    printf("Insertion Sort: ");
    printArray(arr3, n);

    mergeSort(arr4, 0, n - 1);
    printf("Merge Sort: ");
    printArray(arr4, n);

    quickSort(arr5, 0, n - 1);
    printf("Quick Sort: ");
    printArray(arr5, n);

    return 0;
}
