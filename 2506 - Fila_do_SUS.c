/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

struct tempo {
    int h;
    int m; 
};

struct tempo contador_tempo(struct tempo horario, int adicionar) {
    int total_minutos = horario.h * 60 + horario.m + adicionar;
    horario.h = total_minutos / 60;
    horario.m = total_minutos % 60;
    return horario;
}

struct tempo horario_critico(int hora_chegada, int minuto_chegada, int espera) {
    struct tempo critico;
    int total_minutos = hora_chegada * 60 + minuto_chegada + espera;
    critico.h = total_minutos / 60;
    critico.m = total_minutos % 60;
    return critico;
}

int comparar(struct tempo atual, struct tempo limite) {
    return (atual.h > limite.h || (atual.h == limite.h && atual.m > limite.m));
}

struct tempo ajustar_proximo_horario(struct tempo horario) {
    if (horario.m > 0 && horario.m < 30) {
        horario.m = 30;
    } else if (horario.m > 30) {
        horario.h += 1;
        horario.m = 0;
    }
    return horario;
}

int main() {
    int numero_de_pacientes;

    while (scanf("%d", &numero_de_pacientes) == 1) {
        if (numero_de_pacientes == 0) {
            printf("0\n");
            continue;
        }

        struct tempo hora_atual = {7, 0}; 
        int qtd_criticos = 0;
        int tempo_por_consulta = 30;

        for (int i = 0; i < numero_de_pacientes; i++) {
            int H, M, C;
            scanf("%d %d %d", &H, &M, &C);

            struct tempo chegada = {H, M};
            struct tempo limite_critico = horario_critico(H, M, C);

            if (comparar(chegada, hora_atual)) {
                hora_atual = chegada;
            }

            hora_atual = ajustar_proximo_horario(hora_atual);

            if (comparar(hora_atual, limite_critico)) {
                qtd_criticos++;
            }

            hora_atual = contador_tempo(hora_atual, tempo_por_consulta);
        }

        printf("%d\n", qtd_criticos);
    }

    return 0;
}
