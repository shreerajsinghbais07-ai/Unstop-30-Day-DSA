#include <stdio.h>
#include <stdlib.h>

int sum_of_depths(int n, int edges[][2]) {
    // Dynamically allocate graph representation based on N
    int* head = (int*)malloc((n + 1) * sizeof(int));
    int* to = (int*)malloc(2 * n * sizeof(int));
    int* next_edge = (int*)malloc(2 * n * sizeof(int));

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }

    int edge_cnt = 0;

    // Build bidirectional tree graph
    for (int i = 0; i < n - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Edge u -> v
        to[edge_cnt] = v;
        next_edge[edge_cnt] = head[u];
        head[u] = edge_cnt++;

        // Edge v -> u
        to[edge_cnt] = u;
        next_edge[edge_cnt] = head[v];
        head[v] = edge_cnt++;
    }

    // Queue and depth tracking for BFS
    int* queue = (int*)malloc((n + 1) * sizeof(int));
    int* depth = (int*)malloc((n + 1) * sizeof(int));
    int* visited = (int*)calloc((n + 1), sizeof(int));

    int front = 0, rear = 0;

    // Start BFS from Root Node 1
    queue[rear++] = 1;
    visited[1] = 1;
    depth[1] = 0;

    long long total_bias = 0;

    while (front < rear) {
        int u = queue[front++];
        total_bias += depth[u];

        for (int e = head[u]; e != -1; e = next_edge[e]) {
            int v = to[e];
            if (!visited[v]) {
                visited[v] = 1;
                depth[v] = depth[u] + 1;
                queue[rear++] = v;
            }
        }
    }

    // Free memory
    free(head);
    free(to);
    free(next_edge);
    free(queue);
    free(depth);
    free(visited);

    return (int)total_bias;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int (*edges)[2] = malloc((n - 1) * sizeof(*edges));
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int result = sum_of_depths(n, edges);
    printf("%d\n", result);

    free(edges);
    return 0;
}
