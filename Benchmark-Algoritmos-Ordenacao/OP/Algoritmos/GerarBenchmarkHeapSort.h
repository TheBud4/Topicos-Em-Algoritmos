#ifndef GERAR_BENCHMARK_HEAP_SORT_H
#define GERAR_BENCHMARK_HEAP_SORT_H

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}


void gerarBenchmarkHeapSort(char *nomeArquivo) {
  FILE *arquivoEntrada, *arquivoSaida;
  int *arr, n = 0;
  int valor;
  printf("Gerando Benchmark Heap Sort...\n");

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
  heapSort(arr, n);
  clock_t end = clock();

  double tempoExecucao = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Tempo de execução do Heap Sort: %f segundos\n", tempoExecucao);

  char caminhoSaida[150] = "../output/";
  strcat(caminhoSaida, nomeArquivo);

  char *ponto = strrchr(caminhoSaida, '.');

  if (ponto != NULL) {
    char sufixo[100] = "_sortedByHeapSort";
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

  printf("Benchmark Heap Sort criado com sucesso! Arquivo salvo em: %s\n",
         caminhoSaida);
}

#endif  // GERAR_BENCHMARK_HEAP_SORT_H
