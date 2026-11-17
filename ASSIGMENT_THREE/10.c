#include <stdio.h>

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_pro = arr[0];

    for (int i = 0; i < n; i++) {
        int curr_pro = 1;

        for (int j = i; j < n; j++) {
            curr_pro *= arr[j];

            if (curr_pro > max_pro) {
                max_pro = curr_pro;
            }
        }
    }

    printf("Max contiguous product: %d", max_pro);

    return 0;
}