## Objetivos do Trabalho

O objetivo principal deste trabalho é realizar uma **análise comparativa de desempenho** entre cinco algoritmos fundamentais de ordenação: **Bubble Sort, Insertion Sort, Selection Sort, Merge Sort e Quick Sort**.

A análise é baseada tanto em suas **complexidades teóricas** quanto em **evidências experimentais** obtidas através de medições rigorosas de **tempo de execução**, **número de comparações** e **número de trocas** de elementos.

O estudo visa validar a correspondência entre a teoria da complexidade e o desempenho prático, fornecendo um *ranking* de eficiência e **recomendações de uso** para diferentes cenários de entrada de dados.

## 📁 Estrutura do Projeto

O projeto segue uma arquitetura modular em C para facilitar a organização das implementações e a medição isolada de métricas.

| Arquivo | Descrição |
| :--- | :--- |
| `main.c` | **Ponto de Entrada.** Contém a função `main()`, orquestra a geração de dados, executa os testes e imprime a tabela de resultados brutos. |
| `sort_utils.h`/`sort_utils.c` | Utilitários. Define estruturas de métricas, a função de `swap_s` (com contador) e as funções de geração de dados. |
| `bubble_sort.c` | Implementação do Bubble Sort, com contadores de `comparacoes` e `trocas`. |
| `insertion_sort.c` | Implementação do Insertion Sort, com contadores. |
| `selection_sort.c` | Implementação do Selection Sort, com contadores. |
| `merge_sort.c` | Implementação do Merge Sort, com contadores. |
| `quick_sort.c` | Implementação do Quick Sort, com contadores. |
| `analise_ordenacao` | Implementação do Quick Sort, com contadores. |

## ⚙️ Como Compilar e Executar

Para replicar os resultados, você precisará de um compilador C (como GCC) em seu sistema operacional (Linux, macOS, ou WSL/MinGW no Windows).

### 1. Compilação do Código

Use o seguinte comando no terminal para compilar todos os arquivos `.c` e criar o executável `analise_ordenacao`:

```bash
gcc main.c sort_utils.c bubble_sort.c insertion_sort.c selection_sort.c merge_sort.c quick_sort.c -o analise_ordenacao

Após a compilação bem-sucedida, execute o programa. O código irá automaticamente rodar todos os algoritmos em todos os tamanhos de vetor (1.000, 5.000, 10.000, 25.000) e em todos os tipos de *dataset* (Aleatório, Quase Ordenado, Inversamente Ordenado).

```
```bash
./analise_ordenacao
```
