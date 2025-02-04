/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_leap_year(char *ano) {
    int ultimos_dois_digitos = (ano[strlen(ano) - 2] - '0') * 10 + (ano[strlen(ano) - 1] - '0');
    int ultimos_quatro_digitos = (ano[strlen(ano) - 4] - '0') * 1000 + 
                           (ano[strlen(ano) - 3] - '0') * 100 + 
                           (ano[strlen(ano) - 2] - '0') * 10 + 
                           (ano[strlen(ano) - 1] - '0');

    if ((ultimos_dois_digitos % 4 == 0 && ultimos_dois_digitos != 0) || (ultimos_quatro_digitos % 400 == 0)) {
        return 1;
    }
    return 0;
}

int is_huluculu(char *ano) {
    int soma = 0;
    for (int i = 0; i < strlen(ano); i++) {
        soma = (soma * 10 + (ano[i] - '0')) % 15;
    }
    return soma == 0;
}

int is_bulukulu(char *ano) {
    if (!is_leap_year(ano)) {
        return 0;
    }
    int soma = 0;
    for (int i = 0; i < strlen(ano); i++) {
        soma = (soma * 10 + (ano[i] - '0')) % 55;
    }
    return soma == 0;
}

int main() {
    char ano[1001];
    int first_case = 1;

    while (scanf("%s", ano) != EOF) {
        if (!first_case) {
            printf("\n");
        }
        first_case = 0;

        int leap = is_leap_year(ano);
        int huluculu = is_huluculu(ano);
        int bulukulu = is_bulukulu(ano);

        if (leap) {
            printf("This is leap year.\n");
        }
        if (huluculu) {
            printf("This is huluculu festival year.\n");
        }
        if (bulukulu) {
            printf("This is bulukulu festival year.\n");
        }
        if (!leap && !huluculu && !bulukulu) {
            printf("This is an ordinary year.\n");
        }
    }

    return 0;
}
