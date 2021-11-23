#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, num_in = 0, num_neg = 0, num_par = 0, num_prim = 0, i, rest = 0;
	int menu;
	float media, soma = 0;

	printf("Digite os numeros inteiros que deseja cadastrar:\n");
	printf("OBS.: Para parar de cadastrar, digite um numero multiplo de 150.\n");

	do {
		scanf("%d", &n);
		rest = 0;
		if (n % 150 == 0) {
			break;
		}
		
		else {
			num_in += 1;
			soma += n;
			rest = 0;

			if (n < 0) {
				num_neg += 1;
				for (i = -2; i >= n / 2 ; i--) {
					if (n % i == 0) {
						rest+=1;
						break;
					}
				}
				if (rest == 0) {
					num_prim += 1;
				}
			}
			if (n % 2 == 0) {
				num_par += 1;
			}
			if (n >= 0) {		
				for (i = 2; i <= n / 2; i++) {
					if (n % i == 0) {
						rest+=1;
						break;
					}				
				}
				if (rest == 0) {
					num_prim += 1;
				}
			}
		}

	} while (n % 150 != 0);
	system("cls");

	do {
		
		printf("\nEscolha a opcao desejada:\n\n");
		printf("                MENU\n");
		printf("1 - Quantidade de numeros inseridos\n");
		printf("2 - Quantidade de numeros negativos\n");
		printf("3 - Quantidade de numeros pares\n");
		printf("4 - Quantidade de numeros primos\n");
		printf("5 - Media dos numeros\n");
		printf("6 - Sair\n\n");
		
		scanf("%d", &menu);
		system("cls");

		switch (menu)
		{
		case 1:
			printf("Esse eh o total de numeros cadastrados:\n");
			printf("%d\n", num_in);
			break;
		case 2:
			printf("Esse eh o total de numeros negativos cadastrados:\n");
			printf("%d\n", num_neg);
			break;
		case 3:
			printf("Esse eh o total de numeros pares cadastrados:\n");
			printf("%d\n", num_par);
			break;
		case 4:
			printf("Esse eh o total de numeros primos cadastrados:\n");
			printf("%d\n", num_prim);
			break;
		case 5:
			printf("Essa eh a media dos numeros cadastrados:\n");
			media = (soma / num_in);
			printf("%.2f\n", media);
			break;
		case 6:
			printf("Obrigada pela visita!");
			break;

		default:
			printf("Opcao invalida!\n Tente novamente.\n");
			break;
		}

	} while (menu != 6);

	return 0;
}