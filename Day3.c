#include <stdio.h>

void find_flower_indices(int n, int t, int arr[], int result[2]) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int current_sum = arr[left] + arr[right];

        if (current_sum == t) {
            // Store the indices in the result array and exit
            result[0] = left;
            result[1] = right;
            return; 
        }
        else if (current_sum < t) {
            left++; 
        }
        else {
            right--; 
        }
    }
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    
    // Variable-length array for the flower types
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result[2];
    find_flower_indices(n, t, arr, result);
    
    printf("%d %d\n", result[0], result[1]);
    
    return 0;
}
