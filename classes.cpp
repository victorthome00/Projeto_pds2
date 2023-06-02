#include "classes.hpp"
#include <string>
#include <vector>
#include <iostream>
std::vector <Produto> listaProdutos;
void Produto::alterar_quantidade(std::string codigo, int &x, std::vector<Produto> &vetor){
     for (int i = 0; i < vetor.size(); i++) {
        if (vetor[i]._codigo_produto == codigo) {
            vetor[i]._quantidade = x;
            return;
        }
    }
}
float Produto::alterar_valor(std::string codigo, float &valor_novo, std::vector<Produto> &vetor){
    for (int i = 0; i < listaProdutos.size(); i++) {
        if (vetor[i]._codigo_produto == codigo) {
            vetor[i]._valor = valor_novo;
            return;
        }
    }
}
float Produto::desconto(std::string codigo, float porcentagem, std::vector<Produto> &vetor){
    for (int i = 0; i < listaProdutos.size(); i++) {
        if (vetor[i]._codigo_produto == codigo) {
            vetor[i]._valor = vetor[i]._valor - porcentagem*vetor[i]._valor;
            return;
        }
    }
}
