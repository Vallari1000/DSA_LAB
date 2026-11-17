#include<stdio.h>
#include <stdlib.h> 
struct NODE{
    int value;
    struct NODE *Link;    
};
struct NODE* start = NULL;
struct NODE* tail = NULL; 
int n = 5;
static int push_index = 0; 
static int pop_index = 5;
    void Push(int val){
        if(push_index > n){
            printf("stack over flow\n");
            return;
        }
        push_index++;
        pop_index++;
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
    void pop(){
        if(pop_index < 0){
            printf("stack under flow\n");
            return;
        }
        printf("%d\n", tail->value);
        pop_index--;
        push_index--;
        pre_node = start;
        while(pre_node->Link->Link!=NULL){
            pre_node = pre_node->Link;
        }
        free(pre_node->Link);
        pre_node->Link = NULL;

    }
      

int main(){
    Push(7);
    Push(9);
    Push(8);
    Push(6);
    Push(5);
    Push(4);
    pop();
    pop();
    pop();
    Push(2);
    Push(1);
    Push(3);
    Push(7);
    return 0;
}