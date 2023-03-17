/*
- Código desenvolvido por: Lucas Darlindo Freitas Rodrigues (lucas.darlindo@gmail.com)
- Instituição............: Universidade Federal do Oeste do Pará, Instituto de Engenharia e Geociências
- Curso..................: Bacharelado em Ciência da Computação (BCC 2018)
- Criado em..............: 01 de Abril de 2019 - 02:30 (Horário Oficial de Brasília, GMT-3)
- Atualizado em..........: 04 de Abril de 2019 - 16:40 (Horário Oficial de Brasília, GMT-3)

- Ferramenta desenvolvida como meio educacional de demonstração para a soma binária (4 bits) na disciplina de Arquitetura
  de computadores, no terceiro semestre do curso, no ano de 2019.
*/

// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis de controle global
short int one = 0;
short int overflow = 0;
short int resultado[4];

// Interface: exibição do valor vetor-binário
void exibirBinario (short int *a) {
    short int i = 0;

    printf("( ");
    for (i = 0; i < 4; i++) {
        printf("%hd ", a[i]);
    }
    printf(")");
}

// Função lógica: conversão de binário para decimal
int logicaDecimal (int a) {
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

// Função auxiliar lógica: concatenação do binário em vetor para uma única instância
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
    short int logica;
    if (a == 0 && b == 0) {
        one = 0;
        logica = 0;
    } else if (a == 1 && b == 0) {
        one = 0;
        logica = 1;
    } else if (a == 0 && b == 1) {
        one = 0;
        logica = 1;
    } else if (a == 1 && b == 1) {
        one = 1;
        logica = 0;
    }

    return logica;
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
            overflow = 1;
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
            if (overflow == 1) {
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
    if (overflow == 1) {
        printf("%hd ", overflow);
    }
    for (i = 0; i < 4; i++) {
        printf("%hd ", resultado[i]);
    }
    printf("                   |\n\n");
    getchar();

    // Reset das variáveis de controle global e retorno da função
    one = 0;
    overflow = 0;

} // Close key of somaBinaria ()

void soma_noUI (short int *a, short int *b) {
    short int i;

    for (i = 3; i >= 0; i--) {
        if (one == 1) {
            resultado[i] = vaiUm(a[i], b[i]);
        } else {
            resultado[i] = logicaBinaria(a[i], b[i]);
        }
        
        if (i == 0 && a[i] == 1 && b[i] == 1) {
            overflow = 1;
        }
    }

    // Reset das variáveis de controle global e retorno da função
    one = 0;
    overflow = 0;
}

// Função lógica + interface: conversão, soma e exibição ao usuário do binário ~ decimal
void verificaBinaria (short int *a, short int *b) {
    short int i;
    int firstBin, secondBin;
    int firstDec, secondDec, resultDec;

    firstBin = concatBin(a);
    secondBin = concatBin(b);
    soma_noUI(a, b);

    firstDec = logicaDecimal(firstBin);
    secondDec = logicaDecimal(secondBin);
    resultDec = firstDec + secondDec;

    puts("|------------------------ Verificação Binário/Decimal -------------------------|");
    puts("");
    printf(" Soma na forma binária: ");
    exibirBinario(a);
    printf(" + ");
    exibirBinario(b);
    printf(" = ");
    exibirBinario(resultado);
    puts("");
    printf(" Soma na forma decimal: %d + %d = %d\n\n", firstDec, secondDec, resultDec);
    puts("|------------------------------------------------------------------------------|");
}

int main () {
    // Variáveis de Controle
    short int execution;
    short int option;

    // Variáveis para Armazenamento
    short int firstBool[4];
    short int secondBool[4];

    system("clear");
    puts("|------------------------------- Somador Binário ------------------------------|");
    puts("|------------------------------ Versão: 1.0.0 RC1 -----------------------------|");
    puts("|------------------------------ Para computadores -----------------------------|");
    puts("|---------------- Desenvolvido por: Lucas Darlindo F. Rodrigues ---------------|\n");
    puts("|--------------------------- Tecle ENTER para continuar -----------------------|");
    getchar();
    execution = 1;
    system("clear");

    // Laço de execução contínua do programa
    while (execution == 1) {
        puts("|------------------------------- Somador Binário ------------------------------|");
        puts("|------------------------------ Versão: 1.0.0 RC1 -----------------------------|");
        puts("|------------------------------ Para computadores -----------------------------|\n");
        puts("|------------------------------------ MENU ------------------------------------|");
        puts("1 - Exibir tabela de regras para as somas binárias");
        puts("2 - Realizar uma soma binária (4 bits)");
        puts("3 - Verificar a validade da soma feita (Binário para Decimal)");
        puts("0 - Finalizar o programa");
        puts("|------------------------------------------------------------------------------|");
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
                printf(" 1) Digite o primeiro valor (4 Bits ~ Bit a Bit): ");
                scanf("%hd %hd %hd %hd", &firstBool[0], &firstBool[1], &firstBool[2], &firstBool[3]);
                printf(" 2) Digite o segundo valor (4 Bits ~ Bit a Bit).: ");
                scanf("%hd %hd %hd %hd", &secondBool[0], &secondBool[1], &secondBool[2], &secondBool[3]);
                printf("\n");
                
                soma_UI(firstBool, secondBool);
                break;
            case 3: // Verificação da soma feita (converter para decimal, somar e exibir o resultado)
                verificaBinaria(firstBool, secondBool);
                break;                
        } // Close key of switch ()

        if (execution == 1) {
            puts("|------------------------ Deseja retornar para o menu? ------------------------|");
            puts("|----------------------------- (1) Sim | (0) Não ------------------------------|");
            puts("|------------------------------------------------------------------------------|");
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
    
    return 0;
} // Close key of main ()