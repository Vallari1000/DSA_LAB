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
    int first_p;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;){
            if(arr[j]>0 & arr[j+1]<0){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                j = j+2;
            }else{
                j++;
            }
        }
    } 
    printf("Rearranged positive and negitive : \n");
    for(int i=0; i<n; i++){
            printf("%d ", arr[i]);
        }  
    return 0;
}