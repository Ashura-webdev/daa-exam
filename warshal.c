#include <stdio.h>
#define INF 99999
#define N 100

int main() {
    int n, i, j, k, d[N][N];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use %d for INF):\n", INF);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("Shortest distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%4d ", (d[i][j] == INF) ? INF : d[i][j]);
        printf("\n");
    }

    return 0;
}
