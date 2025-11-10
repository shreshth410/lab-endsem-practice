#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end (for testing)
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list (for testing)
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse a segment of the linked list
Node* reverseSegment(Node* head, int k) {
    if (head == NULL || k <= 1) return head;
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;
    
    // Reverse k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // Connect the reversed segment to the remaining list
    head->next = curr;
    
    return prev;
}

// Main function to process logs
Node* processLogs(Node* head, int M, int N, int K) {
    if (head == NULL) return NULL;
    
    Node* current = head;
    Node* prev = NULL;
    
    // Operation 1: Skip the first M log entries
    int count = 0;
    while (current != NULL && count < M) {
        // Check for special node
        if (current->data == 9999) {
            return head;
        }
        prev = current;
        current = current->next;
        count++;
    }
    
    // If we reached the end during skipping M nodes
    if (current == NULL) {
        return head;
    }
    
    // Operation 2: Delete the next N log entries
    count = 0;
    Node* temp;
    while (current != NULL && count < N) {
        // Check for special node
        if (current->data == 9999) {
            return head;
        }
        
        temp = current;
        current = current->next;
        free(temp);
        count++;
    }
    
    // Connect the previous node to the current node after deletion
    if (prev != NULL) {
        prev->next = current;
    } else {
        // If we deleted from the beginning, update head
        head = current;
    }
    
    // If we reached the end during deletion
    if (current == NULL) {
        return head;
    }
    
    // Operation 3: Reverse the next K log entries
    // First, check if we have at least K nodes to reverse
    Node* check = current;
    int available = 0;
    while (check != NULL && available < K) {
        // Check for special node
        if (check->data == 9999) {
            return head;
        }
        check = check->next;
        available++;
    }
    
    // If we have enough nodes, reverse the segment
    if (available >= K) {
        Node* reversedHead = reverseSegment(current, K);
        
        // Connect the reversed segment to the previous part
        if (prev != NULL) {
            prev->next = reversedHead;
        } else {
            head = reversedHead;
        }
    }
    
    return head;
}

// Test function
int main() {
    /*Node* head = NULL;
    
    // Create a sample log list
    int logs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(logs) / sizeof(logs[0]);
    
    for (int i = 0; i < size; i++) {
        insertEnd(&head, logs[i]);
    }
    
    printf("Original log entries: ");
    printList(head);
    
    int M = 2, N = 3, K = 4;
    head = processLogs(head, M, N, K);
    
    printf("After processing (M=%d, N=%d, K=%d): ", M, N, K);
    printList(head);
    
    // Test with special node
    printf("\nTesting with special node (9999):\n");
    
    Node* head2 = NULL;
    int logs2[] = {1, 2, 3, 9999, 5, 6, 7, 8};
    int size2 = sizeof(logs2) / sizeof(logs2[0]);
    
    for (int i = 0; i < size2; i++) {
        insertEnd(&head2, logs2[i]);
    }
    
    printf("Original with special node: ");
    printList(head2);
    
    head2 = processLogs(head2, 1, 2, 3);
    printf("After processing (stopped at 9999): ");
    printList(head2);
    
    // Free memory (optional cleanup)
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    while (head2 != NULL) {
        Node* temp = head2;
        head2 = head2->next;
        free(temp);
    }
    
    return 0;*/
    printf("Hello world!\n");
}