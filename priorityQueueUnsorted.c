#include <stdio.h>
#include <limits.h> // For INT_MIN

#define MAX 100

int priorityQueue[MAX];
int size = 0; // Tracks the current number of elements

int isEmpty() {
    return size == 0;
}

int isFull() {
    return size == MAX;
}

void insert(int element) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", element);
        return;
    }
    
    // Add the new element to the end of the array
    priorityQueue[size] = element;
    size++;
    printf("Inserted: %d\n", element);
}

int peekMax() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return INT_MIN; // Error value
    }

    int maxVal = priorityQueue[0];
    int maxIndex = 0;
    
    // Find the maximum value
    for (int i = 1; i < size; i++) {
        if (priorityQueue[i] > maxVal) {
            maxVal = priorityQueue[i];
            maxIndex = i;
        }
    }
    return maxVal;
}

int deleteMax() {
    if (isEmpty()) {
        printf("Queue is empty! (Underflow)\n");
        return INT_MIN; // Error value
    }

    int maxVal = priorityQueue[0];
    int maxIndex = 0;

    // 1. Find the index of the maximum element
    for (int i = 1; i < size; i++) {
        if (priorityQueue[i] > priorityQueue[maxIndex]) {
            maxIndex = i;
        }
    }
    
    maxVal = priorityQueue[maxIndex];

    // 2. Shift all elements after the max element one position to the left
    for (int i = maxIndex; i < size - 1; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    // 3. Decrease the size of the queue
    size--;
    
    return maxVal;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue (unsorted): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", priorityQueue[i]);
    }
    printf("\n");
}

int main(void) {
    insert(10);
    insert(30);
    insert(5);
    insert(20);
    display(); // Output: 10 30 5 20

    printf("Highest Priority (Peek): %d\n", peekMax()); // Output: 30

    printf("Deleted (Max): %d\n", deleteMax()); // Output: 30
    display(); // Output: 10 5 20

    printf("Deleted (Max): %d\n", deleteMax()); // Output: 20
    display(); // Output: 10 5
    
    printf("Deleted (Max): %d\n", deleteMax()); // Output: 10
    display(); // Output: 5
    
    printf("Deleted (Max): %d\n", deleteMax()); // Output: 5
    display(); // Output: Queue is empty!

    return 0;
}
