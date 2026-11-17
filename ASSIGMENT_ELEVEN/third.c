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

void print_tree(struct Node* root, int arr[], int *i) {
    if (root == NULL)
        return;
    print_tree(root->left, arr, i);
    arr[(*i)++] = root->data;
    print_tree(root->right, arr, i);
}

void k_smallest(int arr[], int n, int k, int x) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int d1 = abs(arr[i] - x);
            int d2 = abs(arr[j] - x);
            if (d1 > d2 || (d1 == d2 && arr[i] > arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < k && i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    struct Node* root = createNode(7);

    root->left = createNode(4);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

    int arr[7];
    int n = 0;
    print_tree(root, arr, &n);
    int x = 6, k = 3;
    printf("Closest values: ");
    k_smallest(arr, n, k, x);

    return 0;
}