#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void correct_tree(struct Node* root, struct Node** incorrect1, struct Node** incorrect2, struct Node** prev) {
    if (root == NULL)
        return;
    correct_tree(root->left, incorrect1, incorrect2, prev);
    if (*prev != NULL && (*prev)->data > root->data) {
        if (*incorrect1 == NULL)
            *incorrect1 = *prev;
        *incorrect2 = root;
    }
    *prev = root;
    correct_tree(root->right, incorrect1, incorrect2, prev);
}

void print_tree(struct Node* root) {
    if (root == NULL)
        return;
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    struct Node* root = createNode(6);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(1);
    root->left->right = createNode(7);
    root->right->left = createNode(4);
    root->right->right = createNode(9);
    print_tree(root);
    struct Node* incorrect1 = NULL;
    struct Node* incorrect2 = NULL;
    struct Node* prev = NULL;
    correct_tree(root, &incorrect1, &incorrect2, &prev);

    if (incorrect1 != NULL && incorrect2 != NULL) {
        printf("\nIncorrect nodes: %d and %d",
               incorrect1->data, incorrect2->data);
        int temp = incorrect1->data;
        incorrect1->data = incorrect2->data;
        incorrect2->data = temp;
    }
    printf("\nAfter: ");
    print_tree(root);

    return 0;
}