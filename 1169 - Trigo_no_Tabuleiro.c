/*Felipe Feritas D' Elia
  rA: 176284*/

#include <stdio.h>

int main() {
    int casos_teste;
    int casas_de_tabuleiro;
    unsigned long long int total;
    long long int gramas;
    long long int quilos;

    scanf("%d", &casos_teste);
    getchar();

    for (int i = 0; i < casos_teste; i++) {
        total = 0;

        scanf("%d", &casas_de_tabuleiro);
        getchar();

        for (int j = 0; j < casas_de_tabuleiro; j++) {
            total += (1ULL << j); 
        }

        gramas = total / 12;
        quilos = gramas / 1000;

        printf("%lld kg\n", quilos);
    }

    return 0;
}
