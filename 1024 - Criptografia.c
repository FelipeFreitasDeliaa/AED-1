#include <stdio.h>
#include <string.h>
#include <ctype.h>

void primeiro_processamento(char* palavra, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(palavra[i])) {
            palavra[i] += 3;
        }
    }
}

void segundo_processamento(char* palavra, int tamanho) {
    for (int i = 0, j = tamanho - 1; i < j; i++, j--) {
        char temp = palavra[i];
        palavra[i] = palavra[j];
        palavra[j] = temp;
    }
}

void terceiro_processamento(char* palavra, int tamanho) {
    for (int i = tamanho / 2; i < tamanho; i++) {
        palavra[i] -= 1;
    }
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);
    getchar();

    char mensagem[1002];

    for (int i = 0; i < casos_teste; i++) {
        if (fgets(mensagem, sizeof(mensagem), stdin) != NULL) {
            int tamanho = strlen(mensagem);

            if (mensagem[tamanho - 1] == '\n') {
                mensagem[tamanho - 1] = '\0';
                tamanho--;
            }

            primeiro_processamento(mensagem, tamanho);
            segundo_processamento(mensagem, tamanho);
            terceiro_processamento(mensagem, tamanho);

            printf("%s\n", mensagem);
        }
    }

    return 0;
}
