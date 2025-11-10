/*#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct Node {
    int val;
    struct Node *next;
}Node;

// Function to sort a linked list using insertion sort
Node* insertionSortList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Create a dummy node to serve as the head of the sorted list
    Node dummy;
    dummy.next = NULL;
    Node* current = head;
    
    while (current != NULL) {
        // Store the next node to process
        Node* next = current->next;
        Node* prev = &dummy;
        Node* sorted_current = dummy.next;
        
        // Find the correct position to insert the current node in the sorted list
        while (sorted_current != NULL && sorted_current->val < current->val) {
            prev = sorted_current;
            sorted_current = sorted_current->next;
        }
        
        // Insert the current node between prev and sorted_current
        current->next = sorted_current;
        prev->next = current;
        
        // Move to the next node in the original list
        current = next;
    }
    
    return dummy.next;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

// Driver code
int main() {
    // Create an unsorted linked list: 4 -> 2 -> 1 -> 3
    Node* head = newNode(4);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(3);
    
    printf("Original list: ");
    printList(head);
    
    head = insertionSortList(head);
    
    printf("Sorted list: ");
    printList(head);
    
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct Node {
    int val;
    struct Node *next;
}Node;

// Recursive function to insert a node into a sorted linked list
Node* sortedInsert(Node* sorted_head, Node* new_node) {
    // Base case: if sorted list is empty or new node should be at the beginning
    if (sorted_head == NULL || sorted_head->val >= new_node->val) {
        new_node->next = sorted_head;
        return new_node;
    }
    
    // Recursive case: insert in the remaining sorted list
    sorted_head->next = sortedInsert(sorted_head->next, new_node);
    return sorted_head;
}

// Recursive function to sort a linked list using insertion sort
Node* insertionSort(Node* head) {
    // Base case: empty list or single node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursively sort the remaining list
    Node* sorted_rest = insertionSort(head->next);
    
    // Insert the current node into the sorted list
    head->next = NULL; // Important: detach the current node
    return sortedInsert(sorted_rest, head);
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->val);
    printList(head->next);
}

// Function to create a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to free the entire linked list recursively
void freeList(Node* head) {
    if (head == NULL) return;
    freeList(head->next);
    free(head);
}

// Driver code
int main() {
    // Create an unsorted linked list: 4 -> 2 -> 1 -> 3
    Node* head = newNode(4);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(3);
    
    printf("Original list: ");
    printList(head);
    
    head = insertionSort(head);
    
    printf("Sorted list: ");
    printList(head);
    
    // Free memory
    freeList(head);
    
    return 0;
}