#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct map {
    struct Node *node;
    int distance;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void mapping(struct Node* root, int i, struct map* arr[], int parent_dis) {
    if (root == NULL) {
        return;
    }
    struct map* newmap = malloc(sizeof(struct map));
    newmap->node = root;
    newmap->distance = parent_dis;
    arr[i] = newmap;
    i++;
    mapping(root->left, i, arr, parent_dis - 1);
    mapping(root->right, i, arr, parent_dis + 1);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    struct map* arr[19];
    int i = 0;
    mapping(root, &i, arr, 0);
    int dis[19] = {};
    printf("Top View: ");

    for(int i = -19; i<19; i++){
        for(int j = 0; j<7; j++){
            if(i == arr[j]->distance){
                printf("%d -> %d\n", arr[j]->node->data,arr[j]->distance);
                break;
            }
        }
    }

    return 0;
}