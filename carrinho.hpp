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
        /// @brief Efetua o pagamento do cliente.
        ///
        /// Essa funcao recebe o metodo de pagamento e, a partir dele,
        /// aplica a operacao de validacao do cartao ou de PIX.
        ///
        void pagar();

        /// @brief Gera um codigo aleatorio de PIX.
        ///
        ///   A partir de uma funcao rand(), presente na biblioteca <ctime>,
        /// x assume um valor de 1 a 20. A partir desse numero, com um switch-
        /// -case, é escolhida uma dos codigos ja escritos.
        ///
        /// @return um codigo PIX de 13 elementos.
        std::string gerar_codigo_PIX();

        /// @brief Recebe o modo de pagamento do cliente.
        ///
        /// Pega o modo de pagamento do cliente, que escolhe entre: 
        /// credito, debito e PIX. Tratando o caso de entradas diferentes com um do-while.
        /// Esse do-while funciona repetindo a funcao ate que seja inserido algum dos metodos de pagamento disponiveis.
        ///
        /// @return O modo de pagamento escolhido (credito, debito ou PIX).
        std::string get_modo_pagamento();

        /// @brief Valida o numero do cartao digitado.
        ///
        ///   O metodo recebe o numero do cartao digitado e verifica se o mesmo:
        ///  Possui alguma letra e/ou possui menos ou mais numeros que o padrao de 16.
        ///  Caso alguma das afirmacoes acima ocorram, o tratamento de erro é acionado,
        ///  retornando 1 para o primeiro caso e 2 para o segundo. Caso a verificação passe nos dois casos é reornado 0.
        ///
        /// @param numeroCartao Numero digitado para validacao pelo cliente.
        ///
        /// @return 0 caso o numero seja validado; 1 caso o numero contenha letras; 2 caso o numero nao contenha exatamente 16 digitos.
        int verificar_cartao(std::string numeroCartao);
};

class Entrega
  public:
      void coletar_endereco();
      void entregar();
      void set_cep(std::string cep);
  private: 
      std::string _cep;

};
#endif