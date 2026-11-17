#include <stdio.h>

int main() {
    int n, sum, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter required sum: ");
    scanf("%d", &sum);

    // Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Two Pointer
    int left = 0, right = n - 1;

    printf("Pairs with sum %d are:\n", sum);

    while(left < right) {
        int s = arr[left] + arr[right];

        if(s == sum) {
            printf("%d %d\n", arr[left], arr[right]);
            left++;
            right--;
        }
        else if(s < sum)
            left++;
        else
            right--;
    }

    return 0;
}