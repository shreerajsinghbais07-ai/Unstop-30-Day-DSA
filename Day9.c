#include <stdio.h>
#include <stdlib.h> // Required for qsort and malloc

// 1. Change the function signature to return long long
long long user_logic(int n, int arr[], int b[]);

int compare(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 2. Use malloc to allocate memory dynamically (prevents stack overflow)
    int *arr = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    // 3. Catch the result as a long long and print using %lld
    long long result = user_logic(n, arr, b);
    printf("%lld\n", result);
    
    free(arr);
    free(b);
    
    return 0;
}

// 4. Update the logic function to return long long directly
long long user_logic(int n, int arr[], int b[]) {
    qsort(arr, n, sizeof(int), compare);
    qsort(b, n, sizeof(int), compare);

    long long score1 = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && b[j] <= arr[i]) {
            j++;
        }
        score1 += j;
    }

    long long score2 = 0;
    int i_ptr = 0;
    for (int k = 0; k < n; k++) {
        while (i_ptr < n && arr[i_ptr] <= b[k]) {
            i_ptr++;
        }
        score2 += i_ptr;
    }

    return score1 > score2 ? score1 : score2; 
}
