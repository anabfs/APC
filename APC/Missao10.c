#include <stdio.h>
#include <stdlib.h>

//Variavel global
int matriz[3][3];

//Assinaturas
void imprimeMenu();
void matrizPrincipal();
void menu1();
void menu2();

int main() {

	int menu;
	matrizPrincipal();
	
	do {//Usar o Do While para deixar o menu em loop e so sair quando o usuario pedir 
		imprimeMenu();
		printf("\nDigite uma opcao do menu: ");
		scanf("%d", &menu);
		system("cls");
		switch (menu){
		case 1:
			menu1();
			break;

		case 2:
			menu2();
			break;

		case 3:
			printf("Obrigada pela visita!\n");
			break;

		default:
			printf("Opcao invalida! Tente novamente!\n\n");
			break;
		}
	} while (menu != 3);

	return 0;
}

void imprimeMenu() {// Procedimento para mostar o menu
	printf("\tMenu\n\n");
	printf("1 - Cadastrar Aluno\n");
	printf("2 - Ver Turma\n");
	printf("3 - Sair\n");
}

void matrizPrincipal() {// Funcao para garantir que todas as posicoes da metriz sejam -1
	
	int a, b, id;

	for (a = 0; a < 3; ++a) {
		for (b = 0; b < 3; ++b) {
			matriz[a][b] = -1;
		}
	}
}

void menu1() {//Funcao para cadastrar a ID
	int a, b, id;
	
	system("cls");
	printf("----------CADASTRO DE ALUNO----------\n\n");
	printf("So seram aceitos numeros de 0 ate 2.\n\n");
	printf("Digite a linha: ");
	scanf("%d", &a);
	printf("Digite a coluna: ");
	scanf("%d", &b);

	while (a < 0 || a>2 || b < 0 || b>2){ //Loop de repeticao para nao precisar voltar para o menu caso digite um numero invalido
		printf("Posicao invalida! Tente novamente!\n");
		printf("Digite a linha: ");
		scanf("%d", &a);
		printf("Digite a coluna: ");
		scanf("%d", &b);
	}
	
	printf("Posicao valida!\n\nSo seram aceitos numeros de 0 ate 100.\nDigite o numero de ID: ");	
	scanf("%d", &id);
	while (id < 0 || id>100) {
		printf("Numero de ID invalido! Tente novamente!\nDigite o numero de ID: ");
		scanf("%d", &id);
	}
	matriz[a][b] = id; //

	printf("-------------------------------------\n");

	
}

void menu2() { // Funcao para mostrar a todas as IDs cadastradas
	int a, b;

	printf("------TURMA-----\n");
	for (a = 0; a < 3; ++a) { 
		for (b = 0; b < 3; ++b) {
			printf("  %d", matriz[a][b]);
		}
		printf("\n");
	}
	printf("----------------\n");
}
