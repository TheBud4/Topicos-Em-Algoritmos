#ifndef GERAR_BENCHMARK_BUBBLE_SORT_H
#define GERAR_BENCHMARK_BUBBLE_SORT_H

void bubbleSort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
void gerarBenchmarkBubbleSort(char *nomeArquivo) {
    FILE *arquivoEntrada, *arquivoSaida;
    int *arr, n = 0;
    int valor;
    printf("Gerando Benchmark Bubble Sort...\n");
    
    char caminhoEntrada[150] = "../output/";
    strcat(caminhoEntrada, nomeArquivo);

    arquivoEntrada = fopen(caminhoEntrada, "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada: %s\n", caminhoEntrada);
        return;
    }

    while (fscanf(arquivoEntrada, "%d", &valor) != EOF) {
        n++;
    }
    rewind(arquivoEntrada);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivoEntrada);
        return;
    }

    for (int i = 0; i < n; i++) {
        fscanf(arquivoEntrada, "%d", &arr[i]);
    }
    fclose(arquivoEntrada);

    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();

    double tempoExecucao = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Bubble Sort: %f segundos\n", tempoExecucao);

    char caminhoSaida[150] = "../output/";
    strcat(caminhoSaida, nomeArquivo);

    char *ponto = strrchr(caminhoSaida, '.');

    if (ponto != NULL) {
        char sufixo[100] = "_sortedByBubbleSort";
        strcat(sufixo, ponto);
        *ponto = '\0';
        strcat(caminhoSaida, sufixo);
    } else {
        strcat(caminhoSaida, "_sorted");
    }

    arquivoSaida = fopen(caminhoSaida, "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída: %s\n", caminhoSaida);
        free(arr);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivoSaida, "%d\n", arr[i]);
    }
    fclose(arquivoSaida);

    free(arr);

    printf("Benchmark Bubble Sort criado com sucesso! Arquivo salvo em: %s\n", caminhoSaida);
}

#endif  // GERAR_BENCHMARK_BUBBLE_SORT_H
