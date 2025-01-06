/*Felipe Freitas D' Elia
            RA: 176284*/

#include <stdio.h>

int verifica_linhas(int matriz[9][9]); // Verifica se as linhas estão de acordo com a solução de um sudoku.
int verifica_colunas(int matriz[9][9]); // Verifica se as colunas estão de acordo com a resolução de um sudoku.
int verifica_celulas(int matriz[9][9]); // Verifica se as células estão de acordo com a resolução de um sudoku.

int main() {
    int num_matrizes;
    int matriz[9][9];
    int k, linhas, colunas;

    scanf("%d", &num_matrizes); // Lerá o número de instâncias

    for (k = 0; k < num_matrizes; k++) { // Loop para cada instância
        for (linhas = 0; linhas < 9; linhas++) {
            for (colunas = 0; colunas < 9; colunas++) {
                scanf("%d", &matriz[linhas][colunas]); // Lerá a instância k
            }
        }

        printf("Instancia %d\n", k + 1);
        if (verifica_linhas(matriz) == 0 || verifica_colunas(matriz) == 0 || verifica_celulas(matriz) == 0) {
            printf("NAO\n");
        } else {
            printf("SIM\n");
        }
        printf("\n"); // Linha em branco após cada instância
    }

    return 0;
}

int verifica_linhas(int matriz[9][9]) {
    int linhas, colunas, numero_da_linha;

    for (linhas = 0; linhas < 9; linhas++) {
        int ocorrencias[10] = {0};  // Vetor para contar ocorrências dos números 1 a 9
        for (colunas = 0; colunas < 9; colunas++) {
            numero_da_linha = matriz[linhas][colunas];
            if (numero_da_linha < 1 || numero_da_linha > 9 || ocorrencias[numero_da_linha] > 0) {
                return 0;
            }
            ocorrencias[numero_da_linha]++;
        }
    }
    return 1;
}

int verifica_colunas(int matriz[9][9]) {
    int colunas, linhas, numero_da_coluna;

    for (colunas = 0; colunas < 9; colunas++) {
        int ocorrencias[10] = {0};  // Vetor para contar ocorrências dos números 1 a 9
        for (linhas = 0; linhas < 9; linhas++) {
            numero_da_coluna = matriz[linhas][colunas];
            if (numero_da_coluna < 1 || numero_da_coluna > 9 || ocorrencias[numero_da_coluna] > 0) {
                return 0;
            }
            ocorrencias[numero_da_coluna]++;
        }
    }
    return 1;
}

int verifica_celulas(int matriz[9][9]) {
    int linha_inicial, coluna_inicial, linhas, colunas, numero_da_celula;

    for (linha_inicial = 0; linha_inicial < 9; linha_inicial += 3) {
        for (coluna_inicial = 0; coluna_inicial < 9; coluna_inicial += 3) {
            int ocorrencias[10] = {0};  // Vetor para contar ocorrências dos números 1 a 9
            for (linhas = 0; linhas < 3; linhas++) {
                for (colunas = 0; colunas < 3; colunas++) {
                    numero_da_celula = matriz[linha_inicial + linhas][coluna_inicial + colunas];
                    if (numero_da_celula < 1 || numero_da_celula > 9 || ocorrencias[numero_da_celula] > 0) {
                        return 0;
                    }
                    ocorrencias[numero_da_celula]++;
                }
            }
        }
    }
    return 1;
}
