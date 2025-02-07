/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

struct tempo {
    int horas, minutos, segundos;
};

int converter_segundos(struct tempo t) {
    return t.horas * 3600 + t.minutos * 60 + t.segundos;
}

int main() {
    char tempo_str[9]; 
    int velocidade = 0;  
    int tempo_anterior = 0; 
    double distancia = 0.0;

    while (scanf("%s", tempo_str) != EOF) {
        struct tempo t;
        sscanf(tempo_str, "%d:%d:%d", &t.horas, &t.minutos, &t.segundos);
        int tempo_atual = converter_segundos(t);

        distancia += (tempo_atual - tempo_anterior) * (velocidade / 3600.0);
        tempo_anterior = tempo_atual;

        char c = getchar();
        if (c == ' ') { 
            scanf("%d", &velocidade);
        } else {
            printf("%s %.2f km\n", tempo_str, distancia);
        }
    }

    return 0;
}
