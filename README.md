# CP3_DSA

## ATM CP3
Eduardo Barcelos De Carvalho Braziliano RM 573274  
Julia Johanson Peniche Dias da Silva RM 572220  
Lucas Bomfim Leite RM 570420

## Descrição do sistema
Sistema ATM FIAP - Projeto Integrador
Este projeto consiste em um sistema de Caixa Eletrônico (ATM) funcional, desenvolvido em linguagem C, operado via terminal. O objetivo é simular as operações bancárias básicas de forma estruturada, aplicando conceitos de modularização, estruturas de repetição e lógica de controle de estado.
O sistema utiliza uma arquitetura baseada em um loop principal (do-while) que mantém a interface ativa, processando as escolhas do usuário através de uma estrutura switch-case. Cada funcionalidade bancária é isolada em funções específicas, garantindo um código limpo, de fácil manutenção e seguindo as melhores práticas de programação (Clean Code).

## Funcionalidades Implementadas

O ATM dispõe das seguintes operações:

Consulta de Saldo: Exibe o valor disponível em conta com formatação monetária.

Depósito: Permite a entrada de valores positivos, atualizando o saldo imediatamente. Possui validação para impedir entradas de valores negativos ou nulos.

Saque: Realiza a retirada de valores após verificar se há saldo suficiente. Caso o valor solicitado seja maior que o saldo, o sistema emite um alerta de "Saldo Insuficiente".

Extrato (Histórico): Funcionalidade de desafio que armazena e exibe as últimas 3 operações realizadas (seja saque ou depósito), mostrando o fluxo recente e o saldo final consolidado.

Interface Otimizada: Limpeza automática do console a cada operação e tratamento de erros para opções inválidas no menu.

## Instruições de compilação e execução

Realizar o comando "gcc main.c -o programa" em seguida executar o exe com "programa" no terminal e por fim seguir as instruições em display no menu conforme necessidade.
