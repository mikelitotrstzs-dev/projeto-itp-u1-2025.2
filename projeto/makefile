# =========================================================
# Makefile para o Projeto 2 (Sistema de Análise de Textos)
# =========================================================

# Variáveis
# CC: Compilador (gcc é o padrão)
CC = gcc
# CFLAGS: Flags de compilação (necessário para U2: C99, warnings, etc.)
CFLAGS = -Wall -Wextra -std=c99 -o 
# TARGET: O nome do executável e seu local de saída.
TARGET = projeto/analisador
# SOURCE: O caminho para o arquivo de código-fonte.
SOURCE = projeto/src/analisador.c

# Alvo Padrão: 'make all' ou apenas 'make'
# O alvo 'all' depende do executável final ser construído.
all: $(TARGET)

# Regra principal para construir o executável
# Dependência: O executável TARGET depende do arquivo fonte SOURCE
$(TARGET): $(SOURCE)
	# Ação: Compila o arquivo-fonte, aplicando as flags e gerando o executável no local especificado.
	$(CC) $(CFLAGS) $(TARGET) $(SOURCE)

# Alvo para Limpeza: 'make clean'
# Ação: Remove o arquivo executável gerado. (Requisito: Estrutura do Repositório - U2)
clean:
	rm -f $(TARGET)

# Especifica que 'all' e 'clean' não são nomes de arquivos, mas ações (targets virtuais).
.PHONY: all clean