#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <vector>
#include <utility>


class Produto{
public:
//adicionar imagem em produto 
    Produto(std::string nome_produto, float valor, 
             std::string descricao, std::string codigo_produto){
                this->_nome_produto = nome_produto;
                this->_valor = valor;
                this->_descricao = descricao;
                this->_codigo_produto = codigo_produto;
             }
    void alterar_valor(float valor_novo);
    void desconto(float porcentagem);
    std::string get_codigo();
    std::string get_nome();
    float get_valor();
    std::string get_descricao();
private:
    std::string _nome_produto;
    float _valor;
    std::string _descricao;
    std::string _codigo_produto;
};
class Estoque{
public:



private:
};


// adicionar produtos ao usuario e alterar filhas
class Usuario{
public:
    Usuario(std::string login, std::string senha, std::string endereco,
            std::string codigo_usuario);

    std::string login() const;
    std::string senha() const;
    virtual std::string endereco() const;
    virtual ~Usuario();
};


class Cliente : public Usuario{
public:
    Cliente(std::string login, std::string senha, std::string endereco, 
            std::string codigo_usuario);

private:
};


class Loja : public Usuario{
public:
    Loja(std::string login, std::string senha, std::string endereco,
         std::string codigo_usuario);
};

class Carrinho_de_compra{
public:
void adicionar_item(std::string codigo, int quantidade, std::vector <Produto> &vetor);
void remover_item(std::string codigo, int quantidade, std::vector <Produto> &vetor);
void exibir_carrinho();
private:
std::vector <std::pair<Produto, int>> _sacola;
};

class Pagamento{
    public: 
      Pagamento(std::string modo_pagamento, std::string endereco, std::string numero_pedido, Carrinho Produtos);
};

#endif