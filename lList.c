#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display_list(struct Node* head){
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_at_start(struct Node **head, int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = num;
    newNode->next = *head;
    *head = newNode;
}

void insert_at_end(struct Node **head, int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = num;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void insert_after(struct Node **head, int num, int pos){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = num;

    struct Node* ptr = *head;
    int i = 0; 
    while(i < pos && ptr != NULL){
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL){
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

void delete_node(struct Node **head, int num){
    struct Node* ptr = *head;
    struct Node* prev = NULL;

    while(ptr != NULL && ptr->data != num){
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL){
        printf("Element not found.\n");
        return;
    }

    if (prev == NULL){
        *head = ptr->next;
        free(ptr);
    }
    else{
        prev->next = ptr->next;
        free(ptr);
    }
    printf("Element deleted.\n");
}

int main(void){
    int choice, num, pos;
    struct Node* head = NULL;
    printf("Test linked list operations: \n");
    printf("1. Insert node at beginning\n");
    printf("2. Insert node at end\n");
    printf("3. Delete a node\n");
    printf("4. Insert node after a set position\n");
    printf("5. Display the list\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    while (choice != 6){
        switch(choice){
            case 1: 
                printf("Enter the number to insert at the beginnning of the list: ");
                scanf("%d", &num);
                insert_at_start(&head, num);
                break;
            case 2:
                printf("Enter the number to insert at the end: ");
                scanf("%d", &num);
                insert_at_end(&head, num);
                break;
            case 3:
                printf("Enter the number to delete: ");
                scanf("%d", &num);
                delete_node(&head, num);
                break;
            case 4: 
                printf("Enter number to insert: ");
                scanf("%d", &num);
                printf("Enter position to insert number at: ");
                scanf("%d", &pos);  
                insert_after(&head, num, pos);
                break;
            case 5: 
                display_list(head);
                break;
            case 6: 
                printf("Exiting now.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}