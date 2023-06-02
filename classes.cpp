#include "classes.hpp"
#include <string>
#include <vector>
std::vector <Produto> listaProdutos;
void Produto::alterar_quantidade(std::string codigo, int x){
     for (int i = 0; i < listaProdutos.size(); i++) {
        if (listaProdutos[i].codigo_produto == codigo) {
            listaProdutos[i].quantidade = x;
            return;
        }
    }
}
float Produto::alterar_valor(std::string codigo, float valor_novo){
    for (int i = 0; i < listaProdutos.size(); i++) {
        if (listaProdutos[i].codigo_produto == codigo) {
            listaProdutos[i].valor = valor_novo;
            return;
        }
    }
}
float Produto::desconto(std::string codigo, float porcentagem){
    for (int i = 0; i < listaProdutos.size(); i++) {
        if (listaProdutos[i].codigo_produto == codigo) {
            listaProdutos[i].valor = valor - porcentagem*valor;
            return;
        }
    }
}
