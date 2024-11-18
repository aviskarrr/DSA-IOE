#include<stdio.h>

int chkPrime(int n){
    int count=0;
    int i;
    for(i=2;i<n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==0){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int pn;
    printf("Enter a number: ");
    scanf("%d",&pn);
    if(chkPrime(pn)==1){
        printf("prime number\n");
    }
    else{
        printf("not a prime number\n");
    }

}