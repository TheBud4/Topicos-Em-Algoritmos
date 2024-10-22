#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./TAD_GeradorDeArquivos.h"

#include "./OP/Arquivos/GerarArquivoOrdenado.h"
#include "./OP/Arquivos/GerarArquivoInvertido.h"
#include "./OP/Arquivos/GerarArquivoDesordenado.h"

#include "./OP/Algoritmos/GerarBenchmarkInsertionSort.h"
#include "./OP/Algoritmos/GerarBenchmarkBubbleSort.h"
#include "./OP/Algoritmos/GerarBenchmarkShellSort.h"
#include "./OP/Algoritmos/GerarBenchmarkSelectionSort.h"
#include "./OP/Algoritmos/GerarBenchmarkQuickSort.h"
#include "./OP/Algoritmos/GerarBenchmarkMergeSort.h"