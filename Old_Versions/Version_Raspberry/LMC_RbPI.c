/*
Desenvolvido por: Lucas Darlindo Freitas Rodrigues (lucas.darlindo@gmail.com) e Octacílio Carvalho de Almeida (octa.oca44@gmail.com)
Instituição.....: Universidade Federal do Oeste do Pará, Instituto de Engenharia e Geociências
Curso...........: Bacharelado em Ciência da Computação (BCC 2018)
Código original.: 01 de Abril de 2019 - 02h30min (Horário Oficial de Brasília, GMT-3)
Criado em.......: 12 de Abril de 2019 - 17h00min (Horário Oficial de Brasília, GMT-3)
Atualizado em...: 18 de Abril de 2019 - 11h30min (Horário Oficial de Brasília, GMT-3)

Versão em adaptação para a plataforma do Raspberry Pi, a fim de uma prototipagem para o trabalho final da disciplina de Arquitetura
*/

// Bibliotecas Utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Variáveis de controle e armazenamento globais
short int one = 0;
short int overflow = 0;
short int execution = 0;
short int firstBool[8], secondBool[8], resultado[8];

// Interface: exibição do estágio da soma binária de oito bits
void sumStage (short int a, short int *v1, short int *v2) {
    switch (a) {
        case 1:
            puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
            puts  ("|----------------------------------------------------- Fase 01: Soma do 8º Bit ------------------------------------------------|");
            puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
            puts  ("|                                                                                                                              |");
            printf("|                                                          %hd %hd %hd %hd %hd %hd %hd |%hd|                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
            printf("|                                                         +%hd %hd %hd %hd %hd %hd %hd |%hd|                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            break;
        case 2:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|----------------------------------------------------- Fase 02: Soma do 7º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                                                                              |");
                printf("|                                                          %hd %hd %hd %hd %hd %hd |%hd| %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd %hd %hd %hd %hd |%hd| %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            } else {
                puts  ("|----------------------------------------------------- Fase 02: Soma do 7º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                        |1|                                                             |");
                printf("|                                                          %hd %hd %hd %hd %hd %hd |%hd| %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd %hd %hd %hd %hd |%hd| %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            }
            break;
        case 3:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|----------------------------------------------------- Fase 03: Soma do 6º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                                                                              |");
                printf("|                                                          %hd %hd %hd %hd %hd |%hd| %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd %hd %hd %hd |%hd| %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            } else {
                puts  ("|----------------------------------------------------- Fase 03: Soma do 6º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                    |1|                                                       |");
                printf("|                                                          %hd %hd %hd %hd %hd |%hd| %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd %hd %hd %hd |%hd| %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            }
            break;
        case 4:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|----------------------------------------------------- Fase 04: Soma do 5º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                                                                              |");
                printf("|                                                          %hd %hd %hd %hd |%hd| %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd %hd %hd |%hd| %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            } else {
                puts  ("|----------------------------------------------------- Fase 04: Soma do 5º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                               |1|                                                                           |");
                printf("|                                                          %hd %hd %hd %hd |%hd| %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd %hd %hd |%hd| %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            }
            break;
        case 5:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|----------------------------------------------------- Fase 05: Soma do 4º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                                                                              |");
                printf("|                                                          %hd %hd %hd |%hd| %hd %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd %hd |%hd| %hd %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            } else {
                puts  ("|----------------------------------------------------- Fase 05: Soma do 4º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                |1|                                                        |");
                printf("|                                                          %hd %hd %hd |%hd| %hd %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd %hd |%hd| %hd %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            }
            break;
        case 6:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|----------------------------------------------------- Fase 06: Soma do 3º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                                                                              |");
                printf("|                                                          %hd %hd |%hd| %hd %hd %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd |%hd| %hd %hd %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            } else {
                puts  ("|----------------------------------------------------- Fase 06: Soma do 3º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                        |1|                                                                                 |");
                printf("|                                                          %hd %hd |%hd| %hd %hd %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd %hd |%hd| %hd %hd %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            }
            break;
        case 7:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|----------------------------------------------------- Fase 07: Soma do 2º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                                                                              |");
                printf("|                                                          %hd |%hd| %hd %hd %hd %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd |%hd| %hd %hd %hd %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            } else {
                puts  ("|----------------------------------------------------- Fase 07: Soma do 2º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                  |1|                                                                         |");
                printf("|                                                          %hd |%hd| %hd %hd %hd %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +%hd |%hd| %hd %hd %hd %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            }
            break;
        case 8:
            if (one == 0) {
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|----------------------------------------------------- Fase 08: Soma do 1º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                                                                                              |");
                printf("|                                                          |%hd| %hd %hd %hd %hd %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +|%hd| %hd %hd %hd %hd %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            } else {
                puts  ("|----------------------------------------------------- Fase 08: Soma do 1º Bit ------------------------------------------------|");
                puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
                puts  ("|                                                 |1|                                                                                         |");
                printf("|                                                          |%hd| %hd %hd %hd %hd %hd %hd %hd                                                   |\n", v1[0], v1[1], v1[2], v1[3], v1[4], v1[5], v1[6], v1[7]);
                printf("|                                                         +|%hd| %hd %hd %hd %hd %hd %hd %hd                                                   |\n", v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7]);
            }
            break;
    }
}

// Lógica: implementação para execução das regras de soma binária
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

// Lógica adicional: implementação da regra (1+1 = 0, e vai 1)
short int complement (short int a, short int b) {
    short int tmp, res;
    tmp = binaryLogic(1, a);
    res = binaryLogic(tmp, b);
    return res;
}

// Interface: exibição formatada do valor binário
void displayBin (short int *a) {
    short int i = 0;

    printf("( ");
    for (i = 0; i < 8; i++) {
        printf("%hd ", a[i]);
    }
    printf(")");
}

// Interface: exibição das regras de soma binária
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

// Lógica: implementação para execução da validação e conversão binário-decimal
int decimalLogic (short int *a) {
    int i, decimalBase = 0;
    int j = 0;

    for (i = 7; i >= 0; i--) {
        decimalBase += (a[i] * (pow(2, j)));
        j++;
    }
    return decimalBase;
}

// Lógica: implementação da função mestre de soma binária (integração lógica)
void logicSum (short int *a, short int *b) {
    short int i;

    for (i = 7; i >= 0; i--) {
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

// Lógica + Interface: implementação da função mestre para validação da soma binária (conversão bin-dec) e exibição ao usuário
void verifyingSum (short int *a, short int *b) {
    short int i;
    int firstDec, secondDec, resultDec;

    logicSum(a, b);

    firstDec = decimalLogic(a);
    secondDec = decimalLogic(b);
    resultDec = firstDec + secondDec;

    puts("|------------------------------------------------- Verificação Binário/Decimal -------------------------------------------------|");
    puts("");
    printf(" Soma na forma binária: ");
    displayBin(a);
    printf(" + ");
    displayBin(b);
    printf(" = ");
    displayBin(resultado);
    puts("");
    printf(" Soma na forma decimal: %d + %d = %d\n\n", firstDec, secondDec, resultDec);
    puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
}

// Interface: exibição do deslocamento dos resultados em cada etapa da soma binária
void binarySum (short int *a, short int *b) {
    short int i, j;
    j = 1;

    logicSum(a, b);
    for (i = 7; i >= 0; i--) {
        if (i == 7) {
            sumStage(j, a, b);
            puts("|                                                      ------------------------                                                |");
            printf("|                                                                        |%hd|                                                   |\n", resultado[i]);
        } else if (i == 6) {
            if (a[i] == 1 && b[i] == 1 && one == 1){
                one = 0;
                sumStage(j, a, b);
                one = 1;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                                      ------------------------                                                |");
            printf("|                                                                      |%hd| %hd                                                   |\n", resultado[i], resultado[i+1]);
        } else if (i == 5) {
            if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                sumStage(j, a, b);
                one = 0;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                                      ------------------------                                                |");
            printf("|                                                                    |%hd| %hd %hd                                                   |\n", resultado[i], resultado[i+1], resultado[i+2]);
        } else if (i == 4) {
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
            puts("|                                                      ------------------------                                                |");
            printf("|                                                                  |%hd| %hd %hd %hd                                                   |\n", resultado[i], resultado[i+1], resultado[i+2], resultado[i+3]);
        } else if (i == 3) {
            if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                sumStage(j, a, b);
                one = 0;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                                      ------------------------                                                |");
            printf("|                                                                |%hd| %hd %hd %hd %hd                                                   |\n", resultado[i], resultado[i+1], resultado[i+2], resultado[i+3], resultado[i+4]);
        } else if (i == 2) {
            if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                sumStage(j, a, b);
                one = 0;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                                      ------------------------                                                |");
            printf("|                                                              |%hd| %hd %hd %hd %hd %hd                                                   |\n", resultado[i], resultado[i+1], resultado[i+2], resultado[i+3], resultado[i+4], resultado[i+5]);
        } else if (i == 1) {
            if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                sumStage(j, a, b);
                one = 0;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                                      ------------------------                                                |");
            printf("|                                                            |%hd| %hd %hd %hd %hd %hd %hd                                                   |\n", resultado[i], resultado[i+1], resultado[i+2], resultado[i+3], resultado[i+4], resultado[i+5], resultado[i+6]);
        } else if (i == 0) {
            if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                sumStage(j, a, b);
                one = 0;
            } else {
                sumStage(j, a, b);
            }
            puts("|                                                      ------------------------                                                |");
            printf("|                                                          |%hd| %hd %hd %hd %hd %hd %hd %hd                                                   |\n", resultado[i], resultado[i+1], resultado[i+2], resultado[i+3], resultado[i+4], resultado[i+5], resultado[i+6], resultado[i+7]);
        }
        puts("|------------------------------------------------------------------------------------------------------------------------------|");
        j++;
        }
    
    printf("|                             Soma entre ");
    displayBin(a);
    printf(" e ");
    displayBin(b);
    printf(" = ");
    if (overflow == 1) {
        printf("%hd ", overflow);
    }
    displayBin(resultado);
    printf("                       |\n\n");
}

// Interfaces: menu principal da aplicação (construir no padrão 128 linhas por 64 colunas)
void binaryToDecimal (short int *a) {
    short int i = 7;
    short int j = 0;
    int conv = decimalLogic(a);
    puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
    puts  ("|----------------------------------------------- Conversão Binário-Decimal (2^n) ----------------------------------------------|");
    puts  ("|------------------------------------------------------------------------------------------------------------------------------|");
    printf("|                                                      %hd %hd %hd %hd %hd %hd %hd %hd                                                         |\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    printf("|                                                      | | | | | | | |------[ %hd * (2^%hd) ] = %.0f                                  |\n", a[i], j, (a[i]*(pow(2, j))));
    i--;
    j++;
    printf("|                                                      | | | | | | |--------[ %hd * (2^%hd) ] = %.0f                                  |\n", a[i], j, (a[i]*(pow(2, j))));
    i--;
    j++;
    printf("|                                                      | | | | | |----------[ %hd * (2^%hd) ] = %.0f                                  |\n", a[i], j, (a[i]*(pow(2, j))));
    i--;
    j++;
    printf("|                                                      | | | | |------------[ %hd * (2^%hd) ] = %.0f                                  |\n", a[i], j, (a[i]*(pow(2, j))));
    i--;
    j++;
    printf("|                                                      | | | |--------------[ %hd * (2^%hd) ] = %.0f                                 |\n", a[i], j, (a[i]*(pow(2, j))));
    i--;
    j++;
    printf("|                                                      | | |----------------[ %hd * (2^%hd) ] = %.0f                                  |\n", a[i], j, (a[i]*(pow(2, j))));
    i--;
    j++;
    printf("|                                                      | |------------------[ %hd * (2^%hd) ] = %.0f                                  |\n", a[i], j, (a[i]*(pow(2, j))));
    i--;
    j++;
    printf("|                                                      |--------------------[ %hd * (2^%hd) ] = %.0f                                  |\n", a[i], j, (a[i]*(pow(2, j))));
    puts  ("|                                                                         --------------------- (Soma)                         |");
    printf("|                                                                                    %d                                        |\n", conv);
}

// Interface + Controle: função mestre para chamada dos principais métodos da aplicação
void controller (short int option) {
    switch (option) {
        case 1: // Exibição da tabela de regras para a soma binária
            binaryRules();
            break;
        case 2: // Execução da soma binária, passo a passo (demonstrativo)
            printf(" 1) Digite o primeiro valor (8 Bits ~ Bit a Bit): ");
            scanf("%hd%hd%hd%hd%hd%hd%hd%hd", &firstBool[0], &firstBool[1], &firstBool[2], &firstBool[3], &firstBool[4], &firstBool[5], &firstBool[6], &firstBool[7]);
            printf(" 2) Digite o segundo valor (8 Bits ~ Bit a Bit).: ");
            scanf("%hd%hd%hd%hd%hd%hd%hd%hd", &secondBool[0], &secondBool[1], &secondBool[2], &secondBool[3], &secondBool[4], &secondBool[5], &secondBool[6], &secondBool[7]);
            printf("\n");
                
            binarySum(firstBool, secondBool);
            break;
        case 3: // Verificação da soma feita (converter para decimal, somar e exibir o resultado)
            verifyingSum(firstBool, secondBool);
            break;
        case 4: // Conversor Binário para Decimal
            printf(" Digite o valor para conversão (8 Bits ~ Bit a Bit): ");
            scanf("%hd%hd%hd%hd%hd%hd%hd%hd", &firstBool[0], &firstBool[1], &firstBool[2], &firstBool[3], &firstBool[4], &firstBool[5], &firstBool[6], &firstBool[7]);
            binaryToDecimal(firstBool);
            break;
        case 5: // Conversor Decimal para Binário
            break;
        case 6: // Complemento de dois
            break;     
        } // Close key of switch ()
}

// (4) Interface + Controle: bloco para exibição e seleção da opção desejada ao usuário, assim como controle de execução
void menu () {
    system("clear");
    // Variáveis de controle da função:
    short int option;

    // Interface do usuário
    puts("|---------------------------------------------------- Somador Binário (8 Bits) ------------------------------------------------|");
    puts("|--------------------------------------------------------- Versão: 1.0.0 ------------------------------------------------------|");
    puts("|---------------------------------------------------- Plataforma: Raspberry Pi ------------------------------------------------|\n");    
    puts("|-------------------------------------------------------------- MENU ----------------------------------------------------------|");
    puts("|                                     |1|    Exibir tabela de regras para as somas binárias                                    |");
    puts("|                                     |2|            Realizar uma soma binária                                                 |");
    puts("|                                     |3|       Verificar a validade da soma binária                                           |");
    puts("|                                     |4|         Conversor Binário para Decimal                                               |");
    puts("|                                     |5|         Conversor Decimal para Binário                                               |");
    puts("|                                     |6|               Complemento de dois                                                    |");
    puts("|------------------------------------------------------------------------------------------------------------------------------|");

    do {
        printf("Digite a operação desejada: ");
        scanf("%hd", &option);
        if (option < 0 || option > 6) {
            puts("Opção inexistente! Tente novamente.");
        }
    } while (option < 1 || option > 6);

    system("clear");
    controller(option);
}

void startup () {
    system("clear");
    puts("|---------------------------------------------------- Somador Binário (8 Bits) ------------------------------------------------|");
    puts("|--------------------------------------------------------- Versão: 1.0.0 ------------------------------------------------------|");
    puts("|---------------------------------------------------- Plataforma: Raspberry Pi ------------------------------------------------|");
    puts("|--------------------------- Desenvolvido por: Lucas Darlindo F. Rodrigues e Octacílio C. de Almeida --------------------------|\n");
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