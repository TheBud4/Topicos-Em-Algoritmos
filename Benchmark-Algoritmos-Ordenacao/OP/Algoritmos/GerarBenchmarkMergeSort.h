#ifndef GERAR_BENCHMARK_MERGE_SORT_H
#define GERAR_BENCHMARK_MERGE_SORT_H

void mergeSort(int arr[], int n) {
    printf("Not implemented yet.\n");
}

void gerarBenchmarkMergeSort(char *nomeArquivo) {
  FILE *arquivoEntrada, *arquivoSaida;
  int *arr, n = 0;
  int valor;

  printf("Gerando Benchmark Merge Sort...\n");

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
  mergeSort(arr, n);
  clock_t end = clock();

  double tempoExecucao = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Tempo de execução do Merge Sort: %f segundos\n", tempoExecucao);

  char caminhoSaida[150] = "../output/";
  strcat(caminhoSaida, nomeArquivo);

  char *ponto = strrchr(caminhoSaida, '.');

  if (ponto != NULL) {
    char sufixo[100] = "_sortedByMergeSort";
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

  printf("Benchmark Merge Sort criado com sucesso! Arquivo salvo em: %s\n",
         caminhoSaida);
}

#endif  // GERAR_BENCHMARK_MERGE_SORT_H
