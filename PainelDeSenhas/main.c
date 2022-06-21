#include "funcoes.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    No *r, *fila = NULL;
    int opcao, op, valor;
	int prioridade;
	srand(time(NULL));

    do{
        printf("\n ============= Sistemas de Senhas ==============="                 );
        printf("\n |           **Geracao de senhas**  \t\t|"                                                           );
        printf("\n ================================================");
        printf("\n | 1)Geração de Senha \t\t\t\t|"                                                                       );
		printf("\n | 2)Chamada de Senha \t\t\t\t|"                                                                     );
        printf("\n | 3)Listagem fila\t\t\t\t|"                                                                                );
        printf("\n |\t\t\t\t\t\t|"                                                                                                 );
        printf("\n | 0)Sair \t\t\t\t\t|"                                                                                         );
        printf("\n ================================================");
        printf("\n\n>> ");
		scanf("%d", &opcao);
		sleep(1);
		system("cls");

        switch(opcao){
        case 1:

        printf("\n ========= Sistemas de Senhas ==========="                 );
        printf("\n|\t**Geracao de senhas**\t\t|"                                                     );
        printf("\n ========================================");
        printf("\n| \t\t\t\t\t|"                                                                                );
        printf("\n| 1 - Senha  NORMAL\t\t\t|"                                                         );
        printf("\n| 2 - Senha PREFERENCIAL\t\t|"                                                   );
        printf("\n| \t\t\t\t\t|"                                                                                 );
        printf("\n ========================================");
        printf("\n\n>> ");
        scanf("%d", &op);
        sleep(1);
        system("cls");

	        switch(op){
	        	case 1:
	        		valor = rand() % 100;
					valor = valor+1;
			        prioridade = 1;
		            inserir_na_fila(&fila, valor, prioridade);

		            printf("\n =================================");
                    printf("\n |      **Senha gerada**\t|"                                        );
                    printf("\n |\t\t\t\t|"                                                                  );
                    printf("\n | SENHA:     ** %d **\t\t|"                               , valor);
                    printf("\n =================================");
                    printf("\n | Tipo:  Normal           \t|"                                          );
                    printf("\n | Status:  Inclusa no sistema\t|"                                  );
                    printf("\n =================================");
                    printf("\n\n");
                    system("pause");
                    sleep(1);
                    system("cls");


	        	break;
	        	case 2:
	        		valor = rand() % 100;
	        		valor = valor+1;
			        prioridade = 2;
		            inserir_na_fila(&fila, valor, prioridade);
		            printf("\n =================================");
                    printf("\n |      **Senha gerada**\t|"                                        );
                    printf("\n |\t\t\t\t|"                                                                  );
                    printf("\n | SENHA:     ** %d **\t\t|"                               , valor);
                    printf("\n =================================");
                    printf("\n | Tipo:  Preferencial\t\t|"                                            );
                    printf("\n | Status:  Inclusa no sistema\t|"                                  );
                    printf("\n =================================");
                    printf("\n\n");
                    system("pause");
                    sleep(1);
                    system("cls");


	        	break;
	        	default:
		            if(op != 1 || op != 2)
                            printf("\n =================================");
                            printf("\n | \t\t\t\t|"                                                                 );
                            printf("\n | ERRO: OPÇÃO INVÁLIDA!!!\t|"                                  );
                            printf("\n | \t\t\t\t|"                                                                 );
                            printf("\n =================================");
                            printf("\n\n");
                            system("pause");
                            sleep(1);
                            system("cls");
		        }

            break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
            	if(r->prioridade == 1){

                    printf("\n =================================");
                    printf("\n |      **Senha chamada**\t|"                                     );
                    printf("\n |\t\t\t\t|"                                                                  );
                    printf("\n | SENHA:     ** %d **\t\t|"                          , r->valor);
                    printf("\n =================================");
                    printf("\n | Tipo:  Normal\t\t|"                                                  );
                    printf("\n | Status:  Excluída no sistema\t|"                                );
                    printf("\n =================================");
                    free(r);
                    printf("\n\n");
                    system("pause");
                    sleep(1);
                    system("cls");
				}

				else if(r->prioridade == 2){
                    printf("\n =================================" );
                    printf("\n |      **Senha chamada**\t|"                                      );
                    printf("\n |\t\t\t\t|"                                                                   );
                    printf("\n | SENHA:     ** %d **\t\t|"                           , r->valor);
                    printf("\n =================================" );
                    printf("\n | Tipo:  Preferencial\t\t|"                                             );
                    printf("\n | Status:  Excluída no sistema\t|"                                  );
                    printf("\n =================================" );
                    free(r);
                    printf("\n\n");
                    system("pause");
                    sleep(1);
                    system("cls");
				}
            }
            break;
        case 3:
            imprimir(fila);
            break;
        default:
            if(opcao >= 4)
                printf("\n =================================");
                printf("\n | \t\t\t\t|"                                                                 );
                printf("\n | ERRO: OPÇÃO INVÁLIDA!!!\t|"                                  );
                printf("\n | \t\t\t\t|"                                                                 );
                printf("\n =================================");
                printf("\n\n");
                system("pause");
                sleep(1);
                system("cls");
        }

    }while(opcao != 0);

    return 0;
}

