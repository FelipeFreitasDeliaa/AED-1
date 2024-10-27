/*Felipe Freitas D' Elia
            RA: 176284*/

#include <stdio.h>
#include <string.h>

int verifica_linhas(int matriz[9][9]); // Verifica se as linhas estão de acordo com a solução de um sudoku.
int verifica_colunas(int matriz[9][9]); // Verifica se as colunas estão de acordo com a resolução de um sudoku.
int verifica_celulas(int matriz[9][9]); // Verifica se as células estão de acordo com a resolução de um sudoku.

int main() {
    int num_matrizes;
    int matriz[9][9];
    int k;
    int linhas, colunas;

    scanf("%d", &num_matrizes); // Lerá o número de instâncias
    char resultados[num_matrizes][4]; // Matriz resultado. Armazena até num_matrizes de 3 caracteres, "SIM" ou "NAO".

    for (k = 0; k < num_matrizes; k++) { // Loop para cada instância
        for (linhas = 0; linhas < 9; linhas++) {
            for (colunas = 0; colunas < 9; colunas++) {
                scanf("%d", &matriz[linhas][colunas]); // Lerá a instância k
            }
        }
        if (verifica_linhas(matriz) == 0 || verifica_colunas(matriz) == 0 || verifica_celulas(matriz) == 0) { // Condição para a matriz ser solução de sudoku.
           strcpy (resultados[k], "NAO"); // Essa função copia "NAO" para o resultado da instancia k.
        } else {
            strcpy (resultados[k], "SIM"); // Essa função copia "SIM" para o resultado da instancia k.
        }
    }

    for (k = 0; k < num_matrizes; k++) {
        if (k == 0){
        printf("Instancia %d\n%s\n", k + 1, resultados[k]);
        } else printf ("\nInstancia %d\n%s\n", k + 1, resultados[k]);         
    }
    return 0;
}

int verifica_linhas(int matriz[9][9]) {
    int linhas;
    int colunas;
    int numero_da_linha;

    for (linhas = 0; linhas < 9; linhas++) {
        int ocorrencias[10] = {0};  // Vetor para contar ocorrências dos números 1 a 9
        for (colunas = 0; colunas < 9; colunas++) {
            numero_da_linha = matriz[linhas][colunas];
            if (numero_da_linha < 1 || numero_da_linha > 9 || ocorrencias[numero_da_linha] > 0) { // Condições para que a linha seja válida para a solução de um sudoku.
                return 0;
            }
            ocorrencias[numero_da_linha]++; // Isso garante que um numero da linha já foi lido.
        }
    }
    return 1;
}

int verifica_colunas(int matriz[9][9]) {
    int colunas;
    int linhas;
    int numero_da_coluna;

    for (colunas = 0; colunas < 9; colunas++) {
        int ocorrencias[10] = {0};  // Vetor para contar ocorrências dos números 1 a 9
        for (linhas = 0; linhas < 9; linhas++) {
            numero_da_coluna = matriz[linhas][colunas];
            if (numero_da_coluna < 1 || numero_da_coluna > 9 || ocorrencias[numero_da_coluna] > 0) { // Condições para que a coluna seja válida para a solução de um sudoku.
                return 0;
            }
            ocorrencias[numero_da_coluna]++; // Isso garante que um numero da coluna já foi lido.
        }
    }
    return 1;
}

int verifica_celulas(int matriz[9][9]) {
    int linha_inicial;
    int coluna_inicial;
    int linhas;
    int colunas;
    int numero_da_celula;

    for (linha_inicial = 0; linha_inicial < 9; linha_inicial += 3) {                                        /* Quando as 3 células de cada coluna de células é lida, 
                                                                                                             passar para a linha de células abaixo*/
      
        for (coluna_inicial = 0; coluna_inicial < 9; coluna_inicial += 3) {                                 /*Cada vez que o numero de linhas e colunas de uma célula específica é lida, 
                                                                                                            iniciar um novo ciclo para as linhas e colunas da próxima célula à direita*/
            int ocorrencias[10] = {0};  // Vetor para contar ocorrências dos números 1 a 9
            for (linhas = 0; linhas < 3; linhas++) {
                for (colunas = 0; colunas < 3; colunas++) {
                    numero_da_celula = matriz[linha_inicial + linhas][coluna_inicial + colunas];
                    if (numero_da_celula < 1 || numero_da_celula > 9 || ocorrencias[numero_da_celula] > 0) { // Condições para que a célula seja válida para a solução de um sudoku.
                        return 0;
                    }
                    ocorrencias[numero_da_celula]++; // Isso garante que um numero da célula já foi lido.
                }
            }
        }
    }
    return 1;
}
