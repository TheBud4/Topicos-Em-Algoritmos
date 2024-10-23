#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// TAD Gerador de arquivos
#include "./TAD_GeradorDeArquivos.h"

// Gerar arquivos
#include "./OP/Arquivos/GerarArquivoOrdenado.h"
#include "./OP/Arquivos/GerarArquivoInvertido.h"
#include "./OP/Arquivos/GerarArquivoDesordenado.h"

// Gerar benchmarks
#include "./OP/Algoritmos/GerarBenchmarkInsertionSort.h"
#include "./OP/Algoritmos/GerarBenchmarkBubbleSort.h"
#include "./OP/Algoritmos/GerarBenchmarkShellSort.h"
#include "./OP/Algoritmos/GerarBenchmarkSelectionSort.h"
#include "./OP/Algoritmos/GerarBenchmarkQuickSort.h"
#include "./OP/Algoritmos/GerarBenchmarkMergeSort.h"
#include "./OP/Algoritmos/GerarBenchmarkHeapSort.h"
#include "./OP/Algoritmos/GerarBenchmarkRadixSort.h"