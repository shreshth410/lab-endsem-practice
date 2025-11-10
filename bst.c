#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left, *right;
} Node;

Node* createNode(int val){
    Node* node = malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* createTreeRec(Node* root, int val){
    if (root == NULL){
        root = createNode(val);
    }

    else if (val < root->data){
        root->left = createTreeRec(root->left, val);
    }
    
    else {
        root->right = createTreeRec(root->right, val);
    }

    return root;
}

Node* findMin(Node* root){
    if (root){
        Node* temp = root;
        while (temp != NULL){
            temp = temp->left;
        }

        return temp;
    }
    else retunr NULL;
}

Node* findMax(Node* root){
    if (root){
        Node* temp = root;

        while (temp != NULL){
            temp = temp->right;
        }

        return temp;
    }
    else return NULL;
}

Node* deleteNode(Node* root, int val){
    if (!root) return NULL;
    else if (val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else{
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if (root->right == NULL){
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        else if (root->left == NULL){
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int searchValue(Node* root, int val){
    if (!root) return 0;
    else if (root->data == val) return 1;
    else return (searchValue(root->left, val) || searchValue(root->right, val));    
}

int findHeight(Node* root){
    if (root == NULL){
        return 0;
    }
    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);

    return ((left_height > right_height) ? left_height : right_height);
}
