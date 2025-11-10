#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Fix 1: Change queue to store Node pointers instead of integers
Node* queue_vals[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(Node* val){
    if (rear != MAX_SIZE-1){
        queue_vals[++rear] = val;
        if (front == -1) front = 0;
    }
    else {
        printf("Queue full\n");
    }
}

void dequeue(){ // Fix 2: Corrected spelling from dequeque to dequeue
    if (front == -1 || front > rear){
        printf("Queue empty\n"); // Fix 3: Changed message from "Queue full" to "Queue empty"
        return;
    }
    front++;

    if (front > rear) front = rear = -1;
}

typedef struct Node{
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int val){
    Node* n = (Node*)malloc(sizeof(Node));

    if (!n) return NULL;

    n->data = val;
    n->left = n->right = NULL;

    return n;
}

Node* createTreeRec(){
    int val;
    printf("Enter value of Node (-1 for NULL): ");
    if (scanf("%d", &val) != 1) return NULL;
    if (val == -1) return NULL;

    Node* n = createNode(val);
    if (!n) return NULL;

    int v;
    printf("Left child of %d? (1=Yes 0=No): ", val);
    if (scanf("%d", &v) == 1 && v == 1)
        n->left = createTreeRec();
    else
        n->left = NULL;

        
    printf("Right child of %d? (1=Yes 0=No): ", val);
    if (scanf("%d", &v) == 1 && v == 1)
        n->right = createTreeRec();
    else
        n->right = NULL;

    return n;
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

Node* getFront() {
    if (isQueueEmpty()) {
        return NULL;
    }
    return queue_vals[front]; // Fix 4: This now returns Node* as intended
}

Node* createTreeIter(int elements[], int n) {
    if (n == 0) return NULL;
    
    Node* root = createNode(elements[0]);
    enqueue(root);
    
    int i = 1;
    while (!isQueueEmpty() && i < n) {
        Node* current = getFront();
        dequeue(); // Fix 5: Use corrected function name
        
        // Create left child
        if (i < n && elements[i] != -1) { // Fix 6: Handle -1 as NULL node
            current->left = createNode(elements[i]);
            enqueue(current->left);
        }
        i++;
        
        // Create right child
        if (i < n && elements[i] != -1) { // Fix 6: Handle -1 as NULL node
            current->right = createNode(elements[i]);
            enqueue(current->right);
        }
        i++;
    }
    
    // Reset queue for future use
    front = rear = -1;
    
    return root;
}

void inorder_rec(Node* root){
    if (!root) return;

    inorder_rec(root->left);
    printf("%d\t", root->data);
    inorder_rec(root->right);
}

void preorder_rec(Node* root){
    if (!root) return;
    
    printf("%d\t", root->data);
    preorder_rec(root->left);
    preorder_rec(root->right);
}

void postorder_rec(Node* root){
    if (!root) return;
    
    postorder_rec(root->left);
    postorder_rec(root->right);
    printf("%d\t", root->data);
}

void preorder_iter(Node* root) {
    if (root == NULL) return;

    Node* stack[MAX_SIZE];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

void inorder_iter(Node* root) {
    if (!root) return;

    Node* stack[MAX_SIZE];
    int top = -1;
    Node* current = root;

    while (current != NULL || top > -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

void postorder_iter(Node* root) {
    if (root == NULL)
        return;

    Node* stack1[MAX_SIZE];
    Node* stack2[MAX_SIZE];
    int top1 = -1;
    int top2 = -1;

    // Push root to first stack
    stack1[++top1] = root;

    // Process using first stack, build second stack in reverse order
    while (top1 != -1) {
        Node* current = stack1[top1--];
        stack2[++top2] = current;

        // Push left child first, then right child to stack1
        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }

    // Print elements from stack2 (which are in postorder)
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

void levelorder(Node* root) {
    if (!root) return;

    Node* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->data); // Visit

        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int search(Node* root, int val){
    if (!root) return 0;
    
    if (root->data == val) {
        return 1;
    }
    
    if (search(root->left, val)) return 1;
    return search(root->right, val);
}

Node* copyTree(Node* root){
    if (!root) return NULL;

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = root->data;

    temp->left = copyTree(root->left);
    temp->right = copyTree(root->right);

    return temp;
}

int countNodes(Node* root){
    if (root == NULL) return 0;

    int lsum = countNodes(root->left);
    int rsum = countNodes(root->right);
    return lsum + rsum + 1;
}

// Fix 7: Added menu function for better usability
void menu() {
    printf("\nBinary Tree Operations:\n");
    printf("1. Create Tree (Recursive)\n");
    printf("2. Create Tree (Iterative)\n");
    printf("3. Inorder Traversal (Recursive)\n");
    printf("4. Preorder Traversal (Recursive)\n");
    printf("5. Postorder Traversal (Recursive)\n");
    printf("6. Inorder Traversal (Iterative)\n");
    printf("7. Preorder Traversal (Iterative)\n");
    printf("8. Postorder Traversal (Iterative)\n");
    printf("9. Level Order Traversal\n");
    printf("10. Search Value\n");
    printf("11. Copy Tree\n");
    printf("12. Count Number of nodes\n");
    printf("13. Exit\n");
}

int main(void){
    Node* root = NULL;
    Node* copy = NULL;
    int choice, val, n;
    int elements[MAX_SIZE];
    
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                root = createTreeRec();
                break;
            case 2:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements (-1 for NULL nodes): ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &elements[i]);
                }
                root = createTreeIter(elements, n);
                break;
            case 3:
                printf("Inorder (Recursive): ");
                inorder_rec(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder (Recursive): ");
                preorder_rec(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder (Recursive): ");
                postorder_rec(root);
                printf("\n");
                break;
            case 6:
                printf("Inorder (Iterative): ");
                inorder_iter(root);
                printf("\n");
                break;
            case 7:
                printf("Preorder (Iterative): ");
                preorder_iter(root);
                printf("\n");
                break;
            case 8:
                printf("Postorder (Iterative): ");
                postorder_iter(root);
                printf("\n");
                break;
            case 9:
                printf("Level Order: ");
                levelorder(root);
                printf("\n");
                break;
            case 10:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val)) {
                    printf("Value %d found in tree.\n", val);
                } else {
                    printf("Value %d not found in tree.\n", val);
                }
                break;
            case 11:
                copy = copyTree(root);
                printf("Tree copied successfully.\n");
                printf("Inorder of copy: ");
                inorder_rec(copy);
                printf("\n");
                break;
            case 12: 
                int count = countTrees(root);
                printf("Number of nodes in tree: %d\n", count);
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 12);
    
    return 0;
}