/*
Desenvolvido por: Lucas Darlindo Freitas Rodrigues (lucas.darlindo@gmail.com)
Instituição.....: Universidade Federal do Oeste do Pará, Instituto de Engenharia e Geociências
Curso...........: Bacharelado em Ciência da Computação (BCC 2018)
Código original.: 01 de Abril de 2019 - 02h30min (Horário Oficial de Brasília, GMT-3)
Criado em.......: 01 de Abril de 2019 - 14h20min (Horário Oficial de Brasília, GMT-3)
Atualizado em...: 01 de Abril de 2019 - 16h23min (Horário Oficial de Brasília, GMT-3)

Versão adaptada para a plataforma Arduino, a fim de uma prototipagem para o trabalho final da disciplina de Arquitetura
*/

// Bibliotecas Utilizadas (ainda em padrão da Linguagem C)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis de controle e armazenamento globais
short int one = 0;
short int overflow = 0;
short int execution = 0;
short int firstBool[4], secondBool[4], resultado[4];

void sumStage (short int a, short int *v1, short int *v2) {
    switch (a) {
        case 1:
            puts  ("|------------------------------------------------------------------------------|");
            puts  ("|--------------------------- Fase 01: Soma do 4º Bit --------------------------|");
            puts  ("|------------------------------------------------------------------------------|");
            puts  ("|                                                                              |");
            printf("|                                    %hd %hd %hd |%hd|                                 |\n", v1[0], v1[1], v1[2], v1[3]);
            printf("|                                   +%hd %hd %hd |%hd|                                 |\n", v2[0], v2[1], v2[2], v2[3]);
            break;
        case 2:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|--------------------------- Fase 02: Soma do 3º Bit --------------------------|");
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|                                                                              |");
                printf("|                                    %hd %hd |%hd| %hd                                 |\n", v1[0], v1[1], v1[2], v1[3]);
                printf("|                                   +%hd %hd |%hd| %hd                                 |\n", v2[0], v2[1], v2[2], v2[3]);
            } else {
                puts  ("|--------------------------- Fase 02: Soma do 3º Bit --------------------------|");
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|                                        |1|                                   |");
                printf("|                                    %hd %hd |%hd| %hd                                 |\n", v1[0], v1[1], v1[2], v1[3]);
                printf("|                                   +%hd %hd |%hd| %hd                                 |\n", v2[0], v2[1], v2[2], v2[3]);
            }
            break;
        case 3:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|--------------------------- Fase 03: Soma do 2º Bit --------------------------|");
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|                                                                              |");
                printf("|                                    %hd |%hd| %hd %hd                                 |\n", v1[0], v1[1], v1[2], v1[3]);
                printf("|                                   +%hd |%hd| %hd %hd                                 |\n", v2[0], v2[1], v2[2], v2[3]);
            } else {
                puts  ("|--------------------------- Fase 03: Soma do 2º Bit --------------------------|");
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|                                      |1|                                     |");
                printf("|                                    %hd |%hd| %hd %hd                                 |\n", v1[0], v1[1], v1[2], v1[3]);
                printf("|                                   +%hd |%hd| %hd %hd                                 |\n", v2[0], v2[1], v2[2], v2[3]);
            }
            break;
        case 4:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|--------------------------- Fase 04: Soma do 1º Bit --------------------------|");
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|                                                                              |");
                printf("|                                    |%hd| %hd %hd %hd                                 |\n", v1[0], v1[1], v1[2], v1[3]);
                printf("|                                   +|%hd| %hd %hd %hd                                 |\n", v2[0], v2[1], v2[2], v2[3]);
            } else {
                puts  ("|--------------------------- Fase 04: Soma do 1º Bit --------------------------|");
                puts  ("|------------------------------------------------------------------------------|");
                puts  ("|                                |1|                                           |");
                printf("|                                    |%hd| %hd %hd %hd                                 |\n", v1[0], v1[1], v1[2], v1[3]);
                printf("|                                   +|%hd| %hd %hd %hd                                 |\n", v2[0], v2[1], v2[2], v2[3]);
            }
            break;
    }
}

short int binaryLogic (short int a, short int b) {
    short int logic;
    if (a == 0 && b == 0) {
        one = 0;
        logic = 0;
    } else if (a == 1 && b == 0) {
        one = 0;
        logic = 1;
    } else if (a == 0 && b == 1) {
        one = 0;
        logic = 1;
    } else if (a == 1 && b == 1) {
        one = 1;
        logic = 0;
    }

    return logic;
}

short int complement (short int a, short int b) {
    short int tmp, res;
    tmp = binaryLogic(1, a);
    res = binaryLogic(tmp, b);
    return res;
}

void displayBin (short int *a) {
    short int i = 0;

    printf("( ");
    for (i = 0; i < 4; i++) {
        printf("%hd ", a[i]);
    }
    printf(")");
}

void binaryRules () {
    puts("|------------------------------------------------------------------------------------------------------------------------------|");
    puts("|          Regra Nº1          |          Regra Nº2          |          Regra Nº3          |              Regra Nº4             |");
    puts("|          0 + 0 = 0          |          1 + 0 = 1          |          0 + 1 = 1          |          1 + 1 = 0 (vai um)        |");
    puts("|-----------------------------|-----------------------------|-----------------------------|------------------------------------|");
    puts("|         Exemplo Nº1         |         Exemplo Nº2         |         Exemplo Nº3         |             Exemplo Nº4            |");
    puts("|           0000 (0)          |           0001 (1)          |           0000 (0)          |          0010 (2)  } 00¹00         |");
    puts("|          +0010 (2)          |          +0010 (2)          |          +0101 (5)          |         +0010 (2)  }               |");
    puts("|-----------------------------|-----------------------------|-----------------------------|------------------------------------|");
    puts("|           0010 (2)          |           0011 (3)          |           0101 (5)          |               0100 (4)             |");
    puts("|------------------------------------------------------------------------------------------------------------------------------|");
}

int decimalLogic (int a) {
    int decimalBase;
    switch (a) {
        case 0000:
            decimalBase = 0;
            break;
        case 0001:
            decimalBase = 1;
            break;
        case 0010:
            decimalBase = 2;
            break;
        case 0011:
            decimalBase = 3;
            break;
        case 0100:
            decimalBase = 4;
            break;
        case 0101:
            decimalBase = 5;
            break;
        case 0110:
            decimalBase = 6;
            break;
        case 0111:
            decimalBase = 7;
            break;
        case 1000:
            decimalBase = 8;
            break;
        case 1001:
            decimalBase = 9;
            break;
        case 1010:
            decimalBase = 10;
            break;
        case 1011:
            decimalBase = 11;
            break;
        case 1100:
            decimalBase = 12;
            break;
        case 1101:
            decimalBase = 13;
            break;
        case 1110:
            decimalBase = 14;
            break;
        case 1111:
            decimalBase = 15;
            break;
    }

    return decimalBase;
}

int concatBin (short int *a) {
    short int i = 0;
    int binario;
    if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 0) {
        binario = 0000; // 0
    } else if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 1) {
        binario = 0001; // 1
    } else if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 0) {
        binario = 0010; // 2
    } else if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 1) {
        binario = 0011; // 3
    } else if (a[i] == 0 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 0) {
        binario = 0100; // 4
    } else if (a[i] == 0 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 1) {
        binario = 0101; // 5
    } else if (a[i] == 0 && a[i+1] == 1 && a[i+2] == 1 && a[i+3] == 0) {
        binario = 0110; // 6
    } else if (a[i] == 0 && a[i+1] == 1 && a[i+2] == 1 && a[i+3] == 1) {
        binario = 0111; // 7
    } else if (a[i] == 1 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 0) {
        binario = 1000; // 8
    } else if (a[i] == 1 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 1) {
        binario = 1001; // 9
    } else if (a[i] == 1 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 0) {
        binario = 1010; // 10
    } else if (a[i] == 1 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 1) {
        binario = 1011; // 11
    } else if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 0) {
        binario = 1100; // 12
    } else if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 1) {
        binario = 1101; // 13
    } else if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 1) {
        binario = 1110; // 14
    } else if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 1 && a[i+3] == 1) {
        binario = 1111; // 15
    }

    return binario;
}

void logicSum (short int *a, short int *b) {
    short int i;

    for (i = 3; i >= 0; i--) {
        if (one == 1) {
            resultado[i] = complement(a[i], b[i]);
        } else {
            resultado[i] = binaryLogic(a[i], b[i]);
        }
        
        if (i == 0 && a[i] == 1 && b[i] == 1) {
            overflow = 1;
        }
    }

    // Reset das variáveis de controle global e retorno da função
    one = 0;
    overflow = 0;
}

// Ajustar e modularizar a parte lógica e a interface
void verifyingSum (short int *a, short int *b) {
    short int i;
    int firstBin, secondBin;
    int firstDec, secondDec, resultDec;

    firstBin = concatBin(a);
    secondBin = concatBin(b);
    logicSum(a, b);

    firstDec = decimalLogic(firstBin);
    secondDec = decimalLogic(secondBin);
    resultDec = firstDec + secondDec;

    puts("|------------------------ Verificação Binário/Decimal -------------------------|");
    puts("");
    printf(" Soma na forma binária: ");
    displayBin(a);
    printf(" + ");
    displayBin(b);
    printf(" = ");
    displayBin(resultado);
    puts("");
    printf(" Soma na forma decimal: %d + %d = %d\n\n", firstDec, secondDec, resultDec);
    puts("|------------------------------------------------------------------------------|");
}

void binarySum (short int *a, short int *b) {
    short int i, j;
    j = 1;

    logicSum(a, b);
    for (i = 3; i >= 0; i--) {
        if (i == 3) {
            sumStage(j, a, b);
            puts("|                                  -------------                               |");
            printf("|                                          |%hd|                                 |\n", resultado[i]);
        } else if (i == 2) {
            if (a[i] == 1 && b[i] == 1 && one == 1){
                one = 0;
                sumStage(j, a, b);
                one = 1;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                  -------------                               |");
            printf("|                                        |%hd| %hd                                 |\n", resultado[i], resultado[i+1]);
        } else if (i == 1) {
            if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                sumStage(j, a, b);
                one = 0;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                  -------------                               |");
            printf("|                                      |%hd| %hd %hd                                 |\n", resultado[i], resultado[i+1], resultado[i+2]);
        } else if (i == 0) {
            if (overflow == 1) {
                one = 1;
                sumStage(j, a, b);
                one = 0;
            } else if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                sumStage(j, a, b);
                one = 0;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                  -------------                               |");
            printf("|                                    |%hd| %hd %hd %hd                                 |\n", resultado[i], resultado[i+1], resultado[i+2], resultado[i+3]);
        }
        puts("|------------------------------------------------------------------------------|");
        j++;
        }
    
    printf("|                    Soma entre ");
    displayBin(a);
    printf("e ");
    displayBin(b);
    printf("= ");
    if (overflow == 1) {
        printf("%hd ", overflow);
    }
    displayBin(resultado);
    printf("                   |\n\n");
}

// Interfaces: menu principal da aplicação (construir no padrão 128 linhas por 64 colunas)
void binaryToDecimal () {
    // Implementar.
}

void controller (short int option) {
    switch (option) {
        case 1: // Exibição da tabela de regras para a soma binária
            binaryRules();
            break;
        case 2: // Execução da soma binária, passo a passo (demonstrativo)
            printf(" 1) Digite o primeiro valor (4 Bits ~ Bit a Bit): ");
            scanf("%hd%hd%hd%hd", &firstBool[0], &firstBool[1], &firstBool[2], &firstBool[3]);
            printf(" 2) Digite o segundo valor (4 Bits ~ Bit a Bit).: ");
            scanf("%hd%hd%hd%hd", &secondBool[0], &secondBool[1], &secondBool[2], &secondBool[3]);
            printf("\n");
                
            binarySum(firstBool, secondBool);
            break;
        case 3: // Verificação da soma feita (converter para decimal, somar e exibir o resultado)
            verifyingSum(firstBool, secondBool);
            break;                
        } // Close key of switch ()
}

void menu () {
    system("clear");
    // Variáveis de controle da função:
    short int option;

    // Interface do usuário
    puts("|-------------------------------------------------------- Somador Binário -----------------------------------------------------|");
    puts("|------------------------------------------------------ Versão: 1.0.0 Debug ---------------------------------------------------|");
    puts("|------------------------------------------------------- Plataforma Arduino ---------------------------------------------------|\n");        
    puts("|-------------------------------------------------------------- MENU ----------------------------------------------------------|");
    puts("|                                     |1|    Exibir tabela de regras para as somas binárias                                    |");
    puts("                                      |2|        Realizar uma soma binária (4 bits)                                            |");
    puts("                                      |3| Verificar a validade da soma (Binário para Decimal)                                  |");
    puts("|------------------------------------------------------------------------------------------------------------------------------|");

    do {
        printf("Digite a operação desejada: ");
        scanf("%hd", &option);
        if (option < 0 || option > 3) {
            puts("Opção inexistente! Tente novamente.");
        }
    } while (option < 1 || option > 3);

    system("clear");
    controller(option);
}

void startup () {
    system("clear");
    puts("|-------------------------------------------------------- Somador Binário -----------------------------------------------------|");
    puts("|------------------------------------------------------ Versão: 1.0.0 Debug ---------------------------------------------------|");
    puts("|------------------------------------------------------- Plataforma Arduino ---------------------------------------------------|");
    puts("|------------------------------------------ Desenvolvido por: Lucas Darlindo F. Rodrigues -------------------------------------|\n");
    puts("|--------------------------------------------------- Tecle ENTER para continuar -----------------------------------------------|");

    getchar();

    execution = 1;
}

void reset () {
    system("clear");
    one = 0;
    overflow = 0;

    startup();
    menu();
}

void askUser () {
    if (execution == 1) {
        puts("|------------------------------------------------- Deseja retornar para o menu? -----------------------------------------------|");
        puts("|------------------------------------------------------ (1) Sim | (0) Não -----------------------------------------------------|");
        puts("|------------------------------------------------------------------------------------------------------------------------------|");
        do {
            printf("Digite a opção desejada: ");
            scanf("%hd", &execution);

            if (execution < 0 || execution > 1) {
                puts("Opção inexistente! Tente novamente.");
            }
        } while (execution < 0 || execution > 1);    
    }
}

void main () {
    // Executar a inicialização da interface de usuário (metadados)
    startup();

    // Execução e controle da execução do programa + interface de usuário (menu principal da aplicação)
    while (execution == 1) {
        menu();
        askUser();
    }
    
    reset();
}