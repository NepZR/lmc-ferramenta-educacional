/*
- Código desenvolvido por: Lucas Darlindo Freitas Rodrigues (lucas.darlindo@gmail.com)
- Instituição............: Universidade Federal do Oeste do Pará, Instituto de Engenharia e Geociências
- Curso..................: Bacharelado em Ciência da Computação (BCC 2018)
- Criado em..............: 01 de Abril de 2019 - 02:30 (Horário Oficial de Brasília, GMT-3)
- Atualizado em..........: 04 de Abril de 2019 - 14:02 (Horário Oficial de Brasília, GMT-3)

- Ferramenta desenvolvida como meio educacional de demonstração para a soma binária (4 bits) na disciplina de Arquitetura
  de computadores, no terceiro semestre do curso, no ano de 2019.
*/

// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis de controle global
short int one = 0;
short int outline = 0;

// Função lógica: conversão de binário para decimal
int logicaDecimal (char *a) {
    if (strcmp(a, '0000')) {
        return 0;
    } else if (strcmp(a, '0001')) {
        return 1;
    } else if (strcmp(a, '0010')) {
        return 2;
    } else if (strcmp(a, '0011')) {
        return 3;
    } else if (strcmp(a, '0100')) {
        return 4;
    } else if (strcmp(a, '0101')) {
        return 5;
    } else if (strcmp(a, '0110')) {
        return 6;
    } else if (strcmp(a, '0111')) {
        return 7;
    } else if (strcmp(a, '1000')) {
        return 8;
    } else if (strcmp(a, '1001')) {
        return 9;
    } else if (strcmp(a, '1010')) {
        return 10;
    } else if (strcmp(a, '1011')) {
        return 11;
    } else if (strcmp(a, '1100')) {
        return 12;
    } else if (strcmp(a, '1101')) {
        return 13;
    } else if (strcmp(a, '1110')) {
        return 14;
    } else if (strcmp(a, '1111')) {
        return 15;
    }
}

// Função auxiliar lógica: concatenação do binário em vetor para uma única instância
int concatBin (short int *a) {
    short int i = 0;
    char binario[4];
    if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 0) {
        strcat(binario, '0000');
    } else if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 1) {
        strcat(binario, '0001');
    } else if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 0) {
        strcat(binario, '0010');
    } else if (a[i] == 0 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 1) {
        strcat(binario, '0011');
    } else if (a[i] == 0 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 0) {
        strcat(binario, '0100');
    } else if (a[i] == 0 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 1) {
        strcat(binario, '0101');
    } else if (a[i] == 0 && a[i+1] == 1 && a[i+2] == 1 && a[i+3] == 0) {
        strcat(binario, '0110');
    } else if (a[i] == 0 && a[i+1] == 1 && a[i+2] == 1 && a[i+3] == 1) {
        strcat(binario, '0111');
    } else if (a[i] == 1 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 0) {
        strcat(binario, '1000');
    } else if (a[i] == 1 && a[i+1] == 0 && a[i+2] == 0 && a[i+3] == 1) {
        strcat(binario, '1001');
    } else if (a[i] == 1 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 0) {
        strcat(binario, '1010');
    } else if (a[i] == 1 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 1) {
        strcat(binario, '1011');
    } else if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 0) {
        strcat(binario, '1100');
    } else if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 1) {
        strcat(binario, '1101');
    } else if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 0 && a[i+3] == 1) {
        strcat(binario, '1110');
    } else if (a[i] == 1 && a[i+1] == 1 && a[i+2] == 1 && a[i+3] == 1) {
        strcat(binario, '1111');
    }

    return binario;
}

// Interface: fase da soma binária
void contadorPasso (short int a, short int *v1, short int *v2) {
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

// Interface: tabela descritiva acerca das regras de soma binária
void regrasBinaria () {
    puts ("|------------------------------------------------------------------------------|");
    puts ("|    Regra Nº1    |    Regra Nº2    |    Regra Nº3    |        Regra Nº4       |");
    puts ("|    0 + 0 = 0    |    1 + 0 = 1    |    0 + 1 = 1    |    1 + 1 = 0 (vai um)  |");
    puts ("|------------------------------------------------------------------------------|");
    puts ("|   Exemplo Nº1   |   Exemplo Nº2   |   Exemplo Nº3   |       Exemplo Nº4      |");
    puts ("|     0000 (0)    |     0001 (1)    |     0000 (0)    |    0010 (2)  } 00¹00   |");
    puts ("|    +0010 (2)    |    +0010 (2)    |    +0101 (5)    |   +0010 (2)  }         |");
    puts ("|-----------------|-----------------|-----------------|------------------------|");
    puts ("|     0010 (2)    |     0011 (3)    |     0101 (5)    |        0100 (4)        |");
    puts ("|------------------------------------------------------------------------------|");
} // Close key of regrasBinaria () 

// Função lógica: interpretação das somas por tempo de execução
short int logicaBinaria (short int a, short int b) {
    if (a == 0 && b == 0) {
        one = 0;
        return 0;
    } else if (a == 1 && b == 0) {
        one = 0;
        return 1;
    } else if (a == 0 && b == 1) {
        one = 0;
        return 1;
    } else if (a == 1 && b == 1) {
        one = 1;
        return 0;
    }
}

// Função lógica: soma binária incrementada ao binário '1' (1+x+y)
short int vaiUm (short int a, short int b) {
    short int tmp, res;
    tmp = logicaBinaria(1, a);
    res = logicaBinaria(tmp, b);
    return res;
}

// Função aritmética + interface: implementação das demais funções e exibição ao usuário
void soma_UI (short int *a, short int *b) {
    short int i, j;
    short int resultado[4];
    j = 1;

    for (i = 3; i >= 0; i--) {
        if (one == 1) {
            resultado[i] = vaiUm(a[i], b[i]);
        } else {
            resultado[i] = logicaBinaria(a[i], b[i]);
        }
        
        if (i == 0 && a[i] == 1 && b[i] == 1) {
            outline = 1;
        }
        // Ajustar lógica para a exibição na interface de forma correta!
        if (i == 3) {
            contadorPasso(j, a, b);
            puts("|                                  -------------                               |");
            printf("|                                          |%hd|                                 |\n", resultado[i]);
        } else if (i == 2) {
            if (a[i] == 1 && b[i] == 1 && one == 1){
                one = 0;
                contadorPasso(j, a, b);
                one = 1;
            } else {
                contadorPasso(j, a, b);
            }
            puts("|                                  -------------                               |");
            printf("|                                        |%hd| %hd                                 |\n", resultado[i], resultado[i+1]);
        } else if (i == 1) {
            if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                contadorPasso(j, a, b);
                one = 0;
            } else {
                contadorPasso(j, a, b);
            }
            puts("|                                  -------------                               |");
            printf("|                                      |%hd| %hd %hd                                 |\n", resultado[i], resultado[i+1], resultado[i+2]);
        } else if (i == 0) {
            if (outline == 1) {
                one = 1;
                contadorPasso(j, a, b);
                one = 0;
            } else if (a[i] == 0 && b[i] == 0 && resultado[i] == 1) {
                one = 1;
                contadorPasso(j, a, b);
                one = 0;
            } else {
                contadorPasso(j, a, b);
            }
            puts("|                                  -------------                               |");
            printf("|                                    |%hd| %hd %hd %hd                                 |\n", resultado[i], resultado[i+1], resultado[i+2], resultado[i+3]);
        }
        puts("|------------------------------------------------------------------------------|");
        j++;

        }
    
    printf("|                    Soma entre ");
    for (i = 0; i < 4; i++) {
        printf("%hd ", a[i]);
    }
    printf("e ");
    for (i = 0; i < 4; i++) {
        printf("%hd ", b[i]);
    }
    printf("= ");
    if (outline == 1) {
        printf("%hd ", outline);
    }
    for (i = 0; i < 4; i++) {
        printf("%hd ", resultado[i]);
    }
    printf("                   |\n\n");
    getchar();

    // Reset das variáveis de controle global e retorno da função
    one = 0;
    outline = 0;

} // Close key of somaBinaria ()

short int soma_noUI (short int *a, short int *b) {
    short int i;
    short int resultado[4];

    for (i = 3; i >= 0; i--) {
        if (one == 1) {
            resultado[i] = vaiUm(a[i], b[i]);
        } else {
            resultado[i] = logicaBinaria(a[i], b[i]);
        }
        
        if (i == 0 && a[i] == 1 && b[i] == 1) {
            outline = 1;
        }
    }

    // Reset das variáveis de controle global e retorno da função
    one = 0;
    outline = 0;

    return resultado;
}

// Função lógica + interface: conversão, soma e exibição ao usuário do binário ~ decimal
void verificaBinaria (short int *a, short int *b) {
    short int i;
    char firstBin[4], secondBin[4], resultBin[4];
    int firstDec, secondDec, resultDec;

    strcat(firstBin, concatBin(a));
    strcat(secondBin, concatBin(b));
    strcat(resultBin, concatBin(soma_noUI(a, b)));

    firstDec = logicaDecimal(firstBin);
    secondDec = logicaDecimal(secondBin);
    resultDec = firstDec + secondDec;

    printf("Números em base binária de 4 bits inseridos anteriormente: ( %s ) e ( %s )\n", firstBin, secondBin);
    puts("Convertendo...");
    getchar();
    printf("Soma na forma binária: (%s) + (%s) = (%s)\n", firstBin, secondBin, resultBin);
    printf("Soma na forma decimal: %d + %d = %d\n", firstDec, secondDec, resultDec);
}

void main () {
    // Variáveis de Controle
    short int execution;
    short int option;

    // Variáveis para Armazenamento
    short int firstBool[4];
    short int secondBool[4];

    system("clear");
    puts("------------------------------- Somador Binário -------------------------------");
    puts("------------------------------- Versão: 1.0.0b2 -------------------------------");
    puts("---------------- Desenvolvido por: Lucas Darlindo F. Rodrigues ----------------\n");
    puts("--------------------------- Tecle ENTER para continuar ------------------------");
    getchar();
    execution = 1;
    system("clear");

    // Laço de execução contínua do programa
    while (execution == 1) {
        puts("------------------------------- Somador Binário -------------------------------");
        puts("------------------------------- Versão: 1.0.0b2 -------------------------------\n");
        puts("------------------------------------ MENU -------------------------------------");
        puts("1 - Exibir tabela de regras para as somas binárias");
        puts("2 - Realizar uma soma binária (4 bits)");
        puts("3 - Verificar a validade da soma feita (Em breve)");
        puts("0 - Finalizar o programa");
        puts("-------------------------------------------------------------------------------");
        do {
            printf("Digite a operação desejada: ");
            scanf("%hd", &option);
            if (option < 0 || option > 3) {
                puts("Opção inexistente! Tente novamente.");
            }
        } while (option < 0 || option > 3);

        system("clear");
        switch (option) {
            case 0: // Encerrar o programa
                execution = 0;
                break;
            case 1: // Exibição da tabela de regras para a soma binária
                regrasBinaria();
                break;
            case 2: // Execução da soma binária, passo a passo (demonstrativo)
                printf("  Digite o primeiro valor (4 Bits ~ Bit a Bit): ");
                scanf("%hd %hd %hd %hd", &firstBool[0], &firstBool[1], &firstBool[2], &firstBool[3]);
                printf("  Digite o segundo valor (4 Bits ~ Bit a Bit).: ");
                scanf("%hd %hd %hd %hd", &secondBool[0], &secondBool[1], &secondBool[2], &secondBool[3]);
                printf("\n");
                
                soma_UI(firstBool, secondBool);
                break;
            case 3: // Verificação da soma feita (converter para decimal, somar e exibir o resultado)
                verificaBinaria(firstBool, secondBool);
                break;                
        } // Close key of switch ()

        if (execution == 1) {
            puts("------------------------ Deseja retornar para o menu? -------------------------");
            puts("----------------------------- (1) Sim | (0) Não -------------------------------");
            puts("-------------------------------------------------------------------------------");
            do {
                printf("Digite a opção desejada: ");
                scanf("%hd", &execution);

                if (execution < 0 || execution > 1) {
                    puts("Opção inexistente! Tente novamente.");
                }
            } while (execution < 0 || execution > 1);
            
        }
        system("clear");
    } // Close key of while ()
    

} // Close key of main ()