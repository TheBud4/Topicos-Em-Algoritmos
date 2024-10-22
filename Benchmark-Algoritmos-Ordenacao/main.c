#include <stdio.h>
#include <stdlib.h>

#include "./GeradorDeArquivos.h"

int main() {
  int tam, op;
  char nomeArquivo[100];

  while (op != 0) {
    printf("-----------------------------------------\n");
    printf("| Digite a sua opção:                   |\n");
    printf("-----------------------------------------\n");
    printf("|  0  - Sair                            |\n");
    printf("|  1  - Gerar arquivo ordenado          |\n");
    printf("|  2  - Gerar arquivo invertido         |\n");
    printf("|  3  - Gerar arquivo desordenado       |\n");
    printf("|  4  - Gerar Benchmark Bubble Sort     |\n");
    printf("|  5  - Gerar Benchmark Insertion Sort  |\n");
    printf("|  6  - Gerar Benchmark Selection Sort  |\n");
    printf("|  7  - Gerar Benchmark Shell Sort      |\n");
    printf("|  8  - Gerar Benchmark Quick Sort      |\n");
    printf("|  9  - Gerar Benchmark Merge Sort      |\n");
    printf("|  99 - Limpar tela                     |\n");
    printf("-----------------------------------------\n");
    scanf("%d", &op);

    switch (op) {
      case 1:
        printf("Digite o tamanho do arquivo: ");
        scanf("%d", &tam);
        gerarArquivoOrdenado(tam);
        break;
      case 2:
        printf("Digite o tamanho do arquivo: ");
        scanf("%d", &tam);
        gerarArquivoInvertido(tam);
        break;
      case 3:
        printf("Digite o tamanho do arquivo: ");
        scanf("%d", &tam);
        gerarArquivoDesordenado(tam);
        break;
      case 4:
        printf("Digite o arquivo a ser testado: ");
        scanf("%s", nomeArquivo);
        gerarBenchmarkBubbleSort(nomeArquivo);
        break;
      case 5:
        printf("Digite o arquivo a ser testado: ");
        scanf("%s", nomeArquivo);
        gerarBenchmarkInsertionSort(nomeArquivo);
        break;
      case 6:
        printf("Digite o arquivo a ser testado: ");
        scanf("%s", nomeArquivo);
        gerarBenchmarkSelectionSort(nomeArquivo);
        break;
      case 7:
        printf("Digite o arquivo a ser testado: ");
        scanf("%s", nomeArquivo);
        gerarBenchmarkShellSort(nomeArquivo);
        break;
      case 8:
        printf("Digite o arquivo a ser testado: ");
        scanf("%s", nomeArquivo);
        gerarBenchmarkQuickSort(nomeArquivo);
        break;
      case 9:
        printf("Digite o arquivo a ser testado: ");
        scanf("%s", nomeArquivo);
        gerarBenchmarkMergeSort(nomeArquivo);
        break;
      case 99:
        system("clear");
        break;
      case 0:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida\n");
        break;
    }
  }
}