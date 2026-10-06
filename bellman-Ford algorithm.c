#include <stdio.h>
#include <stdlib.h>

#define INF 2e9

// Structure to represent a directed, weighted edge
typedef struct {
    int u, v, w;
} Edge;

// Function to print the path recursively using parent pointers
void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        printf("%d", vertex);
        return;
    }
    printPath(parent, parent[vertex]);
    printf("->%d", vertex);
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    // Initialize distances and parent pointers
    int* dist = (int*)malloc((V + 1) * sizeof(int));
    int* parent = (int*)malloc((V + 1) * sizeof(int));

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            
            // Clean up memory before returning
            free(edges);
            free(dist);
            free(parent);
            return 0;
        }
    }

    // Print the results for each vertex (except the source)
    for (int i = 1; i <= V; i++) {
        if (i == src) continue;

        if (dist[i] == INF) {
            printf("%d INF None\n", i);
        } else {
            printf("%d %d ", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }

    // Clean up memory
    free(edges);
    free(dist);
    free(parent);

    return 0;
}

