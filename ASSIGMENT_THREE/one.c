#include<stdio.h>
int main(){
    int n;
    printf("Enter size of the array :  ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i] );
    }    
    return 0;
}