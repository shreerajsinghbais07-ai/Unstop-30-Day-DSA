#include <stdio.h>

int max_books_on_shelf(int heights[], int n) {
    if (n == 0) return 0;

    // Array to store the smallest tail of all increasing subsequences
    int tails[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        // Binary search to find the correct position for heights[i]
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (tails[mid] >= heights[i]) {
                right = mid - 1; // Look left
            } else {
                left = mid + 1;  // Look right
            }
        }

        // Overwrite the element to create a better (lower) stepping stone,
        // or append if it's larger than all elements currently in tails.
        tails[left] = heights[i];
        if (left == size) {
            size++;
        }
    }

    return size;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    
    int result = max_books_on_shelf(heights, n);
    printf("%d\n", result);
    
    return 0;
}
