#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct TreeNode* root) {
    if (root == NULL) return;
    
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Pre-order traversal
void preOrder(struct TreeNode* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(struct TreeNode* root) {
    if (root == NULL) return;
    
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}

