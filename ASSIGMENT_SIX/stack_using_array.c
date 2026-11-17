#include<stdio.h>
#include<stdlib.h>
static int  i = 0;
int arr[5];
void push(int val){
    if(i==5){
        printf("stack over flow");
        return;
    }
    for(int n = 4; n>0; n--){
        arr[n] = arr[n-1];
    }
    arr[0] = val;
    i++;
}
void print(){
    for(int i=0; i<5; i++){
        printf("%d", arr[i]);
    }
}
void pop(){
    static int i = 4;
    if(i<0){
        printf("stack under flow");
        return;
    }
    printf("%d\n", arr[0]);
    for(int n = 0; n<3; n++){
        arr[n] = arr[n+1];
    }
    i--;
}

int main(){
    push(8);
    push(9);
    push(7);
    pop();
    push(3);
    pop();
    push(2);
    push(1);
    return 0;
}