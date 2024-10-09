#ifndef GERAR_ARQUIVO_INVERTIDO_H
#define GERAR_ARQUIVO_INVERTIDO_H

void gerarArquivoInvertido(int tam) {
  FILE *invertido;
  char nomeArquivo[100];

  sprintf(nomeArquivo, "invertido_tam:%d.txt", tam);
  invertido = fopen(nomeArquivo, "w");
  for (int i = 0; i <= tam; i++) {
    fprintf(invertido, "%d\n", tam - i);
  }
  fclose(invertido);

  printf("Arquivo invertido criado com sucesso!\n");
}

#endif  // !GERAR_ARQUIVO_INVERTIDO_H

