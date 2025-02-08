/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 21

void corrigir_palavra(char palavra[]) {
    if (strlen(palavra) == 3) {
        if (strncmp(palavra, "OB", 2) == 0) {
            palavra[2] = 'I';
        } else if (strncmp(palavra, "UR", 2) == 0) {
            palavra[2] = 'I';
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char palavra[MAX_TAM];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", palavra);
        corrigir_palavra(palavra);
        printf("%s", palavra);
        if (i < n - 1) {
            printf(" ");
        }
    }
    
    printf("\n");
    return 0;
}
