#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct no{
    int valor;
    int prioridade;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num, int prio){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->prioridade = prio;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
           if(prio > 1){
                if((*fila)->prioridade < 2){ // é a primeira prioridade?
                    novo->proximo = *fila; // insere no início da fila
                    *fila = novo;
                }
                else{
                    aux = *fila;
                    while(aux->proximo && aux->proximo->prioridade > 1)
                        aux = aux->proximo;
                    novo->proximo = aux->proximo; // insere depois da última prioridade
                    aux->proximo = novo;
                }
            }
            else{
                aux = *fila;
                while(aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
        }
    }
    else{
        printf("\n  ===============================");
        printf("\n | \t\t\t\t|"                                                                 );
        printf("\n | FILA VAZIA!!!\t\t|"                                                   );
        printf("\n | \t\t\t\t|"                                                                 );
        printf("\n  ===============================");
        printf("\n\n");
    }
}


No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila vazia\n");

    return remover;
}

void imprimir(No *fila){
            int contador = 0;

            printf("\n  ================ Sistemas de Senhas ==================="                 );
            printf("\n |                **Listagem da Fila**  \t\t|"                                                                            );
            printf("\n  =======================================================");
            printf("\n |  Posicao \t|  Senha \t|  Tipo \t\t|"                                                                                  );
            printf("\n |\t\t|\t\t|\t\t\t|"                                                                                                              );
            while(fila){
                contador++;
                if(fila->prioridade == 1){
                    printf("\n |\t %d \t|\t %d \t|\tNormal\t\t|", contador, fila->valor                                               );
                }else{
                    printf("\n |\t %d \t|\t %d \t|\tPreferencial\t|", contador, fila->valor                                           );
                }
                fila = fila->proximo;
            }
            printf("\n |\t\t|\t\t|\t\t\t|"                                                                                                             );
            printf("\n  =======================================================");

            printf("\n\n");
            system("pause");
            sleep(1);
            system("cls");

}
