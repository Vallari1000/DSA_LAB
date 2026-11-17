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
    int pos_sum = 0;
    int pos_count = 0;  
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            pos_count++;
            pos_sum += arr[i];
        }
    }
    int m = -(pos_sum - ((pos_count+1)*(pos_count+2))/2);
    printf("First positive missing number : %d ", m);
    return 0;
}