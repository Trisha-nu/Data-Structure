#include <stdio.h>
int main() {
    int n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    int low = 0;
    int high = n - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x) {
            result = mid;
            break;
        }
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);
    return 0;
}

