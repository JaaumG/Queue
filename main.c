#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no * prox;
} tno;

typedef struct fila{
    tno * comeco;
    tno * fim;
    int size; //Isso é só para ter o tamanho da fila de forma mais facil sem precisar percorrer nó por nó.
}tfila;

void criar (tfila * ppf){
    ppf->comeco = NULL;
    ppf->fim = NULL;
    ppf->size =0;
}

bool enfilerar(tfila * ppf, int valor){
    tno * novo = (tno *) malloc(sizeof (tno));
    if (novo == NULL){
    	printf("ERRO");
        return false;
    }else {
        if (ppf->comeco == NULL) {
            novo->dado = valor;
            novo->prox = NULL;
            ppf->comeco = novo;
            ppf->fim = novo;
            ppf->size++;
            //printf("FilaPF[%d]", novo->dado);
            return true;
        }else{
            novo->dado = valor;
            novo-> prox = NULL;
            (ppf->fim)->prox = novo;
            ppf->fim = novo;
            ppf->size++;
            //printf("FilaPF[%d]", novo->dado);
            return true;
        }
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
        ppf->size--;
        free(aux);
        return true;
    }
}

bool separar_impar_par(tfila *fila_inicial, tfila *fila_impar, tfila *fila_par) {
    int valor;
    while (desinfileirar(fila_inicial, &valor)) {
        if (valor % 2 == 0) {
            if (!enfilerar(fila_par, valor)) {
                return false;
            }
        } else {
            if (!enfilerar(fila_impar, valor)) {
                return false;
            }
        }
    }
    return true;
}



bool imprimir_fila(tfila * fila){
	int valor;
	while(desinfileirar(fila, &valor)){
		printf("%d-", valor);
	}
	return true;
}


int main() {
    tfila fila_principal;
    tfila fila_impar;
    tfila fila_par;
    criar(&fila_principal);
    criar(&fila_impar);
    criar(&fila_par);

	if(!enfilerar(&fila_principal, 10)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 98)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 687)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 103)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 91)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 66)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 38)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 99)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 64)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 32)){
		printf("ERRO");
	}

    printf("Tamanho fila principal: %d\n", fila_principal.size);

	if(separar_impar_par(&fila_principal, &fila_impar, &fila_par)){
		if(imprimir_fila(&fila_principal)){
			printf("\nfila par: \n");
			if(imprimir_fila(&fila_par)){
				printf("\nfila impar: \n");
				if(imprimir_fila(&fila_impar)){
				}
			}
		}
	}

}
