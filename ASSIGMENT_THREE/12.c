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
    int sum=0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    int num = ((n)-((((n)*(n+1))/2)-sum));
    printf("Duplicate Number: %d", num);

    return 0;
}