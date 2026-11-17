#include<stdio.h>
#include<ctype.h>
#include<string.h>
int evaluate(char expression[], int n){
    int stack[1024];
    int s = -1;
    for(int i=0; i<n; i++){
        if(expression[i] == ' '){
            continue;
        }
        if(isdigit(expression[i])){
            if(s==1023){
                printf("stack over flow");
                return -1;
                break;
            }else{
                stack[++s] = expression[i] - '0';
            }
           
        }else{
            if(s<1){
                printf("stack underflow\n");
                return -1;
                break;
            }else{
                char ch = expression[i];
                if(ch == '+'){
                    int val = stack[s] + stack[--s];
                    stack[s] = val;
                }else if(ch == '-'){
                    int a = stack[s];
                    int b = stack[--s];
                    int val = b-a;
                    stack[s] = val;
                }else if(ch == '*'){
                    int val = stack[s] * stack[--s];
                    stack[s] = val;
                }else{
                    int b = stack[s];
                    int a = stack[--s];
                    if(b == 0){
                        printf("undefine opeation\n");
                        return -1;
                        break;
                    }else{
                        int val = a/b;
                        stack[s] = val;
                    }
                }
            }
        }
    }
    if(s !=0){
        printf("invalid expression\n");
        return -1;
    }
    return stack[0];
} 

int main(){
    printf("Enter the expression here : ");
    char expression[100];
    scanf("%s", expression);
    int answer = evaluate(expression, strlen(expression));
    printf("Answer = %d", answer);
}