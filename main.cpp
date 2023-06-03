#include <iostream>
#include "classes.cpp"

int main(){ 
std::vector <Produto> listaProdutos;
Produto p1("Televisao", 2999.99, "Muito Grande", "1213as");
Produto p2("Galaxy s10", 1899.99, "Moderno", "1582cs");
Produto p3("Geladeira", 3454.00, "Muito gelada", "2630fg");
Produto p4("Aspirador de po", 340.00, "Aspira po", "2456aa");
listaProdutos.push_back(p1);
listaProdutos.push_back(p2);
listaProdutos.push_back(p3);
listaProdutos.push_back(p4);

    return 0;   
}