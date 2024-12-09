#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

bool isEmp(){
    if(front ==-1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if(front==MAX-1){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int num) {
    if (!isFull()) {
        if (isEmp()) { // If the queue is initially empty
            front = 0;
        }
        rear++;
        queue[rear] = num;
        printf("Enqueued %d successfully!\n", num);
    } else {
        printf("Couldn't insert, queue is full!\n");
    }
}

int dequeue() {
    int num;
    if (!isEmp()) {
        num = queue[front];
        if (front == rear) { 
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        printf("Dequeued %d successfully!\n", num);
        return num;
    } else {
        printf("Couldn't dequeue, queue is empty!\n");
        return -1;
    }
}

int main() {
    int choice, num;
    while (1) { // Infinite loop, exit when choice is 0
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to be enqueued: ");
                scanf("%d", &num);
                enqueue(num);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                if (isEmp()) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue elements are:\n");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;

            case 0:
                printf("Exiting the program.\n");
                return 0; // Exit the program

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}


