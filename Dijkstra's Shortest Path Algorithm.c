include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	
	// write your code here
   int distance[MAX];
    int pred[MAX];
    int visited[MAX];
    int count, mindistance, nextnode, i, j;

    // Initialize distance array, predecessor array, and visited tracking array
    for (i = 1; i <= n; i++) {
        if (i != startnode && G[startnode][i] == 0) {
            distance[i] = INFINITY;
        } else {
            distance[i] = G[startnode][i];
        }
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        // Find the unvisited node with the minimum distance
        for (i = 1; i <= n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        if (mindistance == INFINITY) {
            break;
        }

        visited[nextnode] = 1;
        count++;

        // Update the distances of adjacent unvisited nodes
        for (i = 1; i <= n; i++) {
            if (!visited[i]) {
                int edge_weight = G[nextnode][i];
                if (i != nextnode && edge_weight == 0) {
                    edge_weight = INFINITY;
                }

                if (edge_weight != INFINITY && (mindistance + edge_weight < distance[i])) {
                    distance[i] = mindistance + edge_weight;
                    pred[i] = nextnode;
                }
            }
        }
    }

    // Print Header
    printf("Node\tDistance\tPath\n");

    // Print rows matching strict padding requirements
    for (i = 1; i <= n; i++) {
        if (i == startnode) continue;

        if (distance[i] == INFINITY) {
            printf("   %d\t     INF\tNO PATH\n", i);
        } else {
            printf("   %d\t       %d\t%d", i, distance[i], i);
            j = i;
            do {
                j = pred[j];
                printf("<-%d", j);
            } while (j != startnode);
            printf("\n");
        }
	}
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
