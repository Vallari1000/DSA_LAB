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

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    int D, I;
    printf("\nDo you want to delete any e  lemet : ");
    scanf("%d", &D);
    if(D){
        int d;
        printf("which position you want to delete : ");
        scanf("%d", &d);
        for(int i=d-1; i<n; i++){
            arr[i] = arr[i+1];
        }
        n--;
    }
    printf("Do you want to insert any element : ");
    scanf("%d", &I);
    if(I){
        n++;
        int k, m;
        printf("Which element you want to intest : ");
        scanf("%d", &m);
        printf("At which position you want to insert the element :");
        scanf("%d", &k);
        for(int i=n; i>k; i--){
            arr[i-1]=arr[i-2];
        }
        arr[k-1] = m;
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;


}