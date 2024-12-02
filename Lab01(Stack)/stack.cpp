#include<iostream>
int MAXSIZE = 10;
int stack[10];
int top = -1;


int isEmpty(){
    if(top ==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top ==MAXSIZE){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int num){
    if(!isFull()){
        top +=1;
        stack[top] = num;
    }
    else{
        std::cout<<"Couldnt insert, check if the stack is full!\n";
    }
}
int pop(){
    int num;
    if(!isEmpty()){
        num = stack[top];
        top = top -1;
        return num;
    }

    else{
        std::cout<<"Couldnt retrive, maybe the stack is empty";
        return -1;
    }
}


int main(){
    int choice=0;
    switch (choice)
    {
    case 0:
        
        break;
    
    default:
        break;
    }
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);

    //printing all of the stack elements
    for (int i=0;i<MAXSIZE; i++){
        std::cout<<stack[i]<<std::endl;
    }

    //pop
    std::cout<<"Now poping data:\n";
    while(!isEmpty()){
        int data = pop();
        std::cout<<"poped element:"<<data<<std::endl;
    }
    return 0;

}