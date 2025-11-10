#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int pop(struct Node** head){
    struct Node* ptr = *head;
    *head = ptr->next;
    int v = ptr->data;
    free(ptr);
    return v;
}

int peek(struct Node* head){
    return head->data;
}

int isEmpty(struct Node* head){
    return head == NULL;
}

struct Node* push(struct Node* head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    return head;
}

int main(void){
    struct Node* head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);

    printf("Popped: %d\n", pop(&head));

    printf("Top element: %d\n", peek(head));
}