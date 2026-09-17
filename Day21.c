#include <stdio.h>
#include <stdbool.h>

bool user_logic(int n, int runs[]) {
    int max_reachable = 0;

    for (int i = 0; i < n; i++) {
        // If current index is beyond the maximum reach, we are stuck
        if (i > max_reachable) {
            return false;
        }

        // Update the maximum reach possible from current ball
        if (i + runs[i] > max_reachable) {
            max_reachable = i + runs[i];
        }

        // Early exit if target N-1 is reachable
        if (max_reachable >= n - 1) {
            return true;
        }
    }

    return max_reachable >= n - 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int runs[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &runs[i]);
    }

    bool result = user_logic(n, runs);
    printf(result ? "true\n" : "false\n");

    return 0;
}
