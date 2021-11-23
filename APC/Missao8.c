#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	int x, y, z, numx, numy, numz, menu, resul1, resul2, resul3, resul4;

int valor_x(int x);
int valor_y(int y);
int valor_z(int z);
void imprime_menu();
int menu1();
int menu2();
int menu3();
int menu4();
void menu5();
void menu6();

int main() {

	valor_x(numx);
	valor_y(numy);
	valor_z(numz);

	do {
		imprime_menu();
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
			menu3();
			break;

		case 4:
			menu4();
			break;

		case 5:
			menu5();
			break;

		case 6:
			menu6();
			break;

		case 7:
			printf("Obrigada pela visita!\n");
			break;

		default:
			printf("Opcao desconhecida! Tente novamente!\n");
			break;
		}

	} while (menu != 7);
	
	return 0;
}

int valor_x(int x) {
	printf("Digite o valor de X:\n");
	scanf("%d", &x);
	if (x < 0) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &x);
	}
	if (x > 7) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &x);
	}
	if (x == 2 || x == 3 || x == 5 || x == 7) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &x);
	}
	numx = x;
	return numx;
}

int valor_y(int y) {
	printf("Digite o valor de Y:\n");
	scanf("%d", &y);
	if (y < 0) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &y);
	}
	if (y > 7) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &y);
	}
	if (y == 2 || y == 3 || y == 5 || y == 7) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &y);
	}
	numy = y;
	return numy;
}
int valor_z(int z) {
	printf("Digite o valor de Z:\n");
	scanf("%d", &z);
	if (z < 0) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &z);
	}
	if (z > 7) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &z);
	}
	if (z == 2 || z == 3 || z == 5 || z == 7) {
		printf("NUMERO INVALIDO! DIGITE NOVAMENTE:\n");
		scanf("%d", &z);
	}
	numz = z;
	return numz;
}

void imprime_menu () {
	
	printf("\n\n\t\t MENU\n\n");
	printf("1 - x!+ y!+ z!\n");
	printf("2 - (x + y + z)!\n");
	printf("3 - (x + y)!+ (x - z)!\n");
	printf("4 - x!- (z + y)!\n");
	printf("5 - Se fossem lados, os 3 numeros formariam um triangulo equilatero ?\n");
	printf("6 - Se fossem lados, os 3 numeros formariam um triangulo isosceles ?\n");
	printf("7 - Sair\n\n");

}

int menu1() {
	int num1, num2, num3, resul1, x1 = numx, y1 = numy, z1 = numz;
	for (num1 = 1; x1 > 0; x1--){
		num1 = num1 * x1;
	}
	for (num2 = 1; y1 > 0; y1--){
		num2 = num2 * y1;
	}
	for (num3 = 1; z1 > 0; z1--){
		num3 = num3 * z1;
	}
	resul1 = num1 + num2 + num3;
	printf("------------------------------------------\n");
	printf("O resultado da operacao x! + y! + z! eh: %d\n", resul1);
	printf("------------------------------------------\n");
}

int menu2() {
	int reasul2, soma, x2 = numx, y2 = numy, z2 = numz;
	soma = x2 + y2 + z2;
	for (resul2 = 1; soma > 0; soma--) {
		resul2 = resul2 * soma;
	}
	printf("------------------------------------------\n");
	printf("O resultado da operacao (x + y + z)! eh: %d\n", resul2);
	printf("------------------------------------------\n");

}

int menu3() {
	int xy, xz, resul3, fatxy, fatxz, x3 = numx, y3 = numy, z3 = numz;
	xy = x3 + y3;
	xz = x3 - z3;
	for (fatxy = 1; xy > 0; xy--) {
		fatxy = fatxy * xy;
	}
	if (xz < 0) {
		for (fatxz = 1; xz < 0; xz++) {
			fatxz = fatxz * xz;
		}
	}
	else{
		for (fatxz = 1; xz > 0; xz--) {
			fatxz = fatxz * xz;
		}
	}
	resul3 = fatxy + fatxz;
	printf("------------------------------------------\n");
	printf("O resultado da operacao (x + y)!+ (x - z)! eh: %d\n", resul3);
	printf("------------------------------------------\n");
}

int menu4() {
	int num1, zy, fatzy, resul4, x4 = numx, y4 = numy, z4 = numz;
	zy = z4 + y4;
	for (num1 = 1; x4 > 0; x4--) {
		num1 = num1 * x4;
	}
	for (fatzy = 1; zy > 0; zy--) {
		fatzy = fatzy * zy;
	}
	resul4 = num1 - fatzy;
	printf("------------------------------------------\n");
	printf("O resultado da operacao x!- (z + y)! eh: %d\n", resul4);
	printf("------------------------------------------\n");
}

void menu5() {
	if (numx == numy && numx == numz) {
		printf("------------------------------------------\n");
		printf("Se fossem lados, os 3 numeros formariam um triangulo equilatero?\nSIM!\n");
		printf("------------------------------------------\n");
	}
	else {
		printf("------------------------------------------\n");
		printf("Se fossem lados, os 3 numeros formariam um triangulo equilatero?\nNAO!\n");
		printf("------------------------------------------\n");
	}
}

void menu6() {
	if (numx == numy && numx != numz) {
		printf("------------------------------------------\n");
		printf("Se fossem lados, os 3 numeros formariam um triangulo isosceles?\nSIM!\n");
		printf("------------------------------------------\n");
	}
	else if (numx == numz && numx != numy) {
		printf("------------------------------------------\n");
		printf("Se fossem lados, os 3 numeros formariam um triangulo isosceles?\nSIM!\n");
		printf("------------------------------------------\n");
	}
	else if (numz == numy && numx != numz) {
		printf("------------------------------------------\n");
		printf("Se fossem lados, os 3 numeros formariam um triangulo isosceles?\nSIM!\n");
		printf("------------------------------------------\n");
	}
	else {
		printf("------------------------------------------\n");
		printf("Se fossem lados, os 3 numeros formariam um triangulo isosceles?\nNAO!\n");
		printf("------------------------------------------\n");
	}
}