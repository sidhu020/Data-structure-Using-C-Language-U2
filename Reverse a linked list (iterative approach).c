#include <stdio.h>
#include <stdlib.h>


//23.Program for Reverse a linked list (iterative approach) 

// Structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertNode(struct Node** head_ref, int data) {
    // Create a new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    // Update the head pointer
    (*head_ref) = new_node;
}

// Function to reverse the linked list using iterative approach
void reverseList(struct Node** head_ref) {
    struct Node* current = (*head_ref);
    struct Node* previous = NULL;
    struct Node* next_node = NULL;
    while (current != NULL) {
        // Store the next node
        next_node = current->next;
        // Reverse the link
        current->next = previous;
        // Move the pointers ahead
        previous = current;
        current = next_node;
    }
    // Update the head pointer
    (*head_ref) = previous;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function to test the program
int main() {
    struct Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    printf("Original linked list: ");
    printList(head);
    reverseList(&head);
    printf("\nReversed linked list: ");
    printList(head);
    return 0;
}
