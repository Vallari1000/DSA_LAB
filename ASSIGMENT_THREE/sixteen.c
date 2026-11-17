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

    int largest_element = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest_element) {
            largest_element = arr[i];
        }
    }

    largest_element++;

    int fre_arr[largest_element];

    for (int i = 0; i < largest_element; i++) {
        fre_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        fre_arr[arr[i]]++;
    }

    printf("\nCOMPRESSED ARRAY:\n");

    for (int i = 0; i < largest_element; i++) {
        if (fre_arr[i] > 0) {
            printf("Element %d has %d frequency.\n", i, fre_arr[i]);
        }
    }

    return 0;
}