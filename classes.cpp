#include "classes.hpp"
#include <string>
#include <iostream>
#include <vector>
void Produto::alterar_valor(float valor_novo){
   _valor = valor_novo;
}
void Produto::desconto(float porcentagem){
   _valor = _valor - _valor*porcentagem;
}
std::string Produto::get_codigo(){
    return _codigo_produto;
}
std::string Produto::get_nome(){
    return _nome_produto;
}
float Produto::get_valor(){
    return _valor;
}
std::string Produto::get_descricao(){
    return _descricao;
}
/*void Carrinho_de_compra::adicionar_item(std::string codigo, int quantidade, std::vector <Produto> &vetor){
    for (Produto aux : vetor) {
        if (aux.get_codigo() == codigo) {
            std::pair <Produto, int> aux1(aux, quantidade);
            _sacola.push_back(aux1);
            return;
        }
    }
}
void Carrinho_de_compra::remover_item(std::string codigo, int quantidade, std::vector <Produto> &vetor){
    for (Produto aux : vetor) {
        if (aux.get_codigo() == codigo) {
            std::pair <Produto, int> aux1(aux, quantidade);
            _sacola.push_back(aux1);
            return;
        }
    }
} */