# Definições de variáveis
CC = gcc                           # Compilador
CFLAGS = -Iinclude                 # Diretório dos arquivos de cabeçalho
SRC = src/main.c src/utils.c       # Arquivos fonte
OBJ = build/main.o build/utils.o    # Arquivos objeto
EXEC = meu_programa                # Nome do executável

# Regra padrão
all: $(EXEC)

# Regra para criar o executável
$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

# Regra para compilar main.c
build/main.o: src/main.c include/utils.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

# Regra para compilar utils.c
build/utils.o: src/utils.c include/utils.h
	$(CC) $(CFLAGS) -c src/utils.c -o build/utils.o

# Limpa os arquivos compilados
clean:
	rm -rf build/*.o $(EXEC)
