#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    long long L;
    if (scanf("%d %lld", &n, &L) != 2) return 0;

    long long *speed = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &speed[i]);
    }

    // Allocation for two dynamic deques storing indices
    int *max_dq = (int *)malloc(n * sizeof(int));
    int *min_dq = (int *)malloc(n * sizeof(int));
    int max_head = 0, max_tail = 0;
    int min_head = 0, min_tail = 0;

    int left = 0;
    int max_len = 0;

    for (int right = 0; right < n; right++) {
        // Maintain monotonic decreasing order for max deque
        while (max_head < max_tail && speed[max_dq[max_tail - 1]] <= speed[right]) {
            max_tail--;
        }
        max_dq[max_tail++] = right;

        // Maintain monotonic increasing order for min deque
        while (min_head < min_tail && speed[min_dq[min_tail - 1]] >= speed[right]) {
            min_tail--;
        }
        min_dq[min_tail++] = right;

        // Shrink window from left if current window spread exceeds tolerance L
        while (speed[max_dq[max_head]] - speed[min_dq[min_head]] > L) {
            if (max_dq[max_head] == left) {
                max_head++;
            }
            if (min_dq[min_head] == left) {
                min_head++;
            }
            left++;
        }

        // Update maximum stretch length
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    printf("%d\n", max_len);

    free(speed);
    free(max_dq);
    free(min_dq);

    return 0;
}
