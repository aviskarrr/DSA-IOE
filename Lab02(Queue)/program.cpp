#include<iostream>
#define MAXSIZE 10
using namespace std;
int queue[MAXSIZE];
int front = -1;
int rear = -1;

int isFull(){
    if(front == MAXSIZE - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(front == -1){
        return 1;
    }
    else{
        return 0;
    }
}


void enqueue(int num){
    if(!isFull()){
        front += 1;
        queue[front] = num;
        cout << "Enqueued " << num << " successfully!" << endl;
    }
    else{
        cout << "Couldn't insert, queue is full!" << endl;
    }
}


int dequeue(){///how dequeue works? >> it removes the first element of the queue
//and shifts all the elements to the left
//so that the second element becomes the first element
//and the third element becomes the second element and so on
//and the last element is removed
//and the front is decremented by 1
//and the last element is returned
//if the queue is empty, it returns -1
//if the queue is not empty, it returns the last element
//and the front is decremented by 1
//and the last element is removed
    int num;
    if(!isEmpty()){
        num = queue[0];
        for(int i = 0; i < front; i++){
            queue[i] = queue[i+1];
        }
        front -= 1;
        cout << "Dequeued " << num << endl;
        return num;
    }
    else{
        cout << "Couldn't dequeue, queue is empty!" << endl;
        return -1;
    }
}
int main(){
    int choice, num;
    
    while (1)
    {
        cout << "\nQueue Operations Menu:" << endl;
        cout << "1. Enqueue (max limit is 10 datas)" << endl;
        cout << "2. Dequeue (max limit is 10 datas)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number you want to enqueue: ";
            cin >> num;
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
            } else {
                cout << "Queue contents:" << endl;
                for(int i = 0; i <= front; i++){
                    cout << queue[i] << " ";
                }
                cout << endl;
            }
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;

}