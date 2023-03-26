#include <stdio.h>
#include <stdlib.h>

// 21.Write a Program for merge two Linked List using C language. 


// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to merge two linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* current = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            if (mergedList == NULL) {
                mergedList = list1;
                current = list1;
            } else {
                current->next = list1;
                current = current->next;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = list2;
                current = list2;
            } else {
                current->next = list2;
                current = current->next;
            }
            list2 = list2->next;
        }
    }
    if (list1 != NULL) {
        if (mergedList == NULL) {
            mergedList = list1;
        } else {
            current->next = list1;
        }
    }
    if (list2 != NULL) {
        if (mergedList == NULL) {
            mergedList = list2;
        } else {
            current->next = list2;
        }
    }
    return mergedList;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

// Main function
int main() {
    // Create two linked lists
    struct Node* list1 = NULL;
    insertNode(&list1, 1);
    insertNode(&list1, 3);
    insertNode(&list1, 5);
    insertNode(&list1, 7);

    struct Node* list2 = NULL;
    insertNode(&list2, 2);
    insertNode(&list2, 4);
    insertNode(&list2, 6);
    insertNode(&list2, 8);

    // Merge the two linked lists
    struct Node* mergedList = mergeLists(list1, list2);

    // Print the merged linked list
    printList(mergedList);

    return 0;
}
