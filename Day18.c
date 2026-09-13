#include <stdio.h>
#include <stdlib.h>

void find_center_node(int edges[][2], int n) {
    int u0 = edges[0][0], v0 = edges[0][1];
    int u1 = edges[1][0], v1 = edges[1][1];

    if (u0 == u1 || u0 == v1) {
        printf("%d\n", u0);
    } else {
        printf("%d\n", v0);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int (*edges)[2] = malloc((n - 1) * sizeof(*edges));
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    find_center_node(edges, n);

    free(edges);
    return 0;
}
