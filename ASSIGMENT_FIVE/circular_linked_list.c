#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *link;
};
struct node* head = NULL;
struct node* tail = NULL;

void add_node(int val){
    struct node* new_node = (struct node*)(malloc(sizeof(struct node)));
    new_node->value = val;
    int n;
    if(head == NULL){
        head = tail = new_node;
        new_node->link = NULL;
    }else{
        tail->link = new_node;
        tail = new_node;
        new_node->link = head;
    }
}

void add_at_head(int val){
    struct node* new_node = (struct node*)(malloc(sizeof(struct node)));
    new_node->value = val;
    new_node->link = head;
    head = new_node;
    tail->link = head;
}

void add_at_index(int n, int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = val;
    struct node* cur = head;
    for(int i=0; i<n-2; i++){
        cur = cur->link;
    }
    new_node->link = cur->link;
    cur->link = new_node;
}

void delete(int n){
    struct node* curr = head;
    if(n==1){
        head = head->link;
        tail->link = head;
        free(curr);
        return;
    }
    for(int i=0; i<n-2; i++){
        curr = curr->link;
    }
    struct node* temp = curr->link;
    curr->link = temp->link;
    free(temp);
    }

void print_list(){
    if(head == NULL){
        printf("Empty list.....");
    }else{
        struct node* curr = head;
        while(curr->link != head){
            printf("%d->", curr->value);
            curr = curr->link;
        }
        printf("%d->%d", curr->value, head->value);
    }
}

int main(){
    add_node(7);
    add_node(4);
    add_node(5);
    add_node(6);
    add_node(3);
    add_node(2);
    add_at_head(8);
    add_at_index(2, 77);
    add_at_index(4, 64);
    add_at_index(1, 82);
    delete(1);
    delete(6);
    print_list();
    return 0;
}