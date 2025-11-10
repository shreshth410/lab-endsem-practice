#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int getHeight(Node* n){
    return n == NULL ? -1 : n->height;
}

void LLRotation(Node** k){
    Node* temp = (*k)->left;

    (*k)->left = temp->right;
    temp->right = (*k);

    (*k)->height = MAX(height((*k)->left), height((*k)->right)) + 1;
    temp->height = MAX(height(temp->left), (*k)->height) + 1;

    (*k) = temp;
}

void RRRotation(Node** k){
    Node* temp = (*k)->right;

    (*k)->right = temp->left;
    temp->left = (*k);

    (*k)->height = MAX(height((*k)->left), height((*k)->right)) + 1;
    temp->height = MAX(height(temp->right), (*k)->height) + 1;

    (*k) = temp;
}

void LRRotation(Node** k){
    RRRotation(&((*k)->left));
    LLRotation(k);
}

void RLRotation(Node** k){
    LLRotation(&((*k)->right));
    RRRotation(k);
}

void insert(Node** root, int val){
    if (*root == NULL){
        *root = malloc(sizeof(Node));
        (*root)->data = val;
        (*root)->left = (*root)->right = NULL;
        (*root)->height = 0;
    }

    else if ((*root)->data == val){
        return;
    }

    else if (val <  (*root)->data){
        insert(&((*root)->left), val);

        if (height((*root)->left) - height((*root)->right) == 2){
            if (val < (*root)->left->data)
                LLrotation(root);
            else
                LRRotation(root);
        }
    }
    
    else {
        insert(&((*root)->right), val);

        if (height((*root)->right) - height((*root)->left) == 2){
            if (val > (*root)->right->data)
                RRRotation(root);
            else 
                RLRotation(root);
        }
    }

    (*root)->height = MAX(height((*root)->left), height((*root)->right)) + 1;

}

void inorder(Node* root){
    if (!root) return;

    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}
