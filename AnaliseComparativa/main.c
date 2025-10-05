#include "sort_utils.h"

void rodarTeste(const char* nome_dataset, int n_tamanho, void (*gerar_dados)(int[], int), Algoritmo alg) {
    
    int* base_array = (int*)malloc(n_tamanho * sizeof(int));
    if (base_array == NULL) {
        perror("Erro ao alocar array base");
        return;
    }
    
    gerar_dados(base_array, n_tamanho);
    
    int* array_para_teste = copiarArray(base_array, n_tamanho);
    Metricas resultado = {0, 0};

    clock_t start = clock();
    
    alg.funcao(array_para_teste, n_tamanho, &resultado);
    
    clock_t end = clock();

    long long tempo_ms = (long long)(((double)(end - start) / CLOCKS_PER_SEC) * 1000.0);

    printf("| %-15s | %-12s | %-6d | %-8lld | %-12lld | %-12lld |\n", 
           alg.nome, nome_dataset, n_tamanho, tempo_ms, resultado.comparacoes, resultado.trocas);

    free(base_array);
    free(array_para_teste);
}

int main() {
    
    int tamanhos[] = {1000, 5000, 10000, 25000}; 
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    void (*geradores[])(int[], int) = {
        gerarAleatorio, 
        gerarQuaseOrdenado, 
        gerarInversamenteOrdenado
    };
    const char* nomes_geradores[] = {
        "Aleatorio", 
        "Quase Ordenado", 
        "Inversamente Ordenado"
    };
    int num_geradores = sizeof(geradores) / sizeof(geradores[0]);

    Algoritmo algoritmos[] = {
        {"Bubble Sort", bubbleSort_s}, 
        {"Insertion Sort", insertionSort_s}, 
        {"Selection Sort", selectionSort_s}, 
        {"Merge Sort", mergeSort_s}, 
        {"Quick Sort", quickSort_s}
    };
    int num_algoritmos = sizeof(algoritmos) / sizeof(algoritmos[0]);

    printf("--- Analise Comparativa de Algoritmos de Ordenacao ---\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-12s | %-6s | %-8s | %-12s | %-12s |\n", 
           "Algoritmo", "Dataset", "N", "Tempo(ms)", "Comparacoes", "Trocas");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < num_tamanhos; i++) {
        int N = tamanhos[i];
        
        for (int tipo = 0; tipo < num_geradores; tipo++) {
            
            for (int j = 0; j < num_algoritmos; j++) {
                rodarTeste(nomes_geradores[tipo], N, geradores[tipo], algoritmos[j]);
            }
        }
        printf("--------------------------------------------------------------------------------------------------------------\n");
    }
    
    printf("\nExecucao concluida. Os dados da tabela acima devem ser usados para as tabelas e graficos do relatorio.\n");
    
    return 0;
}