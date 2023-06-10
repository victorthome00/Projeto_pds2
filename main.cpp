#include <iostream>
#include "produto.hpp"
#include "usuario.hpp"
#include "carrinho.hpp"

int main(){ 
    std::vector <Produto> listaProdutos;
    Produto p1;
    Produto p2;
    Produto p3;
    Produto p4;
    p1.produto("Televisao", 2999.99, "Muito Grande", "1213as", 1);
    p2.produto("Galaxy s10", 1899.99, "Moderno", "1582cs",1);
    p3.produto("Geladeira", 3454.00, "Muito gelada", "2630fg",1);
    p4.produto("Aspirador de po", 340.00, "Aspira po", "2456aa",1);
    listaProdutos.push_back(p1);
    listaProdutos.push_back(p2);
    listaProdutos.push_back(p3);
    listaProdutos.push_back(p4);


    return 0;
}