#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao, num3;
    float altura, peso, imc;
    float num1, num2, result;

    do{
    	printf("\n\n         MENU\n");
    	printf("Escolha uma opcao do menu: \n");
    	printf("1- Informacoes\n");
    	printf("2- Calcular IMC\n");
    	printf("3- Par ou Impar\n");
    	printf("4- Multiplicacao\n");
    	printf("5- Divisao\n");
    	printf("6- Sair\n\n");
    
    	scanf("%d", &opcao);
		system("cls");
		
    	switch(opcao){
    		case 1: //informacoes
    		
    			printf("Informacoes do aluno dono do programa:\n");
    			printf("Nome: Ana Beatriz Ferreira dos Santos.\n");
    		break;
    		
    		case 2: //calcular imc
    			printf("Digite sua altura: \n");
    			scanf("%f", &altura);
    			printf("Digite o seu peso: \n");	
    			scanf("%f", &peso);
    
    			imc = peso/(altura*altura);
    
    			printf("Seu IMC eh: %.2f \n", imc);
    			if (imc<18.5){
    				printf("Abaixo do Peso.\n");
    				break;
    			}
    
    				if(imc>=18.5 && imc<24.9){
    				    printf("Peso Normal.\n");
    				    break;
    				}
    					else if(imc>=25 && imc<29.9){
        					printf("Sobrepeso.\n");
        					break;
    					}
    
    						else if(imc>=30 && imc<34.9){
        						printf("Obesidade Grau I.\n");
        						break;
    						}
    
    							else if(imc>=35 && imc<39.9){
        							printf("Obesidade Grau II.\n");
        							break;
    							}
    
    							else{
        							printf("Obesidade Grau III ou Morbida.\n");
        		                    break;
    							}
    							
    		case 3:
    			printf("Digite o numero:\n");
    			scanf("%d", &num3);
    			if(num3 % 2==0){
    				printf("O numero eh PAR.\n");
				}
				else{
					printf("O numero eh IMPAR.\n");
				}
			break;
    
    		case 4: //multiplicar
    			printf("Digite o primeiro numero: \n");
    			scanf("%f", &num1);
    			printf("Digite o segundo numero: \n");
    			scanf("%f", &num2);
    
    			result = num1*num2;
    
    			printf("O resultado dessa operacao eh: %.1f\n", result);
    		break;
    		
    		case 5:
    			printf("Digite o primeiro numero: \n");
    			scanf("%f", &num1);
    			printf("Digite o segundo numero: \n");
    			scanf("%f", &num2);
    
    			result = num1/num2;
    
    			printf("O resultado dessa operacao eh: %.1f\n", result);
    		break;
    
    		case 6: //sair
    			printf("Obrigada por sua visita!\n");
    		break;
    
    		default: //se digitar um numero que nao esta no menu
    			printf("Opcao desconhecida! Tente novamente.\n");
    	}
            
    }while(opcao!=6);
    return 0;
}

