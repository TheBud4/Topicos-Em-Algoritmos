#ifndef TAD_GERADOR_DE_ARQUIVOS_H
#define TAD_GERADOR_DE_ARQUIVOS_H

    // Gerar arquivos
    void gerarArquivoDesordenado      (int tam);
    void gerarArquivoOrdenado         (int tam);
    void gerarArquivoInvertido        (int tam);

    // Gerar benchmarks
    void gerarBenchmarkHeapSort       (char *nomeArquivo);
    void gerarBenchmarkInsertionSort  (char *nomeArquivo);
    void gerarBenchmarkShellSort      (char *nomeArquivo);
    void gerarBenchmarkSelectionSort  (char *nomeArquivo);
    void gerarBenchmarkQuickSort      (char *nomeArquivo);
    void gerarBenchmarkMergeSort      (char *nomeArquivo);
    void gerarBenchmarkHeapSort       (char *nomeArquivo);
    void gerarBenchmarkRadixSort      (char *nomeArquivo);

#endif  // !TAD_GERADOR_DE_ARQUIVOS_H