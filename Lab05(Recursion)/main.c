
#include<stdio.h>
#include<stdlib.h>

int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}


int fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1||n==2){
        return 1;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}


int toh(int n, char A, char B, char C){
    if(n>0){
        toh(n-1,A,C,B);
        printf("Disk moved from %c to % c\n", A, C);
        toh(n-1, B, A, C);
    }
    else{
        return 0;
    }
}


int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));
    printf("Fibonacci of %d is %d\n", n, fibo(n));

    printf("Enter the number of disks: ");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}