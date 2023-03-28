#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct no{
    int dado;
    struct no * prox;
}tno;

typedef struct fila{
    tno * comeco;
    tno * fim;
}tfila;

void criar (tfila * ppf){
    ppf->comeco = NULL;
    ppf->fim = NULL;
}

bool enfilerar(tfila * ppf, int valor){
    tno * novo = (tno *) malloc(sizeof (tno));
    if (novo == NULL){
        return false;
    }else {
        if (ppf->comeco == NULL) {
            novo->dado = valor;
            novo->prox = NULL;
            ppf->comeco = novo;
            ppf->fim = novo;
            printf("FilaPF[%d]", novo->dado);
        }else{
            novo->dado = valor;
            novo-> prox = NULL;
            (ppf->fim)->prox = novo;
            ppf->fim = novo;
            printf("FilaPF[%d]", novo->dado);
        }
       return true;
    }
}

bool desinfileirar(tfila * ppf, int * valor){
    tno * aux;
    if(ppf->comeco==NULL){
        return false;
    }else{
        aux = ppf->comeco;
        *valor = aux->dado;
        ppf->comeco = aux->prox;
        free(aux);
    }
    return true;
}

void main() {
    int pegaValor;
    tfila * pf;
    criar(&pf);
    if(!enfilerar(&pf, 1)){
        printf("Erro ao adicionar a fila.");
    }
    if(!enfilerar(&pf, 2)){
        printf("Erro ao adicionar a fila.");
    }
    if(desinfileirar(&pf, &pegaValor)){
        printf("Retirado valor");
    }


}
