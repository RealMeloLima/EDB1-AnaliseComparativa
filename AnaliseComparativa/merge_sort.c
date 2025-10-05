#include "sort_utils.h"

void merge(int arr[], int l, int mid, int r, Metricas *m) {
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // Usa 'mid'

    i = 0; j = 0; k = l; 
    while (i < n1 && j < n2) {
        if (m != NULL) m->comparacoes++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        if (m != NULL) m->trocas++; 
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        if (m != NULL) m->trocas++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        if (m != NULL) m->trocas++;
    }
    
    free(L);
    free(R);
}

void mergeSort_recursive(int arr[], int l, int r, Metricas *m) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergeSort_recursive(arr, l, mid, m);
        mergeSort_recursive(arr, mid + 1, r, m);

        merge(arr, l, mid, r, m);
    }
}

void mergeSort_s(int arr[], int n, Metricas *m) {
    mergeSort_recursive(arr, 0, n - 1, m);
}