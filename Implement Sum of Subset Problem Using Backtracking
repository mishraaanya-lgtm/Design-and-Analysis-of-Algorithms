#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to store a single valid subset
typedef struct {
    int *elements;
    int size;
} Subset;

Subset *found_subsets = NULL;
int subset_count = 0;
int max_subsets = 100;

// Function to store a discovered subset
void saveSubset(int current_subset[], int subset_size) {
    if (subset_count >= max_subsets) {
        max_subsets *= 2;
        found_subsets = (Subset *)realloc(found_subsets, max_subsets * sizeof(Subset));
    }
    
    found_subsets[subset_count].elements = (int *)malloc(subset_size * sizeof(int));
    found_subsets[subset_count].size = subset_size;
    for (int i = 0; i < subset_size; i++) {
        found_subsets[subset_count].elements[i] = current_subset[i];
    }
    subset_count++;
}

// Backtracking function to find all matching subsets
void findSubsets(int arr[], int n, int target_sum, int index, int current_subset[], int subset_size, int current_sum) {
    // If the target sum is reached, save the subset and return immediately
    // (since elements are >= 1, adding more elements will only exceed the sum)
    if (current_sum == target_sum) {
        saveSubset(current_subset, subset_size);
        return; 
    }

    // Base condition if we run out of elements or exceed the sum
    if (index >= n || current_sum > target_sum) {
        return;
    }

    // Option 1: Include the current element
    current_subset[subset_size] = arr[index];
    findSubsets(arr, n, target_sum, index + 1, current_subset, subset_size + 1, current_sum + arr[index]);

    // Option 2: Exclude the current element
    findSubsets(arr, n, target_sum, index + 1, current_subset, subset_size, current_sum);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target_sum;
    scanf("%d", &target_sum);

    // Dynamic arrays for tracking path during recursion
    int *current_subset = (int *)malloc(n * sizeof(int));
    found_subsets = (Subset *)malloc(max_subsets * sizeof(Subset));

    // Trigger the backtracking search
    findSubsets(arr, n, target_sum, 0, current_subset, 0, 0);

    // Output formatting logic
    if (subset_count == 0) {
        printf("-1\n");
    } else {
        // Print subsets in reverse order of discovery (last found first)
        for (int i = subset_count - 1; i >= 0; i--) {
            for (int j = 0; j < found_subsets[i].size; j++) {
                printf("%d", found_subsets[i].elements[j]);
                if (j < found_subsets[i].size - 1) {
                    printf(" ");
                }
            }
            printf(" \n"); // Matches trailing space + newline seen in test cases
        }
    }

    // Memory Cleanup
    for (int i = 0; i < subset_count; i++) {
        free(found_subsets[i].elements);
    }
    free(found_subsets);
    free(current_subset);
    free(arr);

    return 0;
}

