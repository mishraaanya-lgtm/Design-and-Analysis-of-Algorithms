#include <stdio.h>
    //write your code here...
        Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u); // Add reverse edge for undirected graph
    newNode->next = adjList[v];
    adjList[v] = newNode;
    
    
    
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    //write your code here...
     for (int i = 0; i < V; i++) {
        Node* sorted = NULL;
        Node* curr = adjList[i];

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = sorted;
            sorted = curr;
            curr = next;
    
     }
        
        // Bubble sort implementation for linked list
        int swapped;
        Node* head = sorted;
        do {
            swapped = 0;
            Node* first = head;
            while (first && first->next) {
                if (first->vertex > first->next->vertex) {
                    int temp = first->vertex;
                    first->vertex = first->next->vertex;
                    first->next->vertex = temp;
                    swapped = 1;
                }
                first = first->next;
            }
            head = head->next;
        } while (swapped);
        
        adjList[i] = sorted;
    }

    
}

// Depth-First Search (DFS) function
void DFS(int start) {
    //write your code here...
       visited[start] = 1;
    printf("%d ", start);
    
    Node* temp = adjList[start];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
	}
    
    
    
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}
