#include<stdio.h>
#include <stdlib.h> 
struct NODE{
    int value;
    struct NODE *Link;    
};
struct NODE* start = NULL;
struct NODE* tail = NULL;  
    void Push_Node(int val){
        struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
        newNode->value = val;
        newNode->Link = NULL;
        if(start == NULL){
            start = tail = newNode;
        }else{
            tail->Link = newNode; 
            tail = newNode; 
        }
    } 
    struct NODE* pre_node;
    void pop_back(){
         pre_node = start;
         while(pre_node->Link->Link!=NULL){
             pre_node = pre_node->Link;
         }
         free(pre_node->Link);
         pre_node->Link = NULL;

    }
    struct NODE* print_node;
    void print_LL(){
        print_node = start;
        while(tail->Link != NULL){
            printf("%d->", print_node->value );
            print_node = print_node->Link;
        }         
    } 
      

int main(){
    Push_Node(9);
    Push_Node(6);
    Push_Node(8);
    Push_Node(2);
    Push_Node(2);
    Push_Node(2);
    Push_Node(4);
    Push_Node(2);
    Push_Node(2);
    Push_Node(1);
    Push_Node(4);
    pop_back();
    pop_back();
    pop_back();
    print_LL();    
    return 0;
}