#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insAtBeg(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else{
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
}
void insAtEnd(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if(head == NULL){//empty list
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
        
    }
}

void insAtkth(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    int k;
    printf("Enter the position: ");
    scanf("%d", &k);
    if(k ==1){
        
        if(head == NULL){
            head = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }   
        else{
            newNode->next = head;
            newNode->prev = NULL;
            head->prev = newNode;
            head = newNode;
        }
    }
    else{
        struct Node* temp = head;
        for(int i = 1; i < k-1; i++){
            temp = temp->next;
            if(temp == NULL){
                printf("Invalid position\n");
                return;
            }
        }
        if(temp->next == NULL){
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
        }
        else{
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        
    }
}

void delAtBeg(){
    if(head==NULL){
        printf("Void deletion");
        exit(0);
    }
    struct Node* ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
}
void delAtEnd(){
    if(head==NULL){
        printf("Void deletion");
        exit(0);
    }

    struct Node* temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free (temp);
}
void delAtKth(){
    if(head == NULL){
        printf("Void deletion");
        exit(0);
    }
    int k;
    printf("Enter the position:");
    scanf("%d",&k);
    if(k==1){//deletion at beginning
        delAtBeg();
    }
    else{
        struct Node* ptr = head;
        for(int i=1;i<k;i++){
            ptr = ptr->next;
            if(ptr==NULL){
                printf("Invalid position");
                return;
            }
        }
        if(ptr->next ==NULL){
            delAtEnd();
        }
        else{
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
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
