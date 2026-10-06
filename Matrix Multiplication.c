#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    // Read dimensions of matrix A
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Allocate and read matrix A
    int **A = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int n_B, p;
    // Read dimensions of matrix B
    if (scanf("%d %d", &n_B, &p) != 2) {
        // Cleanup A before leaving
        for (int i = 0; i < m; i++) free(A[i]);
        free(A);
        return 0;
    }

    // Check if multiplication is possible
    if (n != n_B) {
        printf("Invalid input\n");
        // Cleanup A
        for (int i = 0; i < m; i++) free(A[i]);
        free(A);
        return 0;
    }

    // If valid, allocate and read matrix B
    int **B = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        B[i] = (int *)malloc(p * sizeof(int));
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Allocate and compute the result matrix C (dimensions m x p)
    int **C = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        C[i] = (int *)calloc(p, sizeof(int));
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the resulting product matrix C
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d", C[i][j]);
            if (j < p - 1) {
                printf(" ");
            }
        }
        printf(" \n"); // Tail space followed by a newline matching platform style
    }

    // Comprehensive memory cleanup
    for (int i = 0; i < m; i++) free(A[i]);
    free(A);
    for (int i = 0; i < n; i++) free(B[i]);
    free(B);
    for (int i = 0; i < m; i++) free(C[i]);
    free(C);

    return 0;
}

