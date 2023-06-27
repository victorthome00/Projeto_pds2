#ifndef CARRINHO_H
#define CARRINHO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include "produto.hpp"

class Carrinho_de_compra{
public:
void adicionar_item(std::string codigo, int quantidade, Estoque aux);
void remover_item(std::string codigo, int quantidade);
void exibir_carrinho();
private:
std::vector <std::pair<Produto, int>> _sacola;
};

class Pagamento{
    private:
      Carrinho_de_compra _cliente;
      std::string _modo_pagamento;
    public:
      Pagamento(Carrinho_de_compra cliente, std::string modo_pagamento){
        this-> _cliente = cliente; 
        this-> _modo_pagamento = modo_pagamento;
      } 
        void pagar();
        std::string gerar_codigo_PIX();
        bool eValido(int cardNumber[16]);
        void get_modo_pagamento();

};

#endif