Copiar

CC     = gcc
CFLAGS = -Wall -Wextra -g
TARGET = sistema
 
SRCS = main.c inserir.c buscar.c atualizar.c listar.c validador.c
OBJS = $(SRCS:.c=.o)
 
all: $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
 
%.o: %.c arvore.h validador.h
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJS) $(TARGET)
 
.PHONY: all clean