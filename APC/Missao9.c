#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count_n = 0;

//Assinaturas	
void cadastrar(int idade[]);
void imprimirMenu();
int menu1(int idade[]);
int menu2(int idades[]);
int menu3(int idade[]);
int menu4(int idade[]);
int menu5(int idade[]);
int menu6(int idade[]);


int main() {

	int idade[10000], i = 0, count_n = 0, menu, maior = 1, menor = 149;

	cadastrar(idade);

	do {//Usar o Do While para deixar o menu em loop e so sair quando o usuario pedir 
		imprimirMenu();		
		scanf("%d", &menu);
		system("cls");
		switch (menu)
		{
		case 1:
			menu1(idade);
			break;	
		case 2:
			menu2(idade);
			break;
		case 3:
			menu3(idade);
			break;
		case 4:
			menu4(idade);
			break;
		case 5:
			menu5(idade);
			break;
		case 6:
			menu6(idade);
			break;
		case 7:
			printf("Obrigada pela visita!");
			break;
		default:
			printf("Opcao invalida!Tente novamente!");
			break;
		}
	} while (menu != 7);
	

	return 0;
}

void imprimirMenu() { //Procedimento para mostar o menu na 
	printf("\n\n\t\t MENU\n\n");
	printf("1 - Informacoes Gerais\n");
	printf("2 - Listar idades\n");
	printf("3 - Listar Maiores / Menores que a media\n");
	printf("4 - Editar idade\n");
	printf("5 - Excluir idade\n");
	printf("6 - Pesquisar posicao\n");
	printf("7 - Sair\n\n");

	printf("Escolha uma opcao: ");

}

//Funcao para receber as valores digitado
void cadastrar(int idade[]) {
	printf("So seram aceitas idades de 1 - 149.\n");
	do {//Usar o Do While para cadastrar as idades		
		printf("Digite a idade que deseja cadastrar: ");
		scanf("%d", &idade[count_n]);
		if (idade[count_n] <= 0 || idade[count_n] >= 150) {
			break;
		}
		else count_n++;
	} while (count_n > 0 || count_n < 150);

}

//Funcao para informar a quantidade de idades cadastradas, a media dela, a maior e a menor
int menu1(int idade[]) {
	int i = 0, maior = 1, menor = 149, soma=0;
	float media;
	for (i = 0; i < count_n; i++) {
		if (idade[i] > maior) {
			maior = idade[i];
		}
		if (idade[i] < menor) {
			menor = idade[i];
		}
	}
		for (i = 0; i < count_n; i++) {
			soma += idade[i];
		}
	media = (float) soma / count_n;
	printf("Quantas idades foram cadastradas: %d\nMedia das idades cadastradas: %.2f\nMaior idade cadastrada: %d\nMenor idade cadastrada: %d", count_n, media, maior, menor);
}

//Funcao para listar as idades cadastradas
int menu2(int idade[]) {
	int i;
	printf("Idades cadastradas: \n");
	for (i = 0; i < count_n; i++) {
		printf("%d\n", idade[i]);
		}
 }

//Funcao para listar as idades cadastradas que sao maiores e menores que a media
int menu3(int idade[]){
	int i, soma = 0, media, maioresm = 0, novasoma = 0, menorm = 0;

	printf("Numeros maiores que a media:\n");
	for (i = 0; i < count_n; i++) {
		soma += idade[i];
	}
	media = (float)soma / count_n;
	for (i = 0; i < count_n; i++) {
		if (idade[i] > media) {
			printf("%d\n", idade[i]);
			maioresm++;
		}
	}

	printf("Numeros menores que a media:\n");
	for (i = 0; i < count_n; i++) {
		novasoma += idade[i];
	}
	for (i = 0; i < count_n; i++) {
		if (idade[i] < media) {
			printf("%d\n", idade[i]);
			menorm++;
		}
	}
}

//Funcao para alterar uma idade cadastrada
int menu4(int idade[]) {
	int posicao;
	printf("A idade que desja alterar esta em qual posicao?\n");
	scanf("%d", &posicao);
	if (posicao <= 0 || posicao > count_n) {
		printf("Posicao invalida!\n");
	}
	else {
		printf("Na posicao %d contem a idade %d\n", posicao, idade[posicao - 1]);
		printf("Digite a nova idade a ser cadastrada: ");
		scanf("%d", &idade[posicao - 1]);
		printf("Idade alterada com sucesso!\n");
	}
}

//Funcao para excluir uma idade cadastrada
int menu5(int idade[]) {
	int posicao, i;
	printf("A idade que desja excluir esta em qual posicao?\n");
	scanf("%d", &posicao);
	if (posicao <= 0 || posicao > count_n) {
		printf("Posicao invalida!\n");
	}
	else {
		posicao--;
		for (i = posicao; i < count_n; i++) {
			idade[i] = idade[i + 1];
		}
		printf("Idade excluida com sucesso!\n");
		count_n--;
	}
}

//Fun��o para pesquisar uma idade cadastrada
int menu6(int idade[]) {
	int posicao;

	printf("A idade que desja pesquisar esta em qual posicao?\n");
	scanf("%d", &posicao);
	if (posicao <= 0 || posicao > count_n) {
		printf("Posicao invalida!\n");
	}
	else {
		printf("A idade achada foi: %d\n", idade[posicao - 1]);
	}
}