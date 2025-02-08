#include<stdio.h>

int toh(int n, char A, char B, char C){
    if(n>0){
        int moves=0;
        moves+=toh(n-1, A,C,B);
        printf("Moved from %c to %c\n", A,C);
        moves++;
        moves+=toh(n-1,B,A,C);
        return moves;
    }
    else{
        return 0;
    }
}

int main(){
    int n = 3;
    int moves = toh(n,'A','B','C');
    printf("%d",moves);
    return 0;
}

