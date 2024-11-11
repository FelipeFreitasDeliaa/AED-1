#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para ler uma lista de amigos

char **ler_lista_amigos(int *quantidade) { //essa fução retorna um ponteiro de ponteiro

    char nome[10];
    char **lista = NULL; //inicialmente, não está apontando para nenhum endereço
    *quantidade = 0;

    while (nome[0] != '\n'){ //Verifica se o usuário apenas pressionou enter (indicando que acabou de escrever a lista)
        fgets(nome, sizeof(nome), stdin);

        nome[strcspn(nome, "\n")] = '\0';  // Remove o caractere '\n' do final da string

        if (nome[0] == '\0') break; // Para caso o usuário pressione apenas Enter

        lista = realloc(lista, (*quantidade + 1) * sizeof (char *));    /* reajusta o tamanho da memória que foi alocada previamente
                                                                        aumentando o tamanho da lista para acomodar o próximo nome.
                                                                        Explicação: Como lista é um ponteiro do tipo char, é necessário
                                                                        alocar mais um espaço tipo char * para que lista tenha um novo
                                                                        ponteiro adicional */

        lista[*quantidade] = malloc((strlen(nome) + 1) * sizeof(char)); /* Aloca a quantidade exata de memória necessária para armazenar
                                                                        o novo nome, incluindo o caractere de terminação '\0' */

        strcpy(lista[*quantidade], nome);  // Copia o nome para a lista
        (*quantidade)++;   //adiciona +1 ao valor de quantidade
    }

    return lista;
}

// Função para encontrar o índice de um amigo na lista
int encontrar_amigo(char **lista, int quantidade, char *nome) {

    int i;

    for (i = 0; i < quantidade; i++) {
        if (strcmp(lista[i], nome) == 0) { /*comparando duas strings, quando elas são iguais a função
                                            retorna 0*/
            return i; //retorna a posição em que as duas strings são iguais
        }
    }
}


char **inserir_amigos(char **lista_atual, int *quantidade_atual, char **lista_novos, int quantidade_novos, int posicao) { /*Função para inserir a lista de
                                                                                                                            amigos novos na posição correta*/

    lista_atual = realloc(lista_atual, (*quantidade_atual + quantidade_novos) * sizeof(char *)); // Realoca a lista atual para comportar os novos amigos

    // Move os amigos atuais para dar espaço aos novos amigos, caso a posição seja antes do fim
    if (posicao < *quantidade_atual) {
        for (int i = *quantidade_atual - 1; i >= posicao; i--) {
            lista_atual[i + quantidade_novos] = lista_atual[i];
        }
    }

    // Copia os amigos novos para a lista atual na posição correta
    for (int i = 0; i < quantidade_novos; i++) {
        lista_atual[posicao + i] = lista_novos[i];
    }

    *quantidade_atual += quantidade_novos;

    return lista_atual;
}

int main() {

    int quantidade_atual = 0, quantidade_novos = 0;
    char **lista_atual = ler_lista_amigos(&quantidade_atual);

    // Limpar o buffer de entrada após ler a lista de amigos atuais
    while (getchar() != '\n');

    char **lista_novos = ler_lista_amigos(&quantidade_novos);

    // Limpar o buffer de entrada após ler a lista de amigos novos
    while (getchar() != '\n');

    char nome_indicado[10];

    fgets(nome_indicado, sizeof(nome_indicado), stdin); //função que recebe o nome digitado pelo usuário
    nome_indicado[strcspn(nome_indicado, "\n")] = '\0'; // Remove o '\n'

    int posicao;

    if (strcmp(nome_indicado, "nao") == 0) {
        posicao = quantidade_atual; // Insere a lista atual no final da lista antiga
    } else {
        posicao = encontrar_amigo(lista_atual, quantidade_atual, nome_indicado);
    }

    //Insere os amigos novos na posição apropriada
    lista_atual = inserir_amigos(lista_atual, &quantidade_atual, lista_novos, quantidade_novos, posicao);

    // Exibe a lista final de amigos
    for (int i = 0; i < quantidade_atual; i++) {
        printf("%s ", lista_atual[i]);
        free(lista_atual[i]); // Libera a memória de cada nome
    }

    free(lista_atual); // Libera a memória da lista atual
    free(lista_novos); // Libera a memória da lista de novos amigos (pois o conteúdo já foi movido)

    printf ("\n");

    return 0;
