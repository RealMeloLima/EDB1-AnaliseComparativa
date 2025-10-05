#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    long long comparacoes;
    long long trocas;
} Metricas;

typedef struct {
    const char* nome;
    void (*funcao)(int[], int, Metricas*);
} Algoritmo;

void swap_s(int *a, int *b, Metricas *m);

void bubbleSort_s(int arr[], int n, Metricas *m);
void insertionSort_s(int arr[], int n, Metricas *m);
void selectionSort_s(int arr[], int n, Metricas *m);
void mergeSort_s(int arr[], int n, Metricas *m);
void quickSort_s(int arr[], int n, Metricas *m);

void gerarAleatorio(int arr[], int n);
void gerarInversamenteOrdenado(int arr[], int n);
void gerarQuaseOrdenado(int arr[], int n);

int* copiarArray(int arr[], int n);

#endif