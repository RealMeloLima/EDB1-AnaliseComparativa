#include "sort_utils.h"

void selectionSort_s(int arr[], int n, Metricas *m) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (m != NULL) m->comparacoes++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swap_s(&arr[min_idx], &arr[i], m);
        }
    }
}