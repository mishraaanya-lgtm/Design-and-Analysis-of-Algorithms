#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int cost[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int total = 1 << n;

    // dp[mask][i] = minimum cost to visit all cities in mask
    // and end at city i
    int dp[total][n];

    for (int mask = 0; mask < total; mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = INF;
        }
    }

    // Start from city 0
    dp[1][0] = 0;

    for (int mask = 1; mask < total; mask++) {

        for (int u = 0; u < n; u++) {

            if (!(mask & (1 << u)))
                continue;

            if (dp[mask][u] == INF)
                continue;

            for (int v = 0; v < n; v++) {

                // Already visited
                if (mask & (1 << v))
                    continue;

                // No connection
                if (cost[u][v] == -1)
                    continue;

                int newMask = mask | (1 << v);

                int newCost = dp[mask][u] + cost[u][v];

                if (newCost < dp[newMask][v]) {
                    dp[newMask][v] = newCost;
                }
            }
        }
    }

    int fullMask = total - 1;
    int answer = INF;

    // Return to starting city 0
    for (int i = 1; i < n; i++) {

        if (dp[fullMask][i] == INF)
            continue;

        if (cost[i][0] == -1)
            continue;

        int tourCost = dp[fullMask][i] + cost[i][0];

        if (tourCost < answer) {
            answer = tourCost;
        }
    }

    printf("%d\n", answer);

    return 0;
}

