#include "tadVetor.h"

int main(int argc, char const *argv[]) {
    Vetor *vet, *clone;
    int i = 0;
    char s[100];


    // vet_criar =======================================================
    vet = vet_criar(10);

    vet_imprimir(vet);
    printf("Tamanho do vetor: %d \n", vet->tamVetor);
    printf("Quantidade de elementos: %d \n", vet->qtdeElementos);
    puts("\n");

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 30));
    vet_imprimir(vet);

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 10));
    vet_imprimir(vet);

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 20));
    vet_imprimir(vet);

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 30));
    vet_imprimir(vet);

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 10));
    vet_imprimir(vet);

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 20));
    vet_imprimir(vet);

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 30));
    vet_imprimir(vet);

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 10));
    vet_imprimir(vet);

    // vet_inserirFim ==================================================
    printf("Resultado vet_inserirFim: %d \n", vet_inserirFim(vet, 20));
    vet_imprimir(vet);

    // vet_inserir ======================================================
    printf("Resultado vet_inserir: %d\n", vet_inserir(vet, 78, -2));
    vet_imprimir(vet);

    // vet_inserir ======================================================
    printf("Resultado vet_substituir: %d\n", vet_substituir(vet, -2, 19));
    vet_imprimir(vet);

    // vet_removerPosicao ======================================================
    printf("Resultado vet_removerPosicao: %d\n", vet_removerPosicao(vet, -2, &i));
    printf("Valor removido: %d\n", i);
    vet_imprimir(vet);

    // vet_removerElemento ======================================================
    printf("Posição do elemento removido: %d\n", vet_removerElemento(vet, 30));
    vet_imprimir(vet);

    // vet_tamanho ======================================================
    printf("Quantidade de elementos: %d\n", vet_tamanho(vet));
    vet_imprimir(vet);

    // vet_elemento ======================================================
    printf("Resultado vet_elemento: %d\n", vet_elemento(vet, 9, &i));
    printf("Valor do elemento: %d\n", i);
    vet_imprimir(vet);

    // vet_posicao ======================================================
    printf("Resultado vet_posicao: %d\n", vet_posicao(vet, 45));
    vet_imprimir(vet);

    // vet_toString ======================================================
    printf("Resultado vet_toString: %d\n", vet_toString(vet, s));
    printf("Array to string: %s\n\n", s);

    // // verifica_diminui ======================================================
    // verifica_diminui(vet);
    // vet_imprimir(vet);

    // vet_clone ======================================================
    // clone = vet_clone(vet);
    // printf("Clone: ");
    // vet_imprimir(clone);

    // vet_ordenarBuble ======================================================
    // vet_ordenarBuble(clone);
    // printf("vet_ordenarBuble: "); vet_imprimir(clone);

    // vet_ordenarBuble ======================================================
    // vet_ordenarInsertion(clone);
    // printf("vet_ordenarInsertion: "); vet_imprimir(clone);

    // vet_buscaBinaria ======================================================
    // printf("vet_ordenarInsertion: %d\n", vet_buscaBinaria(clone, 0));

    // vet_importar ======================================================
    // Vetor* vet_file = vet_importar("teste.txt");
    // vet_imprimir(vet_file);

    // vet_exportar ======================================================
    // vet_exportar(vet_file, "teste_novo.txt");

    // vet_criarAleatorio ======================================================
    // Vetor* vet_aleatorio = vet_criarAleatorio(10);
    // vet_imprimir(vet_aleatorio);

    // vet_criarAscendente ======================================================
    // Vetor* vet_ascendente = vet_criarAscendente(10);
    // vet_imprimir(vet_ascendente);

    // vet_criarDescendente ======================================================
    // Vetor* vet_descendente = vet_criarDescendente(10);
    // vet_imprimir(vet_descendente);

    // vet_criarAscendenteParcial ======================================================
    Vetor* vet_parcial = vet_criarAscendenteParcial(10, 50);
    vet_imprimir(vet_parcial);

    // vet_destruir ======================================================
    vet_destruir(vet);


    return 0;
}
