#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* front[MAX];
Node* rear[MAX];

/*
Functions:
1. Enqueue~
2. Dequeue~
3. Peek~
4. Display~
5. isEmpty~
6. Initialise~
*/

void initQueues(){
    for (int i = 0; i < MAX; i++){
        front[i] = NULL;
        rear[i] = NULL; 
    }
}

int isEmpty(int pos){
    return (front[pos] == NULL);
}

void enqueue(int pos, int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    if (front[pos]){
        rear[pos]->next = node;
    }
    else{
        front[pos] = node;
    }

    rear[pos] = node;
    printf("Enqueued %d onto queue %d\n", val, pos);
}

int dequeue(int pos){
    if (isEmpty(pos)){
        printf("Queue empty\n");
        return -1;
    }

    Node* temp = front[pos];
    front[pos] = front[pos]->next;

    int val = temp->data;
    free(temp);

    printf("Dequeued %d from queue %d\n", val, pos);

    return val;
}

Node* peek(int pos){
    if (isEmpty(pos)){
        printf("Queue empty\n");
        return NULL;
    }

    return front[pos];
}

void display(int pos){
    Node* temp = front[pos];

    printf("Queue %d: ", pos);
    while (temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    initQueues(); // Initialize all queues

    // Enqueue some elements into different queues
    enqueue(0, 10);
    enqueue(0, 20);
    enqueue(1, 30);
    enqueue(2, 40);
    enqueue(3, 50);

    // Display all queues
    for (int i = 0; i < MAX; i++) {
        display(i);
    }

    // Dequeue an element from queue 0 and display again
    dequeue(0);

    // Display all queues after dequeue operation
    for (int i = 0; i < MAX; i++) {
        display(i);
    }

    // Enqueue more elements to test
    enqueue(2, 60);
    enqueue(3, 70);

    // Final display
    for (int i = 0; i < MAX; i++) {
        display(i);
    }

    return 0;
}
