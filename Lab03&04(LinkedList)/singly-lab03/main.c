#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insAtBeg(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void insAtEnd(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insAtkth(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    int k;
    printf("Enter the position: ");
    scanf("%d", &k);
    
    if(k == 1){
        newNode->next = head;
        head = newNode;
    }
    else{
        struct Node* temp = head;
        for(int i = 1; i < k - 1; i++){
            if(temp == NULL){
                printf("Invalid position\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delAtBeg(){
    if(head == NULL){
        printf("Void deletion\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void delAtEnd(){
    if(head == NULL){
        printf("Void deletion\n");
        return;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delAtKth(){
    if(head == NULL){
        printf("Void deletion\n");
        return;
    }
    int k;
    printf("Enter the position: ");
    scanf("%d", &k);
    
    if(k == 1){
        delAtBeg();
    }
    else{
        struct Node* temp = head;
        struct Node* prev = NULL;
        for(int i = 1; i < k; i++){
            prev = temp;
            temp = temp->next;
            if(temp == NULL){
                printf("Invalid position\n");
                return;
            }
        }
        prev->next = temp->next;
        free(temp);
    }
}

void display(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("Enter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at kth position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at kth position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                insAtBeg();
                break;
            case 2:
                insAtEnd();
                break;
            case 3:
                insAtkth();
                break;
            case 4:
                delAtBeg();
                break;
            case 5:
                delAtEnd();
                break;
            case 6:
                delAtKth();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}