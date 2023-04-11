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
}tfila;

void criar (tfila * ppf){
    ppf->comeco = NULL;
    ppf->fim = NULL;
}

bool enfilerar(tfila * ppf, int valor, int * tamanho){
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
            *tamanho +=1;
            return true;
        }else{
            novo->dado = valor;
            novo-> prox = NULL;
            (ppf->fim)->prox = novo;
            ppf->fim = novo;
            *tamanho +=1;
            //printf("FilaPF[%d]", novo->dado);
            return true;
        }
    }
}

bool desinfileirar(tfila * ppf, int * valor, int * tamanho){
    tno * aux;
    if(ppf->comeco==NULL){
        return false;
    }else{
        aux = ppf->comeco;
        *valor = aux->dado;
        ppf->comeco = aux->prox;
        *tamanho -=1;
        free(aux);
        return true;
    }
}

bool separar_impar_par(tfila *fila_inicial, tfila *fila_impar, tfila *fila_par) {
    int valor;
    int tamanho = 0;
    while (desinfileirar(fila_inicial, &valor, &tamanho)) {
        if (valor % 2 == 0) {
            if (!enfilerar(fila_par, valor, &tamanho)) {
                return false;
            }
        } else {
            if (!enfilerar(fila_impar, valor, &tamanho)) {
                return false;
            }
        }
    }
    return true;
}



bool imprimir_fila(tfila * fila){
	int valor, tamanho;
	while(desinfileirar(fila, &valor, &tamanho)){
		printf("%d-", valor);
	}
	return true;
}


int main() {
    tfila fila_principal;
    tfila fila_impar;
    tfila fila_par;
    int tamanho = 0;
    criar(&fila_principal);
    criar(&fila_impar);
    criar(&fila_par);
	if(!enfilerar(&fila_principal, 10, &tamanho)){
		printf("ERRO");
	}
	
	if(!enfilerar(&fila_principal, 98, &tamanho)){
		printf("ERRO");
	}
	
	if(!enfilerar(&fila_principal, 687, &tamanho)){
		printf("ERRO");
	}
	
	if(!enfilerar(&fila_principal, 103, &tamanho)){
		printf("ERRO");
	}
	
	if(!enfilerar(&fila_principal, 91, &tamanho)){
		printf("ERRO");
	}

	if(!enfilerar(&fila_principal, 66, &tamanho)){
		printf("ERRO");
	}
	
	if(!enfilerar(&fila_principal, 38, &tamanho)){
		printf("ERRO");
	}
	
	if(!enfilerar(&fila_principal, 99, &tamanho)){
		printf("ERRO");
	}
	
	if(!enfilerar(&fila_principal, 64, &tamanho)){
		printf("ERRO");
	}
	
	if(!enfilerar(&fila_principal, 32, &tamanho)){
		printf("ERRO");
	}

    if(!enfilerar(&fila_principal, 52, &tamanho)){
		printf("ERRO");
	}

    printf("Tamanho fila principal: %d\n", tamanho);

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
