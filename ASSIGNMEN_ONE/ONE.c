#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], pos[n], neg[n];

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p = 0, q = 0;

    for(i = 0; i < n; i++) {
        if(arr[i] >= 0)
            pos[p++] = arr[i];
        else
            neg[q++] = arr[i];
    }

    int pi = 0, ni = 0, k = 0;

    while(pi < p && ni < q) {
        arr[k++] = pos[pi++];
        arr[k++] = neg[ni++];
    }

    while(pi < p) {
        arr[k++] = pos[pi++];
    }

    while(ni < q) {
        arr[k++] = neg[ni++];
    }

    printf("Rearranged array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}