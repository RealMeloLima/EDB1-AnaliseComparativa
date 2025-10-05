#include "sort_utils.h"

int partition(int arr[], int low, int high, Metricas *m) {
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (m != NULL) m->comparacoes++;
        if (arr[j] <= pivot) {
            i++;
            swap_s(&arr[i], &arr[j], m);
        }
    }
    swap_s(&arr[i + 1], &arr[high], m);
    return (i + 1);
}

void quickSort_recursive(int arr[], int low, int high, Metricas *m) {
    if (low < high) {
        int pi = partition(arr, low, high, m);

        quickSort_recursive(arr, low, pi - 1, m);
        quickSort_recursive(arr, pi + 1, high, m);
    }
}

void quickSort_s(int arr[], int n, Metricas *m) {
    quickSort_recursive(arr, 0, n - 1, m);
}