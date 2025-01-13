#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Array to simulate the linked list structure
int data[MAX_SIZE];       // Array to store data of the nodes
int next[MAX_SIZE];       // Array to store the "next" index of the nodes
int head = -1;            // Points to the first element in the list
int freeIndex = 0;        // Tracks the next free space in the arrays

// Function to initialize the linked list
void init() {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        next[i] = i + 1;
    }
    next[MAX_SIZE - 1] = -1; // End of the free list
}

// Function to create a new node and return its index
int createNode(int value) {
    if (freeIndex == -1) {
        printf("List is full. Cannot create new node.\n");
        return -1;
    }

    int newNodeIndex = freeIndex; // Get the next free node index
    freeIndex = next[freeIndex];  // Move freeIndex to the next available spot

    data[newNodeIndex] = value;   // Set the data of the new node
    next[newNodeIndex] = -1;      // Set the "next" pointer to -1, indicating end of the list

    return newNodeIndex;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int value) {
    int newNode = createNode(value);
    if (newNode == -1) return; // If node creation failed, do nothing

    if (head == -1) { // If the list is empty, make newNode the head
        head = newNode;
    } else {
        int current = head;
        while (next[current] != -1) { // Traverse to the end of the list
            current = next[current];
        }
        next[current] = newNode; // Point the last node to the new node
    }
}

// Function to print the linked list
void printList() {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }

    int current = head;
    while (current != -1) {
        printf("%d -> ", data[current]);
        current = next[current];
    }
    printf("NULL\n");
}

// Function to delete a node from the linked list
void deleteNode(int value) {
    if (head == -1) {
        printf("List is empty. Cannot delete node.\n");
        return;
    }

    int current = head;
    int previous = -1;

    while (current != -1 && data[current] != value) {
        previous = current;
        current = next[current];
    }

    if (current == -1) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (previous == -1) { // Node to be deleted is the head
        head = next[current];
    } else {
        next[previous] = next[current]; // Bypass the current node
    }

    next[current] = freeIndex;  // Return the node to the free list
    freeIndex = current;        // Update the freeIndex
    printf("Node with value %d deleted.\n", value);
}

// Function to display the menu
void displayMenu() {
    printf("\nSingly Linked List Operations:\n");
    printf("1. Insert at the end\n");
    printf("2. Delete a node\n");
    printf("3. Print the list\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Main function to drive the program
int main() {
    int choice, value;

    init(); // Initialize the list structure

    while (1) {
        displayMenu(); // Show the menu
        scanf("%d", &choice); // Get user choice

        switch (choice) {
            case 1: // Insert at the end
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                printf("Value %d inserted.\n", value);
                break;

            case 2: // Delete a node
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 3: // Print the list
                printf("Linked List: ");
                printList();
                break;

            case 4: // Exit
                printf("Exiting program.\n");
                exit(0);

            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
