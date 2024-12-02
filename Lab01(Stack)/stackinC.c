#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 10
int stack[MAXSIZE];
int top = -1;

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if(top == MAXSIZE - 1){  // Corrected condition
        return true;
    }
    else{
        return false;
    }
}

void push(int num){
    if(!isFull()){
        top += 1;
        stack[top] = num;
        printf("Pushed %d successfully!\n", num);
    }
    else{
        printf("Couldn't insert, stack is full!\n");
    }
}

int pop(){
    int num;
    if(!isEmpty()){
        num = stack[top];  // Get the top item BEFORE decrementing
        top -= 1;
        printf("Popped %d\n", num);
        return num;
    }
    else{
        printf("Couldn't pop, stack is empty!\n");
        return -1;
    }
}

int main(){
    int choice, num;
    
    while (1)
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push (max limit is 10 datas)\n");
        printf("2. Pop (max limit is 10 datas)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number you want to push: ");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty()) {
                printf("Stack is empty!\n");
            } else {
                printf("Stack contents:\n");
                for(int i = 0; i <= top; i++){
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
            break;
        case 4:
            exit(0);
        
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}