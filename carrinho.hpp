#ifndef CARRINHO_H
#define CARRINHO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include "produto.hpp"

/// @brief É a classe responsável por cuidar dos itens do carrinho.
class Carrinho_de_compra{   //estoque n tem construtor;
public:
  friend class Estoque;
    /// @brief Adiciona um item ao carrinho de compras
    ///
    ///  A partir de um código e uma quantidade passados na função,
    /// é procurado o elemento do estoque com o código referente, e 
    /// a partir disso, é verificado se há essa quantidade disponível 
    /// em estoque. Caso haja, o item é adicionado, caso não haja,
    /// é retornado uma mensagem de erro.
    ///
    /// @param codigo é o codigo do produto referido
    /// @param quantidade é a quantidade que se deseja adicionar
    /// @param aux é o estoque onde se busca esse produto
    void adicionar_item(std::string codigo, int quantidade, Estoque aux);

    /// @brief Remove um item do carrinho de compras
    ///
    ///  A partir de um código passado na função, o item
    /// de código referente é removido, na quantidade também
    /// referida na função. Caso a quantidade seja >= a quantidade
    /// na sacola, o item é apagado da sacola, caso seja menor, 
    /// será removido apenas uma fração.
    ///
    /// @param codigo Código do produto a ser removido do carrinho.
    /// @param quantidade Quantidade do produto que se deseja retirar do carrinho.
    void remover_item(std::string codigo, int quantidade);

    /// @brief Exibe o carrinho
    ///
    ///  Percorre todos os elementos da sacola,
    /// mostrando as informações de cada um deles.
    /// além disse mostra o valor total do carrinho.
    ///
    void exibir_carrinho();
    
    /// @brief Calcula o valor total do carrinho
    ///
    ///  É verificado o valor de cada elemento do carrinho
    /// e multiplicado pela sua quantidade, e somando todos os valores
    /// é retornado o valor total do carrinho.
    ///
    /// @return o valor total do carrinho.
    float calcular_valor();

private:
  std::vector <std::pair<Produto, int>> _sacola;
};

/// @brief A classe Pagamento efetua e valida o pagamento do cliente.
class Pagamento{
    private:
        /// @brief Gera um código aleatório de PIX.
        ///
        ///   A partir de uma função rand(), presente na biblioteca <ctime>,
        /// x assume um valor de 1 a 20. A partir desse numero, com um switch-
        /// -case, é escolhido um dos códigos já escritos.
        ///
        /// @return um codigo PIX de 13 elementos.
        std::string gerar_codigo_PIX();

        /// @brief Recebe o modo de pagamento do cliente.
        ///
        ///  Pega o modo de pagamento do cliente, que escolhe entre: 
        /// crédito, débito e PIX. Tratando o caso de entradas diferentes com um do-while.
        /// Esse do-while funciona repetindo a função ate que seja inserido algum dos métodos de pagamento disponíveis.
        ///
        /// @return O modo de pagamento escolhido (credito, debito ou PIX).
        std::string get_modo_pagamento();

        /// @brief Valida o numero do cartão digitado.
        ///
        ///   O método recebe o número do cartão digitado e verifica se o mesmo:
        ///  Possui alguma letra e/ou possui menos ou mais números que 8.
        ///  Caso alguma das afirmações acima ocorram, o tratamento de erro é acionado,
        ///  retornando 1 para o primeiro caso e 2 para o segundo. Caso a verificação passe nos dois casos é retornado 0.
        ///
        /// @param numeroCartao Número digitado para validação pelo cliente.
        ///
        /// @return Retorna 0 caso o número seja validado; 1 caso o número contenha letras; 2 caso o número nao contenha exatamente 8 dígitos.
        int verificar_cartao(std::string numeroCartao);
    public:
      Pagamento(){} 

        /// @brief Efetua o pagamento do cliente.
        ///
        ///   Essa função recebe o método de pagamento e, a partir dele,
        /// aplica a operação de pagamento pela validação do cartão ou pela
        /// confirmação do código do PIX.
        ///
        void pagar();       
};

/// @brief É a classe responsável pela entrega dos produtos em um cep específico.
class Entrega{
  public:
      /// @brief Coleta o endereço do usuário
      ///  
      ///  É feito uma função que coleta o cep do
      /// usuário, e verifica se o cep tem o tamanho
      /// certo e não contem letras. Caso as duas condições
      /// seja satisfeitas, o função é completa, e atribui um
      /// cep a classe.
      ///
      void coletar_endereco();

      /// @brief É a função de mostrar os status de entrega do produto
      /// 
      ///  É apenas uma função ilustrativa, que
      /// mostra o status de entrega do produto. Como
      /// a função é ilustrativa, o status de entrega é atualizado
      /// a cada 3 segundos.
      ///
      void entregar();

      /// @brief Uma função que bota atribui um cep diretamente
      ///
      ///  É uma função útil para o programa, já que pode-se desejar
      /// utilizar um cep já cadastrado para fazer a entrega. Nesse 
      /// caso, utiliza-se essa função, com parametro de entrada o cep
      /// cadastrado.
      /// 
      /// @param cep É o cep que se deseja fazer a entrega.
      void set_cep(std::string cep);
  private: 
      std::string _cep;
};

/*
class Jogo_espera{
  private:
  void drawBoard(char *spaces);
  void playerMove(char *spaces, char player);
  void computerMove(char *spaces, char computer);
  bool checkWinner(char *spaces, char player);
  bool checkTie(char *spaces);
  public:
  Jogo_espera(){}
  void Jogo_da_velha();
};*/

#endif