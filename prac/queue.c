#include<stdio.h>
#define MAX 10
int q[MAX];
int front = -1;
int rear = -1;

int isE(){
    if(front ==-1){
        return 1;
    }
    else{
        return 0;
    }

}


int isF(){
    if(front ==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}


void en(int n){
    if(!isF){
        if(isE()){
            front =0;
        }
        rear++;
        q[rear] = n;
        printf("Enqueued %d successfully!\n", n);
    }
    else
        printf("Couldn't insert, queue is full!\n");
}

void de(){
    if(!isE()){
        if(front==rear){
            front=-1;
            rear=-1;
        }
        int num = q[front];
        front++;
    }
}