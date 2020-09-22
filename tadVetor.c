#include "tadVetor.h"

Vetor* vet_criar(int tamVetor){
    //Aloca o vetor
    Vetor* newVet = malloc(sizeof(Vetor));

    // Aloca o array dentro do vetor
    newVet->array = malloc(tamVetor * sizeof(TipoElemento));

    //Atribui o tamanho do vetor a variavel da struct
    newVet->tamVetor = tamVetor;
    newVet->qtdeElementos = 0;

    return newVet;
};

Boolean vet_inserirFim(Vetor* v, TipoElemento elemento){
    if(v->tamVetor == v->qtdeElementos){
        verifica_aumenta(v);
    }
    if(v->qtdeElementos < v->tamVetor){
        if(v->array[v->tamVetor-1] != 0){
            puts("teste");
            shiftLeft(v, v->tamVetor-1);
        }
        v->array[v->tamVetor-1] = elemento;
        v->qtdeElementos++;
        return true;
    }
};

Boolean vet_inserir(Vetor* v, TipoElemento elemento, int posicao){
    verifica_aumenta(v);
    posicao = negativeToPositive(v, posicao);

    if(posicao < v->tamVetor){
        if(v->array[posicao] == 0){
            v->array[posicao] = elemento;
            v->qtdeElementos++;
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
};

Boolean vet_substituir(Vetor* v, int posicao, TipoElemento novoElemento){
    posicao = negativeToPositive(v, posicao);

    if(posicao < v->tamVetor){
        if(v->array[posicao] == 0){
            v->array[posicao] = novoElemento;
            v->qtdeElementos++;
        }else{
            v->array[posicao] = novoElemento;
        }
        return true;
    }else{
        return false;
    }
};

Boolean vet_removerPosicao(Vetor* v, int posicao, TipoElemento* endereco){
    posicao = negativeToPositive(v, posicao);

    if(posicao < v->tamVetor){
        *endereco = v->array[posicao];
        v->array[posicao] = 0;
        v->qtdeElementos--;
        verifica_diminui(v);
        return true;
    }else{
        return false;
    }
};

int vet_removerElemento(Vetor* v, TipoElemento elemento){
    for (size_t i = 0; i < v->tamVetor; i++) {
        if(v->array[i] == elemento){
            v->array[i] = 0;
            v->qtdeElementos--;
            verifica_diminui(v);
            return i;
        }
    }
    return -1;
};

int vet_tamanho(Vetor* v){
    return v->qtdeElementos;
};

Boolean vet_elemento(Vetor* v, int posicao, TipoElemento* saida){
    posicao = negativeToPositive(v, posicao);

    if(v->array[posicao] != 0){
        *saida = v->array[posicao];
        return true;
    }else{
        return false;
    }
};

int vet_posicao(Vetor* v, TipoElemento elemento){
    for (size_t i = 0; i < v->tamVetor; i++) {
        if(v->array[i] == elemento){
            return i;
        }
    }
    return -1;
};


void vet_imprimir(Vetor* v){
    printf("Array: ");
    for (size_t i = 0; i < v->tamVetor; i++) {
        printf("[%d]", v->array[i]);
    }
    puts("\n");
};

void vet_destruir(Vetor* v){
    free(v->array);
    free(v);
};

Boolean vet_toString(Vetor* v, char* enderecoString){
    if(v->array != NULL){
        strcat(enderecoString, "[");
        strcat(enderecoString, itoa(v->array[0], 10));
        for (size_t i = 1; i < v->tamVetor; i++) {
            strcat(enderecoString, ",");
            strcat(enderecoString, itoa(v->array[i], 10));
        }
        strcat(enderecoString, "]");
        return true;
    }else{
        return false;
    }
};

void verifica_aumenta(Vetor* v){
    if(v->tamVetor == v->qtdeElementos){
        v->array = realloc(v->array, v->tamVetor*2 * sizeof(v->tamVetor));
        v->tamVetor = v->tamVetor*2;
    }
};

void verifica_diminui(Vetor* v){
    if(v->tamVetor/2 >= v->qtdeElementos){
        vet_ordenarSelectionDesc(v);
        v->array = realloc(v->array, v->tamVetor/2 * sizeof(v->tamVetor));
        v->tamVetor = v->tamVetor/2;
    }
};

Vetor* vet_clone(Vetor* v){
    Vetor* vet = vet_criar(v->tamVetor);
    vet->qtdeElementos = v->qtdeElementos;
    for (size_t i = 0; i < v->tamVetor; i++) {
        vet->array[i] = v->array[i];
    }

    return vet;
};

void vet_ordenarBuble(Vetor* v){
    int aux = 0;
    for (int i = 1; i < v->tamVetor; i++) {
        for (int j = 0; j < v->tamVetor - 1; j++) {
            if (v->array[j] > v->array[j + 1]) {
                aux = v->array[j];
                v->array[j] = v->array[j + 1];
                v->array[j + 1] = aux;
            }
        }
    }
};

void vet_ordenarSelection(Vetor* v){
    int min, aux;
    for (int i = 0; i < v->tamVetor; i++){
        min = i;
        for(int j = (i+1); j < v->tamVetor; j++) {
            if(v->array[j] < v->array[min]){
                min = j;
            }
        }
        if(v->array[i] != v->array[min]){
            aux = v->array[i];
            v->array[i] = v->array[min];
            v->array[min] = aux;
        }
    }
};

void vet_ordenarSelection_parcial(Vetor* v, int percentual){
    int min, aux, percentual_total;
    float a;
    a = percentual; percentual_total = v->tamVetor*(a/100);

    for (int i = 0; i < percentual_total; i++){
        min = i;
        for(int j = (i+1); j < percentual_total; j++) {
            if(v->array[j] < v->array[min]){
                min = j;
            }
        }
        if(v->array[i] != v->array[min]){
            aux = v->array[i];
            v->array[i] = v->array[min];
            v->array[min] = aux;
        }
    }
};

void vet_ordenarSelectionDesc(Vetor* v){
    int min, aux;
    for (int i = 0; i < v->tamVetor; i++){
        min = i;
        for(int j = (i+1); j < v->tamVetor; j++) {
            if(v->array[j] > v->array[min]){
                min = j;
            }
        }
        if(v->array[i] != v->array[min]){
            aux = v->array[i];
            v->array[i] = v->array[min];
            v->array[min] = aux;
        }
    }
};

void vet_ordenarInsertion(Vetor* v){
    int j, aux;
    for (int i = 1; i < v->tamVetor; i++) {
        aux = v->array[i];
        j = i - 1;

        while (j >= 0 && v->array[j] > aux) {
            v->array[j + 1] = v->array[j];
            j = j - 1;
        }
        v->array[j + 1] = aux;
    }
};

int vet_buscaBinaria(Vetor* v, TipoElemento elemento){
    int left = v->qtdeElementos-1;
    int right = v->tamVetor-1;

    if (left > right){
        puts("O vetor precisa estar ordenado crescentemente!");
        return -1;
    }else{
        int middle = (left+right)/2;

        while (left <= right) {
            if (v->array[middle] < elemento){
                left = middle + 1;
            }
            else if (v->array[middle] == elemento) {
                return middle;
                break;
            }
            else{
                right = middle - 1;
            }
            middle = (left + right)/2;
        }
    }
};

Vetor* vet_importar(char* nomeArquivo){
    char ch ,line[256];
    int i = 0;

    FILE* fp = fopen(nomeArquivo, "r"); //Modo leitura
    if (fp == NULL){
        perror("Erro.\n");
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF){
        if(ch == '\n'){
            i++;
        }
    }

    Vetor* vetor = vet_criar(i);
    rewind(fp);
    for (size_t i = 0; fgets(line, sizeof(line), fp); i++) {
        vetor->array[i] = atoi(line);
    }

    fclose(fp);
    return vetor;
};

Boolean vet_exportar(Vetor* v, char* nomeArquivo){
    FILE* fp = fopen(nomeArquivo, "w+"); //Modo escrita
    if (fp == NULL){
        return false;
    }

    for (size_t i = 0; i < v->tamVetor; i++) {
        fprintf(fp, "%s\n", itoa(v->array[i], 10));
    }

    fclose(fp);
    return true;
};

Vetor* vet_criarAleatorio(int tam){
    int elemento;
    Vetor* vet = vet_criar(tam);
    for (size_t i = 0; i < tam; i++) {
        elemento = rand()%(tam*10) + 1;
        vet_inserir(vet, elemento, i);
    }

    return vet;
};

Vetor* vet_criarAscendente(int tam){
    Vetor* vet = vet_criarAleatorio(tam);
    vet_ordenarSelection(vet);
    return vet;
};

Vetor* vet_criarDescendente(int tam){
    Vetor* vet = vet_criarAleatorio(tam);
    vet_ordenarSelectionDesc(vet);
    return vet;
};

Vetor* vet_criarAscendenteParcial(int tam, int percentual){
    Vetor* vet = vet_criarAleatorio(tam);
    vet_ordenarSelection_parcial(vet, percentual);
    return vet;
};

int negativeToPositive(Vetor* v, int posicao){
    if(posicao < 0){
        return v->tamVetor + posicao;
    }else{
        return posicao;
    }
};

char* itoa(int val, int base){
    if(val == 0){
        return "0";
    }else{
        static char buf[32] = {0};
        int i = 30;

        for(; val && i ; --i, val /= base){
            buf[i] = "0123456789abcdef"[val % base];
        }

        return &buf[i+1];
    }
};

void shiftLeft(Vetor* v, int posicao){
    int posicao_aux, arr_aux;
    for (int i = posicao; i > 0; i--) {
        if(v->array[i] == 0){
            for (size_t j = i; j < posicao; j++) {
                v->array[j] = v->array[j+1];
            }
            break;
        }
    }
};
