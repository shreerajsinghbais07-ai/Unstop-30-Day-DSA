#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long val;
    int original_idx;
} Element;

int cmp_ll(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int binary_search_idx(long long val, long long *unique, int u_size) {
    int low = 0, high = u_size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (unique[mid] == val) return mid;
        if (unique[mid] < val) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, w;
    if (scanf("%d %d", &n, &w) != 2) return 0;

    long long *readings = (long long *)malloc(n * sizeof(long long));
    long long *sorted = (long long *)malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &readings[i]);
        sorted[i] = readings[i];
    }

    // Coordinate Compression setup
    qsort(sorted, n, sizeof(long long), cmp_ll);
    
    int u_size = 0;
    long long *unique = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1]) {
            unique[u_size++] = sorted[i];
        }
    }
    free(sorted);

    int *compressed = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        compressed[i] = binary_search_idx(readings[i], unique, u_size);
    }

    // Structures for Sliding Window
    int *deque = (int *)malloc(n * sizeof(int));
    int head = 0, tail = 0;

    int *freq = (int *)calloc(u_size, sizeof(int));
    int distinct_count = 0;

    for (int i = 0; i < n; i++) {
        // Add element to distinct frequency map
        if (freq[compressed[i]] == 0) {
            distinct_count++;
        }
        freq[compressed[i]]++;

        // Maintain monotonic decreasing queue for window max
        while (head < tail && readings[deque[tail - 1]] <= readings[i]) {
            tail--;
        }
        deque[tail++] = i;

        // Remove elements outside current window of size W
        if (i >= w) {
            int out_idx = compressed[i - w];
            freq[out_idx]--;
            if (freq[out_idx] == 0) {
                distinct_count--;
            }
            if (deque[head] == i - w) {
                head++;
            }
        }

        // Print result when window of size W is fully formed
        if (i >= w - 1) {
            long long peak = readings[deque[head]];
            printf("%lld %d\n", peak, distinct_count);
        }
    }

    free(readings);
    free(unique);
    free(compressed);
    free(deque);
    free(freq);

    return 0;
}
