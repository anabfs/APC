#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Struck com as informacoes do jogador.
typedef struct Jogador {
    int id;
    char nome[50];
    char posicao[4];
    int idade;
    int pontos_jogador;
}Jogador;

// Struck com as informacoes do time.
typedef struct Time {
    Jogador jogadores[5];
    char nome_time[50];
    char tecnico[50];
}Time;
Time time; //Declarando a struct.

// Struck para associar os jogadore com o seu time.
typedef struct JogadorPartida {
    int num_assistencias;
    int num_kills;
    int num_deaths;
}JogadorPartida;

// Struck com as informacoes da partida.
typedef struct Partida {
    int id_jogador;
    char destaque_nome[50], destaque_posicao[4];
    int total_kills_time;
    int total_kills_adversario;
    char vitoria;
    int total_torres_destruidas_time;
    int total_torres_destruidas_adversario;
    JogadorPartida jogadores_partida[5];
}Partida;
Partida partida[100];//Declarando a struct como um vetor para eu poder acessar cada partida cadastrada. 

// Struck com as pontuacoes.
typedef struct TotalPontos {
    int todas_assistencia;
    int todas_kills;
    int maior_pontuacao;
    int menor_pontuacao;
}TotalPontos;
TotalPontos totalpontos;//Declarando a struct.

int quant_partidas = 0;//Declarando como uma variavel global.

//Assinaturas.
    //Tipo int
    int imprimi_menu();
    int Kills(int i);
    int Assistencia(int i);
    int Pontuacao(int i);
    int Pontos(int ponto, int i);
    int Maiuscula(int i);
    //Tipo void
    void menu1();    
    void menu2();
    void menu3();
    void menu4();
    void menu5();
    void menu6();
    void menu7();
    void menu8();
    void menu9();
    void cadastrar_jogador(int i);
    //Tipo bool
    bool confirmar(char a);

//Fun��o main.
int main() {
    int menu;

    do {
        menu = imprimi_menu();
        system("cls"); //Limpar a tela depois de escolher uma opcao do menu.
        switch (menu) {
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
            menu7();
            break;
        case 8:
            menu8();
            break;
        case 9:
            menu9();
            break;
        case 10:
            printf("Obrigada pela visita!\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente!\n");
            break;
        }
    } while (menu != 10);
    return 0;
}

//Funcao para mostrar o menu.
int imprimi_menu() {
    int menu;
    printf("\n-----------------------Menu----------------------\n\n");
    printf("1) Cadastrar time\n");
    printf("2) Listar time\n");
    printf("3) Editar time\n");
    printf("4) Cadastrar partida\n");
    printf("5) Listar partidas\n");
    printf("6) Pesquisar jogador\n");
    printf("7) Mostrar numero total de kills e assistencias\n");
    printf("8) Mostrar jogador com menor pontuacao\n");
    printf("9) Mostrar jogador com maior pontuacao\n");
    printf("10) Sair\n\n\n");
    printf("Escolha uma opcao do menu: ");
    scanf("%d", &menu);
    return menu;
}

//Fun��o para cadastrar o time.
void menu1() {
    printf("------------------CADASTRAR TIME------------------\n\n");
    getchar();
    printf("Digite o nome do time: ");
    scanf(" %[^\n]s", time.nome_time);
    getchar();
    printf("Digite o nome do tecnico: ");
    scanf(" %s", time.tecnico);
    getchar();

    for (int i = 0; i < 5; i++) { //For para pegar as infomacaes 5 vezes.
        time.jogadores[i].id = i + 1; //Definir um ID para cada jogador automaticamente.
        cadastrar_jogador(i);
    }


}

void cadastrar_jogador(int i) {
        printf("Digite o nome do jogador: ");
        scanf("%s", time.jogadores[i].nome);

        printf("Digite a posicao do jogador: ");
        scanf("%s", time.jogadores[i].posicao);
        
        Maiuscula(i);
        //Comparar a posicao digitada com as possicoes validas usando o strcmp, se as duas forem igual fica = 0. 
        while ((strcmp(time.jogadores[i].posicao, "ADC") != 0) && (strcmp(time.jogadores[i].posicao, "SUP") != 0) && (strcmp(time.jogadores[i].posicao, "MID") != 0) && (strcmp(time.jogadores[i].posicao, "TOP") != 0) && (strcmp(time.jogadores[i].posicao, "JG") != 0)) {
            printf("Posicao invalida! Tente novamente!\nDigite a posicao do jogador: ");
            scanf("%s", time.jogadores[i].posicao);
            Maiuscula(i);
        }
        printf("Digite a idade do jogador: ");
        scanf("%d", &time.jogadores[i].idade);

        while (time.jogadores[i].idade < 0 || time.jogadores[i].idade>150) {
            printf("Idade invalida! Tente novamente!\nDigite a idade do jogador: ");
            scanf("%d", &time.jogadores[i].idade);
        }
}

//Funcao para caso o usuario escreva a posicao com letras minusculas, tranformar em maiusculas.
int Maiuscula(int i) {
    if (islower(time.jogadores[i].posicao[0]) ||
        islower(time.jogadores[i].posicao[1]) || 
        islower(time.jogadores[i].posicao[2])) {
            strupr(time.jogadores[i].posicao);
        }
    return time.jogadores[i].posicao;
}

//Funcao para listar as informacoes do time.
void menu2() {
    printf("\n-------------------LISTAR TIME-------------------\n\n");
    printf("\tNome do Time: %s\n", time.nome_time);
    printf("\tNome do Tecnico: %s\n", time.tecnico);
    printf("\tJogadores:\n");
    //O "%-5s" e os "%-10s" sao para definir um espaco para escrever cada informacao, fazendo assim uma tabela.
    printf("\t\t%-5s %-10s %-10s\n", "ID", "Nome", "Posicao");
    for (int i = 0; i < 5; i++) {//For para listar as informacoes dos 5 jogadores.
        printf("\t\t%-5d ", time.jogadores[i].id);
        printf("%-10s ", time.jogadores[i].nome);
        printf("%-10s \n", time.jogadores[i].posicao);
    }
}

bool confirmar(char verificar) {
    bool t = true;
	if(verificar == 'n'){
		t = false;
	}
	return t;
}

//Funcao para editar as infoormacoes de um jogador.
void menu3() {
    int i;
    char verificar;
    bool verdade;
    printf("\n-------------------EDITAR TIME-------------------\n\n");
    printf("Digite o ID do jogador que voce deseja editar: ");
    scanf("%d", &partida->id_jogador);
    //Verificando se o ID eh valido.
    while (partida->id_jogador < 1 || partida->id_jogador>5) {
        printf("ID invalido! Tente novamente!\nDigite o ID do jogador que voce deseja editar: ");
        scanf("%d", &partida->id_jogador);
    }
    i = partida->id_jogador - 1;//o ID vai de 1-5 enquanto no for vai de 0-4.

    printf("\n\t%-5s %-10s %-10s %-10s\n", "ID", "Nome", "Posicao", "Pontuacao");
    printf("\t%-5d %-10s %-10s %-10d\n\n", time.jogadores[i].id, time.jogadores[i].nome, time.jogadores[i].posicao, time.jogadores[i].pontos_jogador);
    getchar();
    printf("Voce tem certeza que deseja editar essas informacoes? (s/n)  ");
    scanf("%c", &verificar);


    while ((verificar != 's') && (verificar != 'n') && (verificar != 'S') && (verificar != 'N')) {
        getchar();
        printf("Opcao invalida! Tente novamente!\nVoce tem certeza que deseja editar essas informacoes? (s/n)  ");
        scanf("%c", &verificar);
    }
    verdade = confirmar(verificar);
    //Se editar depois de mostrar as informacoes do jogador e o usuario confirmar.
    if (verdade == true) {//Receber todas as novas informacoes mas mantendo o ID.
        getchar();
        cadastrar_jogador(i);
        printf("Digite a pontuacao do jogador: ");
        scanf("%d", &time.jogadores[i].pontos_jogador);

        //Mostrar as novas informacoes.
        printf("\n\t%-5s %-10s %-10s %-10s\n", "ID", "Nome", "Posicao", "Pontuacao");
        printf("\t%-5d %-10s %-10s %-10d\n\n", time.jogadores[i].id, time.jogadores[i].nome, time.jogadores[i].posicao, time.jogadores[i].pontos_jogador);

    }
    //Se o usuario nao quiser editar, volta para o menu.
    else {
        printf("\nNao houve nenhuma alteracao.\n");
    }
}

//Funcao para cadastrar as partidas.
void menu4() {
    int ponto = 0, destaque;

    printf("\n----------------CADASTRAR PARTIDAS----------------\n\n");
    //Receber todas as informacoes e verificar se sao validas se nao forem, entra no loop While e so sai quando a informacao for valida.
    printf("Digite o numero de kills do seu time: ");
    scanf("%d", &partida[quant_partidas].total_kills_time);
    while (partida[quant_partidas].total_kills_time < 0) {
        printf("Numero invalido!Tente novamente!\nDigite o numero de kills do seu time: ");
        scanf("%d", &partida[quant_partidas].total_kills_time);
    }

    printf("Digite o numero de kills do time adversario: ");
    scanf("%d", &partida[quant_partidas].total_kills_adversario);
    while (partida[quant_partidas].total_kills_adversario < 0) {
        printf("Numero invalido!Tente novamente!\nDigite o numero de kills do time adversario: ");
        scanf("%d", &partida[quant_partidas].total_kills_adversario);
    }
    getchar();
    printf("A sua equipe venceu a partida? (s/n) ");
    scanf("%c", &partida[quant_partidas].vitoria);
    partida[quant_partidas].vitoria = tolower(partida[quant_partidas].vitoria);//Caso o usuario escreva maiscula, tranformar em minuscula.
    while ((partida[quant_partidas].vitoria != 's') && (partida[quant_partidas].vitoria != 'n')) {
        printf("Opcao invalida!Tente novamente!\nA sua equipe venceu a partida? (s/n) ");
        scanf("%c", &partida[quant_partidas].vitoria);
        partida[quant_partidas].vitoria = tolower(partida[quant_partidas].vitoria);//Caso o usuario escreva maiscula, tranformar em minuscula.
    }
    printf("Digite o numero de torres destruidas do seu time: ");
    scanf("%d", &partida[quant_partidas].total_torres_destruidas_time);
    while (partida[quant_partidas].total_torres_destruidas_time < 0 || partida[quant_partidas].total_torres_destruidas_time>11) {
        printf("Numero invalido!Tente novamente!\nDigite o numero de torres destruidas do seu time: ");
        scanf("%d", &partida[quant_partidas].total_torres_destruidas_time);
    }
    printf("Digite o numero de torres destruidas do time adversario: ");
    scanf("%d", &partida[quant_partidas].total_torres_destruidas_adversario);
    while (partida[quant_partidas].total_torres_destruidas_adversario < 0 || partida[quant_partidas].total_torres_destruidas_adversario>11) {
        printf("Numero invalido!Tente novamente!\nDigite o numero de torres destruidas do time adversario: ");
        scanf("%d", &partida[quant_partidas].total_torres_destruidas_adversario);
    }
    destaque = -1;
    for (int i = 0; i < 5; i++) {//Informacoes dos jogadores.
        printf("\tJogador %d\n", i + 1);
        printf("\t\tDigite o numero de assistencia do jogodor: ");
        scanf("%d", &partida[quant_partidas].jogadores_partida[i].num_assistencias);
        printf("\t\tDigite o numero de kills do jogodor: ");
        scanf("%d", &partida[quant_partidas].jogadores_partida[i].num_kills);
        printf("\t\tDigite o numero de deaths do jogodor: ");
        scanf("%d", &partida[quant_partidas].jogadores_partida[i].num_deaths);

        totalpontos.todas_kills = Kills(i);
        totalpontos.todas_assistencia = Assistencia(i);
        time.jogadores[i].pontos_jogador = Pontuacao(i);

        ponto = Pontos(ponto, i);
            if (ponto > destaque) {//Definir o jogador destaque.
            destaque = ponto;
            //Passar o nome e posicao do jogador para as variaveis sobre os jogadore destaque, usando strcpy.
            strcpy(partida[quant_partidas].destaque_nome, time.jogadores[i].nome);
            strcpy(partida[quant_partidas].destaque_posicao, time.jogadores[i].posicao);

        }
    }quant_partidas++;//Soma 1 toda vez que cadastrar uma partidada.
}

int Kills(int i) {
    //Guardar o numero total de kills para usar na funcao menu7(), menu8() e menu9().
    totalpontos.todas_kills += partida[quant_partidas].jogadores_partida[i].num_kills;
    return totalpontos.todas_kills;
}

int Assistencia(int i) {
    //Guardar o numero total de assistencias para usar na funcao menu7().
    totalpontos.todas_assistencia += partida[quant_partidas].jogadores_partida[i].num_assistencias;
    return  totalpontos.todas_assistencia;
}

int Pontuacao(int i) {
    //Calcular e guardar a pontuacao total de cada jogador para usar na funcao menu3(), menu8(), menu9().
    time.jogadores[i].pontos_jogador += partida[quant_partidas].jogadores_partida[i].num_assistencias + (partida[quant_partidas].jogadores_partida[i].num_kills * 3);
    return time.jogadores[i].pontos_jogador;
}

int Pontos(int ponto, int i) {
    //Calcular a potuacao de cada jogador
    ponto = partida[quant_partidas].jogadores_partida[i].num_assistencias + (partida[quant_partidas].jogadores_partida[i].num_kills * 3);
    return ponto;
}

//Funcao para listar todas as partidas cadastradas.
void menu5() {
    bool verdade;
    printf("\n-----------------LISTAR PARTIDAS-----------------\n\n");
    printf("      ---------------------------------------\n");
    //A variavel "quant_partidas" vira parametro no for, para que saia do loop quando as informacoes de todas as partidas sejam listadas.
    for (int i = 0; i < quant_partidas; i++) {
        verdade = confirmar(partida[i].vitoria);
        if (verdade == true) {
            printf("\t\t      Vitotia!\n");
        }
        else {
            printf("\t\t      Derrota!\n");
        }
        printf("\tKills do time: %d\n", partida[i].total_kills_time);
        printf("\tDeaths do time: %d\n", partida[i].total_kills_adversario);
        printf("\tTorres destruidas pelo time: %d\n", partida[i].total_torres_destruidas_time);
        printf("\tTorres destruidas pelo adversario: %d\n\n", partida[i].total_torres_destruidas_adversario);
        printf("\tPosicao destaque:\n\t\t%-10s %-10s\n", "Nome", "Posicao");
        printf("\t\t%-10s %-10s\n", partida[i].destaque_nome, partida[i].destaque_posicao);
        printf("      ---------------------------------------\n");
    }
}

//Funcao para pesquisar um jogador.
void menu6() {
    int i;
    printf("\n----------------PESQUISAR JOGADOR----------------\n\n");
    printf("Digite o ID do jogador que voce deseja pesquisar: ");
    scanf("%d", &partida->id_jogador);
    //Verificar se o ID eh valido.
    if (partida->id_jogador < 1 || partida->id_jogador>5) {
        printf("Jogador nao existe!\n");
    }
    else {
        i = partida->id_jogador - 1;
        //Listar as informacoes do jogador.
        printf("\n\t%-5s %-10s %-10s %-10s\n", "ID", "Nome", "Posicao", "Pontuacao");
        printf("\t%-5d %-10s %-10s %-10d\n\n", time.jogadores[i].id, time.jogadores[i].nome, time.jogadores[i].posicao, time.jogadores[i].pontos_jogador);
    }
}

//Funcao para mostrar o numero total de kills e assistencias (de todas as partidas juntas).
void menu7() {
    printf("\n----------TOTAL DE KILLS E ASSISTENCIAS----------\n\n");
    printf("\n\t%-15s    %-15s\n", "Total de kills", "Totalde assistencias");
    printf("\t%-15d    %-15d\n\n", totalpontos.todas_kills, totalpontos.todas_assistencia);
}

//Funcao para mostar o jogador com menor pontuacao.
void menu8() {
    printf("\n-----------JOGADOR COM MENOR PONTUACAO-----------\n\n");

    //Iniciar as variaveis com os valores do 1o jogador
    int indicador = 0;//Essa variavel vai ser usada para acessar as informacoes do jogador.
    totalpontos.menor_pontuacao = time.jogadores[0].pontos_jogador;

    //Quando uma pontuacao for menor do que a da variavel "menor_pontuacao", a variavel recebe esse valor e o indicador recebe o valor de i.
    for (int i = 0; i < 5; i++) {
        if (totalpontos.menor_pontuacao > time.jogadores[i].pontos_jogador) {
            totalpontos.menor_pontuacao = time.jogadores[i].pontos_jogador;
            indicador = i;
        }
    }
    printf("\n\t%-5s %-10s %-10s %-10s\n", "ID", "Nome", "Posicao", "Pontuacao");
    printf("\t%-5d %-10s %-10s %-10d\n\n", time.jogadores[indicador].id, time.jogadores[indicador].nome, time.jogadores[indicador].posicao, time.jogadores[indicador].pontos_jogador);
}

//Funcao para mostar o jogador com maior pontuacao.
void menu9() {
    printf("\n-----------JOGADOR COM MAIOR PONTUACAO-----------\n\n");

    //Iniciar as variaveis com os valores do 1o jogador
    int indicador = 0; //Essa variavel vai ser usada para acessar as informacoes do jogador.
    totalpontos.maior_pontuacao = time.jogadores[0].pontos_jogador;

    //Quando uma pontuacao for maior do que a da variavel "maior_pontuacao", a variavel recebe esse valor e o indicador recebe o valor de i.
    for (int i = 0; i < 5; i++) {
        if (totalpontos.maior_pontuacao < time.jogadores[i].pontos_jogador) {
            totalpontos.maior_pontuacao = time.jogadores[i].pontos_jogador;
            indicador = i;
        }
    }
    printf("\n\t%-5s %-10s %-10s %-10s\n", "ID", "Nome", "Posicao", "Pontuacao");
    printf("\t%-5d %-10s %-10s %-10d\n\n", time.jogadores[indicador].id, time.jogadores[indicador].nome, time.jogadores[indicador].posicao, time.jogadores[indicador].pontos_jogador);
}