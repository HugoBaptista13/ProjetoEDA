# Detecta o sistema operacional
ifdef OS
    EXEC = main.exe
else
    EXEC = main
endif

# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o grafo.o

# Regra principal
all: $(EXEC)

# Criar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

# Regras para compilar os arquivos .c em .o
main.o: main.c estruturasDados.h grafo.h
	$(CC) $(CFLAGS) -c main.c -o main.o

grafo.o: grafo.c grafo.h estruturasDados.h
	$(CC) $(CFLAGS) -c grafo.c -o grafo.o

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJ) $(EXEC)

# Recompilar do zero
rebuild: clean all

.PHONY: all clean rebuild