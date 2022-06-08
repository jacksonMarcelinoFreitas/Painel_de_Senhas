#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {


	int resposta;
	int senha, aux1 = 0, aux2 = 0;
	int SenhasNORMAL[aux1], SenhasPREFERENCIAL[aux2];


	printf("________________________________\n");
	printf("|\tSistema de Senhas\t|\n");
	printf("|      **Menu de Opcoes**\t|\n");
	printf("|_______________________________|\n");
	printf("|\t1-Geracao de Senha\t|\n");
	printf("|\t2-Chamada de Senha\t|\n");
	printf("|\t3-Listagem de Fila\t|\n");
	printf("|\t\t\t\t|\n");
	printf("|\tX-Sair do Programa\t|\n");
	printf("|_______________________________|\n");

	printf("\nDigite o que deseja: ");
	scanf("%d", &resposta);

	if (resposta==1){
		int resposta2;
		while (resposta2 != 3){

			printf("\n\n1-NORMAL ou 2-PREFERENCIAL\n\n");

			printf("\nDigite o que deseja: ");
			scanf("%d", &resposta2);

			if(resposta2 ==1){
					senha = rand()%1000 + 1;
					printf("\nEscolha foi: NORMAL");
					printf("\nSenha gerada: %d", senha);

					SenhasNORMAL[aux1] = senha;
					aux1++;
			}else if(resposta2 ==2){
					senha = rand()%1000 + 1;
					printf("\nEscolha foi: PREFERENCIAL");
					printf("\nSenha gerada: %d", senha);

					SenhasPREFERENCIAL[aux2] = senha;
					aux2++;
				}
				else{
					printf("\nEscolha INCORRETA");
				}
			}
		}
        return 0;
	}
