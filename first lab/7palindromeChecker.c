#include<stdio.h>
int main(){
    int n; int rev = 0; int temp;
    printf("Enter the number: ");
    scanf("%d", &n);
    temp = n;
    while(n != 0){
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    if(temp == rev){
        printf("palindrome\n");
    }else{
        printf("not palindrome\n");
    }
    return 0;

}