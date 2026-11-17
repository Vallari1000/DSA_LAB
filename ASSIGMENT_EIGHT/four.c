#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct Info {
    int min;
    int max;
    int sum;
    int isBST;
};

struct Info largestBST(struct Node* root, int *ans) {
    if (root == NULL)
        return (struct Info){INT_MAX, INT_MIN, 0, 1};
    struct Info left = largestBST(root->left, ans);
    struct Info right = largestBST(root->right, ans);
    struct Info curr;
    if (left.isBST && right.isBST &&
        root->data > left.max && root->data < right.min) {

        curr.isBST = 1;
        curr.sum = left.sum + right.sum + root->data;

        curr.min = root->left ? left.min : root->data;
        curr.max = root->right ? right.max : root->data;

        if (curr.sum > *ans)
            *ans = curr.sum;
    }
    else {
        curr.isBST = 0;
        curr.sum = 0;
        curr.min = INT_MIN;
        curr.max = INT_MAX;
    }
    return curr;
}

int main() {
    struct Node* root = createNode(7);
    root->left = createNode(2);
    root->right = createNode(8);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(9);
    int ans = 0;
    largestBST(root, &ans);
    printf("Maximum BST Sum = %d", ans);
    return 0;
}