#include <stdio.h>
#include <stdlib.h>

//Funções
void exibirMenu();
void consultarSaldo(float saldo);
float realizarDeposito(float saldo);
float realizarSaque(float saldo);
void exibirExtrato(float saldo, float historico[], int totalOp);

int main() {
   
    // Definição de valores
    int opcao = 0;
    float saldoAtual = 0.0;
    float historico[3] = {0, 0, 0};
    int contadorOp = 0;

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Switch case do menu com suas funcionalidades
        switch (opcao) {
            case 1:
                consultarSaldo(saldoAtual);
                break;
            
            case 2: {
                float valorDep = realizarDeposito(saldoAtual);
                if (valorDep > 0) {
                    saldoAtual += valorDep;
                    historico[2] = historico[1];
                    historico[1] = historico[0];
                    historico[0] = valorDep; 
                    contadorOp++;
                }
                break;
            }

            case 3: {
                float valorSaq = realizarSaque(saldoAtual);
                if (valorSaq > 0) {
                    saldoAtual -= valorSaq;
                    historico[2] = historico[1];
                    historico[1] = historico[0];
                    historico[0] = -valorSaq;
                    contadorOp++;
                }
                break;
            }

            case 4:
                exibirExtrato(saldoAtual, historico, contadorOp);
                break;
            //Exibição das mensagens de erro ou encerramento do sistema
            case 0:
                printf("\nEncerrando o sistema.\n");
                break;
            // Mensagem de loop
            default:
                printf("\nOpcao invalida, Tente novamente.\n");
        }
        //Mensagem de continuação do programa
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            fflush(stdin); 
            getchar(); getchar(); 
        }

    } while (opcao != 0);

    return 0;
}

// Função menu

void exibirMenu() {
    system("cls || clear");
    printf("===============================\n");
    printf("          ATM FIAP             \n");
    printf("===============================\n");
    printf("1. Consultar Saldo\n");
    printf("2. Realizar Deposito\n");
    printf("3. Realizar Saque\n");
    printf("4. Ver Extrato (Historico)\n");
    printf("0. Sair\n");
    printf("-------------------------------\n");
}
//Função consultar saldo
void consultarSaldo(float saldo) {
    printf("\n>>> Saldo Atual: R$ %.2f\n", saldo);
}
//Função realizar deposito
float realizarDeposito(float saldo) {
    float valor;
    printf("\nDigite o valor do deposito: R$ ");
    scanf("%f", &valor);
    //Mensagem de erro referente ao valor do deposito
    if (valor <= 0) {
        printf("Erro: Valor de deposito deve ser positivo.\n");
        return 0;
    }
    //Mensagem de êxito em deposito
    printf("Deposito de R$ %.2f realizado com sucesso!\n", valor);
    return valor;
}
//Função de saque
float realizarSaque(float saldo) {
    float valor;
    printf("\nDigite o valor do saque: R$ ");
    scanf("%f", &valor);
    // Erro de saque
    if (valor > saldo) {
        printf("Erro: Saldo insuficiente!\n");
        return 0;
    // Valor invalido
    } else if (valor <= 0) {
        printf("Erro: Valor inválido.\n");
        return 0;
    }
    // Êxito em saque
    printf("Saque de R$ %.2f realizado com sucesso!\n", valor);
    return valor;
}
// Função do Extrato
void exibirExtrato(float saldo, float historico[], int totalOp) {
    printf("\n========== EXTRATO ==========\n");
    if (totalOp == 0) {
        printf("Nenhuma movimentação realizada.\n");
    } else {
        int limite = (totalOp < 3) ? totalOp : 3;
        for (int i = 0; i < limite; i++) {
            if (historico[i] > 0)
                printf("%d. DEPOSITO: + R$ %.2f\n", i + 1, historico[i]);
            else
                printf("%d. SAQUE:    - R$ %.2f\n", i + 1, -historico[i]);
        }
    }
    printf("-----------------------------\n");
    printf("SALDO FINAL: R$ %.2f\n", saldo);
    printf("=============================\n");
}