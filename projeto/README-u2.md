# Projeto 2 - Sistema de Análise de Textos

## Descrição
Este é um programa de linha de comando (CLI) desenvolvido em linguagem C que funciona como um **Sistema de Análise de Textos**.

O programa realiza as seguintes tarefas:
* Lê um texto completo fornecido pelo usuário (utilizando alocação dinâmica para gerenciar a entrada).
* Processa o texto para identificar palavras únicas e suas frequências.
* Utiliza uma estrutura de dados dinâmica (Array de Structs alocado com `realloc`) para armazenar o dicionário de palavras e suas contagens.
* Aplica **Strings**, **Ponteiros** e **Alocação Dinâmica** (requisitos da U2).

## Compilação
O projeto consiste em um único arquivo-fonte (`analisador.c`) e utiliza apenas bibliotecas padrão do C (`stdio.h`, `stdlib.h`, `string.h`, `ctype.h`).

Para compilar o programa, navegue até o diretório raiz do projeto e utilize o compilador GCC, incluindo as flags para garantir o padrão C99 e exibir todos os warnings (`-Wall -Wextra`):

```bash
gcc -o projeto/analisador projeto/src/analisador.c -Wall -Wextra -std=c99
```