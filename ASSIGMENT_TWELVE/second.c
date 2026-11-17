
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
    int lthread, rthread;
};

struct Node* inorderArray[100];
int count = 0;

struct Node* createNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->lthread = 0;
    new_node->rthread = 0;
    return new_node;
}

struct Node* insert_in_binary_tree(struct Node* root, int data){
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert_in_binary_tree(root->left, data);
    else if (data > root->data)
        root->right = insert_in_binary_tree(root->right, data);

    return root;
}
void storeInorder(struct Node* root){
    if (root == NULL){
        return;
    }
    storeInorder(root->left);
    inorderArray[count++] = root;
    storeInorder(root->right);
}
void add_the_thread(struct Node* root){
    count = 0;
    storeInorder(root);
    for (int i = 0; i < count; i++){
        struct Node* curr = inorderArray[i];
        if (curr->left == NULL){
            curr->left = (i == 0) ? NULL : inorderArray[i - 1];
            curr->lthread = 1;
        }
        if (curr->right == NULL){
            curr->right = (i == count - 1) ? NULL : inorderArray[i + 1];
            curr->rthread = 1;
        }
    }
}

struct Node* leftMost(struct Node* root){
    if (root == NULL)
        return NULL;
    while (root->lthread == 0 && root->left != NULL)
        root = root->left;
    return root;
}

void inorder(struct Node* root){
    struct Node* current = leftMost(root);
    while (current != NULL){
        printf("%d ", current->data);
        if (current->rthread == 1)
            current = current->right;
        else
            current = leftMost(current->right);
    }
}

int main(){
    struct Node* root = NULL;
    int n, value;

    printf("Enter count of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (int i = 0; i < n; i++){
        scanf("%d", &value);
        root = insert_in_binary_tree(root, value);
    }

    add_the_thread(root);

    printf("\nResult : ");
    inorder(root);

    return 0;
}
