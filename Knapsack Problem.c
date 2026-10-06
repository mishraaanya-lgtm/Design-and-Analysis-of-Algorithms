#include <stdio.h>
#include <stdlib.h>

int maxValueInKnapsack(int n, int *values, int *weights, int capacity) {
    // Create a DP table with (n+1) rows and (capacity+1) columns
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
    }

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j) {
                // Item can be included: choose max of including or excluding
                int include = dp[i - 1][j - weights[i - 1]] + values[i - 1];
                int exclude = dp[i - 1][j];
                dp[i][j] = (include > exclude) ? include : exclude;
            } else {
                // Item cannot be included
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The answer is in dp[n][capacity]
    int result = dp[n][capacity];

    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int *values = (int *)malloc(n * sizeof(int));
    int *weights = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int capacity;
    scanf("%d", &capacity);

    printf("%d\n", maxValueInKnapsack(n, values, weights, capacity));

    free(values);
    free(weights);

    return 0;
}
