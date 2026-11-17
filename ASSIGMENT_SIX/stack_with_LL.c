#include <stdio.h>
#include <stdlib.h>
struct NODE {
    int value;
    struct NODE *Link;
};
struct NODE *head = NULL;
struct NODE *tail = NULL;
int n = 5;
int count = 0;
void Push(int val) {
    if (count == n) {
        printf("Stack over flow\n");
        return;
    }
    struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE));
    newNode->value = val;
    newNode->Link = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->Link = newNode;
        tail = newNode;
    }
    count++;
}
void pop() {
    if (count == 0) {
        printf("Stack under flow\n");
        return;
    }
    struct NODE *temp = head;
    if (head == tail) {
        printf("%d\n", tail->value);
        head = NULL;
        tail = NULL;
    }
    else {
        while (temp->Link != tail) {
            temp = temp->Link;
        }
        printf("%d\n", tail->value);
        free(tail);
        tail = temp;
        tail->Link = NULL;
    }
    count--;
}
int main() {
    Push(7);
    Push(9);
    Push(8);
    Push(6);
    Push(5);
    pop();
    pop();
    pop();
    Push(2);
    Push(1);
    Push(3);
    Push(7);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    return 0;
}