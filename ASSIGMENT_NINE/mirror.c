#include<stdio.h>
#include <stdlib.h> 
struct NODE{
    int value;
    struct NODE *Left;  
    struct NODE *Right;  
};

struct NODE* make_tree(int arr[], int n){
    struct NODE* root = NULL;
    root->value = arr[0];
    for(int i=0; i<n; n++){
        struct NODE* cur = NULL; 

    }
    return root;
}      

int main(){
     
    return 0;
}