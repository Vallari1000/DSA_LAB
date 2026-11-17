
#include <stdio.h>

void farculate(int arr[], int n, int i){
    int largest = i;
    int left_index = 2 * i + 1;
    int right_index = 2 * i + 2;

    if (left_index < n && arr[left_index] > arr[largest])
        largest = left_index;

    if (right_index < n && arr[right_index] > arr[largest])
        largest = right_index;

    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        farculate(arr, n, largest);
    }
}

void Sort_using_heap(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        farculate(arr, n, i);

    for (int i = n - 1; i > 0; i--)    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        farculate(arr, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter count of element : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Sort_using_heap(arr, n);

    printf("Resulted sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
