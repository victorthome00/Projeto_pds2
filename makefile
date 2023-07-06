
all: main clean
	
main: main.o carrinho.o registro.o usuario.o produto.o login.o
	g++ -Wall -Wextra -o main main.o carrinho.o registro.o usuario.o produto.o login.o
	
*.o:
	g++ -g -c *.cpp -o *.o

clean:
	rm *.o