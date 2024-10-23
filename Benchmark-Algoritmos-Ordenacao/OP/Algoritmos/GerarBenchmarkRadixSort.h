#ifndef GERAR_BENCHMARK_RADIX_SORT_H
#define GERAR_BENCHMARK_RADIX_SORT_H

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void gerarBenchmarkRadixSort(char *nomeArquivo) {
    FILE *arquivoEntrada, *arquivoSaida;
    int *arr, n = 0;
    int valor;
    printf("Gerando Benchmark Radix Sort...\n");

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
    radixSort(arr, n);
    clock_t end = clock();

    double tempoExecucao = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Radix Sort: %f segundos\n", tempoExecucao);

    char caminhoSaida[150] = "../output/";
    strcat(caminhoSaida, nomeArquivo);

    char *ponto = strrchr(caminhoSaida, '.');

    if (ponto != NULL) {
        char sufixo[100] = "_sortedByRadixSort";
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

    printf("Benchmark Radix Sort criado com sucesso! Arquivo salvo em: %s\n", caminhoSaida);
}

#endif  // GERAR_BENCHMARK_RADIX_SORT_H