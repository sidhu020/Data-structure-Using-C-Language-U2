#include <stdio.h>
#include <stdlib.h>

// 22. Program for Reverse a linked list (tail-recursive approach). 


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

// Function to reverse the linked list using tail-recursive approach
void reverseList(struct Node* current, struct Node* previous, struct Node** head_ref) {
    // If current node is the last node, update the head pointer
    if (current->next == NULL) {
        (*head_ref) = current;
        current->next = previous;
        return;
    }
    // Recursive call with updated arguments
    struct Node* next_node = current->next;
    current->next = previous;
    reverseList(next_node, current, head_ref);
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
    reverseList(head, NULL, &head);
    printf("\nReversed linked list: ");
    printList(head);
    return 0;
}


//*****************************************//

//Original linked list: 4 3 2 1 
//Reversed linked list: 1 2 3 4 
