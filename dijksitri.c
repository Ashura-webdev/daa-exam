#include <stdio.h>
#define INF 99999
#define N 100

int main() {
    int n, src, i, j, u, v, min, dist[N], visited[N], graph[N][N];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use %d for INF):\n", INF);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(i = 0; i < n - 1; i++) {
        min = INF;
        for(j = 0; j < n; j++)
            if(!visited[j] && dist[j] < min)
                min = dist[j], u = j;

        visited[u] = 1;

        for(v = 0; v < n; v++)
            if(graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Shortest distances from vertex %d:\n", src);
    for(i = 0; i < n; i++)
        printf("To %d: %d\n", i, dist[i]);

    return 0;
}
