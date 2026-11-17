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
    
    int k;
    printf("How many times you want to rotate it :  ");
    scanf("%d", &k);
    
    for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i] );
    }
    printf("\n");
    for(int i=0; i<k/2; i++){
        int temp = arr[i];
        arr[i] = arr[k-i-1];
        arr[k-i-1] = temp;
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i] );
    }
    printf("\n");
    for(int i=0; i<(n-k)/2; i++){
        int temp = arr[k+i];
        arr[k+i] = arr[n-(i)-1];
        arr[n-(i)-1] = temp;
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i] );
    }



    return 0;


}