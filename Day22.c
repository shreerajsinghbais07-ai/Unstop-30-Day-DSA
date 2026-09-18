#include <stdio.h>
#include <stdlib.h>

int* calculatePeakReadings(int n, int k, const int* readings, int* returnSize) {
    if (n < k || k <= 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = n - k + 1;
    int* peaks = (int*)malloc((*returnSize) * sizeof(int));
    
    // Custom array-based deque storing array indices
    int* dq = (int*)malloc(n * sizeof(int));
    int head = 0;
    int tail = 0;
    int result_idx = 0;

    for (int i = 0; i < n; ++i) {
        // Remove indices outside the current window
        if (head < tail && dq[head] == i - k) {
            head++;
        }
        
        // Remove elements smaller than the current element from the back
        while (head < tail && readings[dq[tail - 1]] <= readings[i]) {
            tail--;
        }
        
        // Push current index to back
        dq[tail++] = i;
        
        // Record front element as the window max once window size reaching k
        if (i >= k - 1) {
            peaks[result_idx++] = readings[dq[head]];
        }
    }
    
    free(dq);
    return peaks;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    
    int* readings = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &readings[i]);
    }
    
    int returnSize = 0;
    int* result = calculatePeakReadings(n, k, readings, &returnSize);
    
    for (int i = 0; i < returnSize; ++i) {
        printf("%d%s", result[i], (i == returnSize - 1) ? "" : " ");
    }
    printf("\n");
    
    free(readings);
    free(result);
    
    return 0;
}
