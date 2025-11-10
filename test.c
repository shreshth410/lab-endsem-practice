#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Utility functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// Right rotate
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // New root
}

// Left rotate
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // New root
}

// Get balance factor
int getBalance(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Insert node in AVL and balance the tree
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Enter number of nodes to insert into AVL Tree: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder traversal of AVL Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}

/*#include <stdio.h>
#include <string.h>

#define MAX 100

struct patient {
    char name[30];
    int age;
    int prio;
};

struct patient q[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue full!\n");
        return;
    }
    
    if (front == -1) front = 0;
    rear++;
    
    printf("Name: ");
    scanf("%s", q[rear].name);
    printf("Age: ");
    scanf("%d", &q[rear].age);
    printf("Priority: ");
    scanf("%d", &q[rear].prio);
    
    printf("Patient added.\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue empty!\n");
        return;
    }
    
    printf("Removed: %s, Age: %d, Priority: %d\n", 
           q[front].name, q[front].age, q[front].prio);
    front++;
    
    if (front > rear) front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue empty!\n");
        return;
    }
    
    printf("Patients in queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%s, %d, %d\n", q[i].name, q[i].age, q[i].prio);
    }
}

int main() {
    int ch;
    
    printf("\nPatient Queue Menu:\n");
    printf("1. Add patient\n");
    printf("2. Remove patient\n");
    printf("3. Display queue\n");
    printf("4. Exit\n");
    
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}*/

/*#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Enter order of matrix (n): ");
        scanf("%d", &n);
    }while (n < 0);

    int a[n][n];
    int s = n*n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element %d-%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    int b[s];
    int k = 0;
    while (k<s)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[k] = a[i][j];
                k++;
            }
        }
    }
    
    for (int i = 0; i < s; i++)
    {
        printf("%d\t", b[i]);
    }
    printf("\n");

    int move;
    printf("Enter number of spaces to shift: ");
    scanf("%d", &move);

    int c[s];
    move = move % s;

    for (int i = 0; i < s; i++)
    {
        c[(i+move)%s] = b[i];
    }

    for (int i = 0; i < s; i++)
    {
        printf("%d\t", c[i]);
    }    
}
*/