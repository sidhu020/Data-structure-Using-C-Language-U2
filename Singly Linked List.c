#include <stdio.h>
#include <stdlib.h>


// 18.Write a Menu Driven Program for Singly Linked List. 

// Define the structure for a singly linked list node
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
    printf("Node with data %d inserted at the beginning of the list.\n", data);
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct node* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Node with data %d inserted at the end of the list.\n", data);
}

// Function to delete the first node in the list
void deleteAtBeginning(struct node** headRef) {
    if (*headRef == NULL) {
        printf("The list is already empty.\n");
    } else {
        struct node* current = *headRef;
        *headRef = (*headRef)->next;
        free(current);
        printf("The first node in the list has been deleted.\n");
    }
}

// Function to delete the last node in the list
void deleteAtEnd(struct node** headRef) {
    if (*headRef == NULL) {
        printf("The list is already empty.\n");
    } else if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        printf("The last node in the list has been deleted.\n");
    } else {
        struct node* current = *headRef;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        printf("The last node in the list has been deleted.\n");
    }
}

// Function to print the entire list
void printList(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("The list is:\n");
        struct node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Main function to drive the program
int main() {
    struct node* head = NULL;
    int choice, data;

    do {
        printf("\n");
        printf("1. Insert node at the beginning of the list\n");
        printf("2. Insert node at the end of the list\n");
        printf("3. Delete node at the beginning of the list\n");
        printf("4. Delete node at the end of the list\n");
        printf("5. Print the list\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        insertAtBeginning(&head, data);
                break;
        case 2:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;

        case 3:
            deleteAtBeginning(&head);
            break;

        case 4:
            deleteAtEnd(&head);
            break;

        case 5:
            printList(head);
            break;

        case 6:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
    }
} while (choice != 6);

return 0;
}
