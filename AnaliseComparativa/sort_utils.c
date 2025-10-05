#include "sort_utils.h"

void swap_s(int *a, int *b, Metricas *m) {
    int temp = *a;
    *a = *b;
    *b = temp;
    if (m != NULL) {
        m->trocas++;
    }
}

int* copiarArray(int arr[], int n) {
    int* nova_arr = (int*)malloc(n * sizeof(int));
    if (nova_arr == NULL) {
        perror("Erro de alocacao de memoria");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        nova_arr[i] = arr[i];
    }
    return nova_arr;
}

void gerarAleatorio(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 10); 
    }
}
void gerarInversamenteOrdenado(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i; 
    }
}
void gerarQuaseOrdenado(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    
    int desordenar_count = n / 10;
    srand(time(NULL));
    for (int k = 0; k < desordenar_count; k++) {
        int i = rand() % n;
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}