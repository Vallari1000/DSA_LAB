#include<stdio.h>
#include<stdlib.h>
struct  node{
    int value;
    struct node* next;
    struct node* pre;    
};
struct node* head = NULL;
struct node* tail = NULL;

void add_node(int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = val;
    if (head==NULL){
        head = tail = new_node;
        new_node->next = NULL;
        head->pre = NULL;
    }else{
        tail->next = new_node;
        new_node->pre = tail;
        tail = new_node;
        new_node->next = NULL;
    }
}

void add_at_index(int n, int val){
    
}
void print_list(){
    struct node* curr = head;
    while(curr->next != NULL){
        printf("%d<=>", curr->value);
        curr = curr->next;
    }
    printf("%d", curr->value);
}
void print_from_last(){
    printf("\n");
    struct node* curr = tail;
    while(curr->pre != NULL){
        printf("%d<=>", curr->value);
        curr = curr->pre;
    }
    printf("%d", curr->value);
}

int main(){
    add_node(7);
    add_node(6);
    add_node(3);
    add_node(2);
    add_node(9);
    add_node(1);
    print_list();
    print_from_last();
    return 0;
}