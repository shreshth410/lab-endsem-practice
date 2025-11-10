#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int DEQueue[SIZE];
int front = -1, rear = -1;

// Check if the DEQueue is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Check if the DEQueue is empty
int isEmpty() {
    return (front == -1);
}

// Insert element at the front
void insertFront(int val) {
    if (isFull()) {
        printf("Queue full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        printf("Cannot insert at front\n");
        return;
    } else {
        front--;
    }
    DEQueue[front] = val;
    printf("Inserted %d @ the front of queue\n", val);
}

// Insert element at the rear
void insertRear(int val) {
    if (isFull()) {
        printf("Queue full\n");
        return;
    }
    if (rear == -1) {
        rear = front = 0;
    } else if (rear == SIZE - 1) {
        printf("Cannot insert at rear\n");
        return;
    } else {
        rear++;
    }
    DEQueue[rear] = val;
    printf("Inserted %d @ the rear of queue\n", val);
}

// Delete the front element
int deleteFront() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return -1;
    }
    int val = DEQueue[front];
    printf("Deleted %d from front of queue\n", val);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return val;
}

// Delete element from the rear
int deleteRear() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return -1;
    }
    int val = DEQueue[rear];
    printf("Deleted %d from rear of queue\n", val);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
    return val;
}

// Peek the front value
int peekFront() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return -1;
    }
    return DEQueue[front];
}

// Peek the rear value
int peekRear() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return -1;
    }
    return DEQueue[rear];
}

// Display all elements in the DEQueue
void display() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d\t", DEQueue[i]);
    }
    printf("\n");
}

int main() {
    // Demonstration of DEQueue operations
    insertFront(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);

    display();

    deleteFront();
    deleteRear();

    display();

    insertFront(1);
    insertRear(40);

    display();

    printf("Front value: %d\n", peekFront());
    printf("Rear value: %d\n", peekRear());

    return 0;
}
