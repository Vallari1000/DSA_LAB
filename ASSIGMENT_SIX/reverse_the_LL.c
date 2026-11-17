#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct  node* link;
    
};
struct node* head = NULL;
struct node* tail = NULL;
void add_node(int val){
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->val = val;
    if(head == NULL){
        head = tail = newnode;
        newnode->link = NULL;
    }else{
        tail->link = newnode;
        tail = newnode;
        newnode->link = NULL;
    }   
}

struct node* pre = NULL;

void reverse_the_LL(){
    struct node* curr = head;
    struct node* nex = head->link;
    while(curr->link!=NULL){
        curr->link = pre;
        pre = curr;
        curr = nex;
        nex = nex->link;
    }
    curr->link = pre;
    head = curr;
}
void print_LL(){
    struct node* curr = head;
    while(curr->link != NULL){
        printf("%d->", curr->val);
        curr = curr->link;
    }
    printf("%d\n", curr->val);
}

int main(){
    add_node(8);
    add_node(7);
    add_node(6);
    add_node(9);
    print_LL();
    reverse_the_LL();
    print_LL();
    return 0;
}