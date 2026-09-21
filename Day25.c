#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    char *belt = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", belt);

    int req[26] = {0};
    for (int i = 0; i < m; i++) {
        char type_str[10];
        int count;
        scanf("%s %d", type_str, &count);
        req[type_str[0] - 'A'] = count;
    }

    int window[26] = {0};
    int satisfied = 0;
    int left = 0;
    int min_len = n + 1;

    for (int right = 0; right < n; right++) {
        int idx = belt[right] - 'A';
        window[idx]++;

        // If this character reaches its required target count, increment satisfied requirement count
        if (req[idx] > 0 && window[idx] == req[idx]) {
            satisfied++;
        }

        // Contract window from left as long as all m component conditions are met
        while (satisfied == m) {
            int current_len = right - left + 1;
            if (current_len < min_len) {
                min_len = current_len;
            }

            int left_idx = belt[left] - 'A';
            window[left_idx]--;
            if (req[left_idx] > 0 && window[left_idx] < req[left_idx]) {
                satisfied--;
            }
            left++;
        }
    }

    if (min_len > n) {
        printf("-1\n");
    } else {
        printf("%d\n", min_len);
    }

    free(belt);
    return 0;
}
