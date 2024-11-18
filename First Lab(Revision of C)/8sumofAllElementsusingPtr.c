#include<stdio.h>

void sumofAll(int *arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum= sum + *(arr+i);
    }
}

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    sumofAll(arr,10);
    return 0;
}