CC = g++

CFLAGS = -Wall -Wextra

all: main clean

main: main.o carrinho.o registro.o usuario.o produto.o login.o
    $(CC) $(CFLAGS) -o main main.o carrinho.o registro.o usuario.o produto.o login.o

.o:
    $(CC) -g -c.cpp -o .o

clean:
    rm.o

run: all 
    ./main