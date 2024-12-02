#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 10
int stack[MAXSIZE];
int top =-1;

bool isEmpty(){
    if(top ==-1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(){
    if(top ==MAXSIZE){
        return true;
    }
    else{
        return false;
    }

}
void push(int num){
    if(!isFull()){
        top+=1;
        stack[top]=num;
    }
    else{
        printf("Couldnt insert, check if the stack is full!\n");
    }

}
int pop(){
    int num;
    if(!isEmpty()){
        top-=1;
        num= stack[top];
        return num;
    }
    else{
        printf("Couldnt insert, check if the stack is empty!\n");
        return -1;
    }
}

int main(){


    int choice;
    int num;
        printf("What do you want to do?\n");
        printf("1. Push (max limit is 10 datas)\n");
        printf("2. Pop (max limit is 10 datas)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
    while (1)
    {
        printf("What do you want to do?\n");
        scanf("%d",&choice);


        switch (choice)
        {
        case 1:
            printf("Enter the number you want to push: ");
            scanf("%d",&num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            for(int i=0;i<=top;i++){
                printf("%d\n",stack[i]);
            }
            break;
        case 4:
            exit(0);
        
        default:
            break;
        }
    }
    return 0;
}