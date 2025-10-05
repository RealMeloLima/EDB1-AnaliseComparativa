#include "sort_utils.h"

void bubbleSort_s(int arr[], int n, Metricas *m) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (m != NULL) m->comparacoes++;
            if (arr[j] > arr[j + 1]) {
                swap_s(&arr[j], &arr[j + 1], m);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}