#include<stdio.h>

int main() {
    int arr1[] = {1, 5, 8, 5, 7, 7};
    int n = sizeof(arr1) / sizeof(int);
    int i, j;
    
    printf("The given array is: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    printf("Unique elements are: ");
    for(i = 0; i < n; i++) {
        int isDuplicate = 0;
        for(j = 0; j < n; j++) {
            if(i != j && arr1[i] == arr1[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if(!isDuplicate) {
            printf("%d ", arr1[i]);
        }
    }
    return 0;
}

