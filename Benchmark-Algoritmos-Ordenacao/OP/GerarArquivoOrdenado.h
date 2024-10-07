#ifndef GERAR_ARQUIVO_ORDENADO_H
#define GERAR_ARQUIVO_ORDENADO_H

void gerarArquivoOrdenado(int tam) {
  FILE *ordenado;
  char nomeArquivo[100];

  sprintf(nomeArquivo, "ordenado_tam:%d.txt", tam);
  ordenado = fopen(nomeArquivo, "w");
  for (int i = 0; i <= tam; i++) {
    fprintf(ordenado, "%d\n", i);
  }
  fclose(ordenado);
  printf("Arquivo ordenado criado com sucesso!\n");
}

#endif  // !GERAR_ARQUIVO_ORDENADO_H