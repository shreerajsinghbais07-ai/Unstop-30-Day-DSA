#include <stdio.h>
#include <stdlib.h>

// 1. Add this compare function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void concatenate(int* arr, int n, int* result) {
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
        result[i + n] = arr[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 2. Sort the array BEFORE concatenating
    qsort(arr, n, sizeof(int), compare);
    
    int* result = (int*)malloc(2 * n * sizeof(int));
    concatenate(arr, n, result);
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", result[i]);
    }
    
    free(arr);
    free(result);
    return 0;
}
