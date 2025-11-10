#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node{
    int rank_id;
    char name[30];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int id, char name[]) {
    Node* n = malloc(sizeof(Node));

    n->rank_id = id;

    int i = 0;
    while (name[i] != '\0'){
        n->name[i] = name[i];
        i++;
    }
    n->name[i+1] = name[i+1];
    n->left = NULL;
    n->right = NULL;

    return n;
}

Node* insertNode(Node* root, int id, char name[]){
    if (root == NULL){
        root = createNode(id, name);
    }
    else if (id < root->rank_id){
        root->left = insertNode(root->left, id, name);
    }
    else {
        root->right = insertNode(root->right, id, name);
    }

    return root;
}

void postorder(Node* root){
    Node* s1[MAX];
    Node* s2[MAX];
    int top1 = -1, top2 = -1;
    
    s1[++top1] = root;

    while (top1 > -1){
        Node* curr = s1[top1--];
        s2[++top2] = curr;

        if (curr->left) s1[++top1] = curr->left;
        if (curr->right) s1[++top1] = curr->right;
    }

    while (top2 != -1){
        Node* node = s2[top2--];
        printf("Rank ID: %d\n", node->rank_id);
        printf("Team Name: %s\n\n", node->name);
    }
}

Node* findMin(Node* root){
    if (!root) return NULL;

    Node* temp = root;

    while (temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

Node* findMax(Node* root){
    if (!root) return NULL;

    Node* temp = root;

    while (temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}

Node* deleteNode(Node* root, int val){
    if (root == NULL){
        printf("Not found\n");
        return root;
    }
    else if (val < root->rank_id){
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->rank_id){
        root->right = deleteNode(root->right, val);
    }
    
    else{
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if (root->left == NULL){
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL){
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        else{
            Node* temp = findMin(root->right);
            root->rank_id = temp->rank_id;
            strcpy(root->name, temp->name);
            root->right = deleteNode(root->right, temp->rank_id);
        }
    }

    return root;
}

int main(void) {
    Node *root = NULL;
    int choice;
    int id;
    char name[30];

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert node\n");
        printf("2. Delete node by Rank ID\n");
        printf("3. Find minimum (leftmost)\n");
        printf("4. Find maximum (rightmost)\n");
        printf("5. Postorder traversal (iterative)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            // invalid input, clear stdin and continue
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input. Try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter Rank ID: ");
                if (scanf("%d", &id) != 1) {
                    while (getchar() != '\n') {}
                    printf("Invalid ID.\n");
                    break;
                }
                while (getchar() != '\n') {} // consume newline
                printf("Enter Team Name (max 29 chars): ");
                if (fgets(name, sizeof(name), stdin) == NULL) {
                    name[0] = '\0';
                } else {
                    // strip newline
                    size_t ln = strcspn(name, "\n");
                    name[ln] = '\0';
                }
                root = insertNode(root, id, name);
                printf("Inserted (ID: %d, Name: %s)\n", id, name);
                break;

            case 2:
                printf("Enter Rank ID to delete: ");
                if (scanf("%d", &id) != 1) {
                    while (getchar() != '\n') {}
                    printf("Invalid ID.\n");
                    break;
                }
                root = deleteNode(root, id);
                break;

            case 3: {
                Node *mn = findMin(root);
                if (mn) {
                    printf("Minimum node -> Rank ID: %d, Team Name: %s\n", mn->rank_id, mn->name);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            }

            case 4: {
                Node *mx = findMax(root);
                if (mx) {
                    printf("Maximum node -> Rank ID: %d, Team Name: %s\n", mx->rank_id, mx->name);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            }

            case 5:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("\nPostorder traversal:\n");
                    postorder(root);
                }
                break;

            case 6:
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}