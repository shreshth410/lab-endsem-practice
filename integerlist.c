#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int digit;
    struct Node* prev;
    struct Node* next;
};

void createList(struct Node** head, struct Node** tail, int n){
    if (*head == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->digit = n;
        newNode->prev = NULL;
        newNode->next = NULL;

        *head = newNode;
        *tail = newNode;
    }
    else if (*head == *tail){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->digit = n;
        newNode->prev = *head;
        newNode->next = *head;
        
        (*head)->prev = newNode;
        (*head)->next = newNode;

        (*tail) = newNode;
    }
    else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->digit = n;
        newNode->prev = *tail;
        newNode->next = *head;

        (*tail)->next = newNode;
        (*head)->prev = newNode;

        (*tail) = newNode;
    }
}

void printOdd(struct Node** head, struct Node** tail){
    struct Node* temp = *head;

    if (temp == NULL)return;

    else if (temp == *tail){
        if (temp->digit % 2 == 1){
            printf("%d\t", temp->digit);
        }
    }
    else {
        do {
            if (temp->digit % 2 == 1){
                printf("%d\t", temp->digit);
            }
            temp = temp->next;
        }while (temp != *head);
    }
}

int main(void){
    struct Node* head = NULL;
    struct Node* tail = NULL;

    char number[100];

    printf("Enter an integer: ");
    fgets(number, sizeof(number), stdin);

    for (int i = 0; i < strlen(number); i++){
        createList(&head, &tail, (int)(number[i]-'0'));
    }

    printOdd(&head, &tail);
}