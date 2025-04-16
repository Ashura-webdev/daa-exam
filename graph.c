#include <stdio.h>

#define V 4 // Number of vertices

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int isSafe(int v, int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c) // Adjacent vertex has same color
            return 0;
    return 1;
}

int graphColoring(int m, int color[], int v) {
    if (v == V) // All vertices are assigned a color
        return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c)) {
            color[v] = c;
            if (graphColoring(m, color, v + 1)) // Assign color to next vertex
                return 1;
            color[v] = 0; // Backtrack
        }
    }

    return 0; // No color can be assigned
}

void printSolution(int color[]) {
    printf("Solution exists: \n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %d\n", i, color[i]);
}

int main() {
    int color[V] = {0}; // Initialize all vertices with no color
    int m = 3; // Number of colors

    if (!graphColoring(m, color, 0)) {
        printf("Solution does not exist\n");
    } else {
        printSolution(color);
    }

    return 0;
}
