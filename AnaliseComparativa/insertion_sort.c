#include "sort_utils.h"

void insertionSort_s(int arr[], int n, Metricas *m) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            if (m != NULL) m->comparacoes++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                if (m != NULL) m->trocas++;
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}