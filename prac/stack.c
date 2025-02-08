#include<stdio.h>
// #include<stdbool.h>
#include<stdlib.h>

// #include<stdio.h>
#define MAXSIZE 3
// #include<stdbool.h>
int top = -1;
int stack[MAXSIZE];
// #include<stdlib.h>


int isEmpty(){
    if(top ==-1){
        return 1;
    }
    else
        return 0;
}
int isFull(){
    if(top == MAXSIZE-1){
        return 1;
    }
    else
        return 0;
}

void push(int ele){
    if(isFull()){
        printf("Stack is full, cant insert\n");
        // exit(0);
    }
    else{
        top++;
        stack[top]=ele;
    }
}

void pop(){

    if(isEmpty()){
        printf("Stack is empty, cant delete\n");
        return;
    }
    else{
        int temp = stack[top];
        printf("%d was popped",temp);
        top--; 
    }
}

void display(){
    for (int i = top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

int main(){
    push(20);
    push(40);
    push(50);
    // push(60);
    display();
    pop();
    pop();
    pop();
    pop();
    return 0;
}