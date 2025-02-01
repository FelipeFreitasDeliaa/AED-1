/*Felipe Freitas D' Elia 
  RA: 176284*/

#include <stdio.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int testes;
    scanf("%d", &testes);

    for (int i = 0; i < testes; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);

        int resultado = mdc(num1, num2);

        printf("%d\n", resultado);
    }

    return 0;
}
