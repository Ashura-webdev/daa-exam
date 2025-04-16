#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int main() {
    int w[100], v[100], n, W, i, j, dp[101][101];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(i = 0; i < n; i++) scanf("%d", &w[i]);

    printf("Enter values:\n");
    for(i = 0; i < n; i++) scanf("%d", &v[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for(i = 0; i <= n; i++) {
        for(j = 0; j <= W; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(w[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - w[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("Maximum value: %d\n", dp[n][W]);
    return 0;
}
