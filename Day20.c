#include <stdio.h>
#include <stdlib.h>

int userLogic(int **grid, int n, int m) {
    int **dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(m * sizeof(int));
    }

    dp[0][0] = grid[0][0];

    // Initialize first row
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Initialize first column
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill minimum cumulative paths for remaining cells
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int top = dp[i - 1][j];
            int left = dp[i][j - 1];
            dp[i][j] = grid[i][j] + (top < left ? top : left);
        }
    }

    int result = dp[n - 1][m - 1];

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = userLogic(grid, n, m);
    printf("%d\n", result);

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
