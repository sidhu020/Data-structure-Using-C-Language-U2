#include <stdio.h>
#include <stdlib.h>


// 20.Write a Menu Driven Program for Circular Linked List. 

struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the list
struct Node* addAtBegin(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Node added at the beginning of the list\n");
    return head;
}

// Function to add a node at the end of the list
struct Node* addAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node added at the end of the list\n");
    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        printf("List: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

// Function to delete a node from the list
struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr->data != key) {
        if (curr->next == head) {
            printf("Node with data %d not found\n", key);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == head && prev == NULL) {
        head = NULL;
        free(curr);
    } else if (curr == head) {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        free(curr);
    } else if (curr->next == head) {
        prev->next = head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
    printf("Node with data %d deleted from the list\n", key);
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, key;
    do {
        printf("1. Add a node at the beginning of the list\n");
        printf("2. Add a node at the end of the list\n");
        printf("3. Display the list\n");
        printf("4. Delete a node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
case 1:
printf("Enter data to be inserted: ");
scanf("%d", &data);
head = addAtBegin(head, data);
break;
case 2:
printf("Enter data to be inserted: ");
scanf("%d", &data);
head = addAtEnd(head, data);
break;
case 3:
displayList(head);
break;
case 4:
printf("Enter data to be deleted: ");
scanf("%d", &key);
head = deleteNode(head, key);
break;
case 5:
printf("Exiting program\n");
break;
default:
printf("Invalid choice\n");
}
} while (choice != 5);
return 0;
}

//****************************************//
//1. Add a node at the beginning of the list
//2. Add a node at the end of the list
//3. Display the list
//4. Delete a node
//5. Exit
//Enter your choice: 
//***************************************//
