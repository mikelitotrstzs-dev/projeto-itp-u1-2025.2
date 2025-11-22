# Projeto 1 - Conversor de Unidades com Histórico

## Descrição
Este é um programa de linha de comando (CLI) desenvolvido em linguagem C que funciona como um conversor de unidades. O usuário pode escolher entre diferentes tipos de conversão (distância e temperatura) através de um menu interativo. O programa também salva cada resultado em um histórico que pode ser visualizado durante a execução.

## Compilação
O projeto consiste em um único arquivo-fonte (`main.c`) e não requer bibliotecas externas. Para compilar, utilize o GCC:
```bash
gcc -o projeto src/main.c
```
Se você estiver no diretório `projeto/`, o comando acima irá gerar um executável chamado `projeto`.

## Execução
Após a compilação, execute o programa com o seguinte comando:
```bash
./projeto
```

## Funcionalidades
Ao executar, o programa exibe um menu com as seguintes opções:
1.  **Metros para Centímetros**: Solicita um valor em metros e exibe o resultado da conversão.
2.  **Centímetros para Metros**: Solicita um valor em centímetros e exibe o resultado da conversão.
3.  **Celsius para Fahrenheit**: Solicita uma temperatura em Celsius e exibe o resultado da conversão.
4.  **Fahrenheit para Celsius**: Solicita uma temperatura em Fahrenheit e exibe o resultado da conversão.
5.  **Ver histórico**: Exibe uma lista com os resultados de todas as conversões realizadas na sessão atual.
6.  **Sair**: Encerra a execução do programa.