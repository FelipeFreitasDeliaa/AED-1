/* Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int testes;
    scanf("%d", &testes);

    for (int i = 0; i < testes; i++) {
        int estudantes;
        scanf("%d", &estudantes);

        int* estudante = malloc(estudantes * sizeof(int));

        int soma_nota = 0;
        for (int j = 0; j < estudantes; j++) {
            scanf("%d", &estudante[j]);
            soma_nota += estudante[j];
        }

        int media = soma_nota / estudantes;
        
        int acima_da_media = 0;
        for (int k = 0; k < estudantes; k++) {
            if (estudante[k] > media) {
                acima_da_media++;
            }
        }

        float porcentagem = (float)acima_da_media / estudantes * 100;
        printf("%.3f%%\n", porcentagem);

        free(estudante);
    }

    return 0;
}
