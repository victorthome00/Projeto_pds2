#ifndef CARRINHO_H
#define CARRINHO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include "produto.hpp"

class Carrinho_de_compra{   //estoque n tem construtor;
public:
  friend class Estoque;
    void adicionar_item(std::string codigo, int quantidade, Estoque aux);
    void remover_item(std::string codigo, int quantidade);
    void exibir_carrinho();
    float calcular_valor();

private:
  std::vector <std::pair<Produto, int>> _sacola;
};

class Pagamento{
    private:
      std::string _modo_pagamento;
      std::string _numeroCartao;
      
    public:
      Pagamento(std::string modo_pagamento, std::string numeroCartao){ 
        this-> _modo_pagamento = modo_pagamento;
        this-> _numeroCartao = numeroCartao;
      } 
        void pagar();
        std::string gerar_codigo_PIX();
        std::string get_modo_pagamento();
        int verificar_cartao(std::string numeroCartao);
};

class Entrega{
  public:
      void coletar_endereco();
      void entregar();
      void set_cep(std::string cep);
  private: 
      std::string _cep;

};
#endif