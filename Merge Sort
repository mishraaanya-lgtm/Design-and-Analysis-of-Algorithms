#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int temp[], int low, int mid, int high) {
    int i = low;       // Initial index of first subarray
    int j = mid + 1;   // Initial index of second subarray
    int k = low;       // Initial index of merged array

    // Copy data to temporary array while comparing elements
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back into the original array
    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

// Function to recursively divide the array into subarrays
void mergeSort(int arr[], int temp[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Sort first and second halves
        mergeSort(arr, temp, low, mid);
        mergeSort(arr, temp, mid + 1, high);

        // Merge the sorted halves
        merge(arr, temp, low, mid, high);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Use dynamic allocation for large input size constraints (up to 10^6)
    int* arr = (int*)malloc(n * sizeof(int));
    int* temp = (int*)malloc(n * sizeof(int));

    if (arr == NULL || temp == NULL) {
        return 0; // Memory allocation failed
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            free(temp);
            return 0;
        }
    }

    // Perform Merge Sort
    mergeSort(arr, temp, 0, n - 1);

    // Print the sorted array with trailing space formatting
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Clean up allocated memory
    free(arr);
    free(temp);

    return 0;
}


    
