/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>

int main(){
    int testes;
    float quantidade;
    int dias;
    scanf ("%d", &testes);
    getchar ();

    for (int i = 0; i < testes; i++){
        dias = 0;
        scanf ("%f", &quantidade);
        getchar();

        while (quantidade > 1.00){
            dias++;
            quantidade = quantidade/2;
        }
        printf ("%d dias\n", dias);
    }

    return 0;
}
