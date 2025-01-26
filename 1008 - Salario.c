/*Felipe Freitas D' Elia
 RA: 176284*/

#include <stdio.h>

int main() {
    int numero, horas;
    float salario, total;

    scanf("%d", &numero);
    scanf("%d", &horas);
    scanf("%f", &salario);

    total = horas * salario;

    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2f\n", total);

    return 0;
} 
