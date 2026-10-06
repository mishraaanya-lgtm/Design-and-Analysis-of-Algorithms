#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// A utility function to find the set/root of an element i
int find(int i, int parent[]) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// A utility function to perform union of two sets
void unionSets(int i, int j, int parent[]) {
    int root_a = find(i, parent);
    int root_b = find(j, parent);
    parent[root_a] = root_b;
}




void kruskalMST(int **cost, int V) {
	 int *parent = (int *)malloc(V * sizeof(int));
    
    // Initialize each vertex as its own parent/set
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edge_count = 0;
    int min_cost = 0;

    // Include V-1 edges in the Minimum Spanning Tree
    while (edge_count < V - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;

        // Find the absolute minimum weight edge remaining in the graph
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Change 0 to 9999 because 9999 represents "no edge" / infinity
                if (cost[i][j] != 9999 && cost[i][j] < min) {
                    // Check if picking this edge creates a cycle
                    if (find(i, parent) != find(j, parent)) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // If no more valid edges can be found, break (graph might be disconnected)
        if (u == -1 || v == -1) {
            break;
        }

        // Merge the components together
        unionSets(u, v, parent);
        
        // Match the platform format: Edge 0:(0, 1) cost:2
        printf("Edge %d:(%d, %d) cost:%d\n", edge_count, u, v, min);
        
        min_cost += min;
        edge_count++;
    }
    
    // Match the platform format: Minimum cost= 14
    printf("Minimum cost= %d\n", min_cost);

    free(parent);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
