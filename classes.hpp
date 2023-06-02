#ifndef CLASSES_H
#define CLASSES_H
#include <string>



class Produto{
public:
//adicionar imagem em produto 
    Produto(std::string nome_produto, float valor, int quantidade, 
             std::string descricao, std::string codigo_produto){
                this->nome_produto = nome_produto;
                this->valor = valor;
                this->quantidade = quantidade;
                this->descricao = descricao;
                this->codigo_produto;
             }
    
    void alterar_quantidade(std::string codigo, int &x);
    float alterar_valor(std::string codigo, float &valor_novo);
    float desconto(std::string codigo, float porcentagem);
private:
    std::string nome_produto;
    float valor;
    int quantidade;
    std::string descricao;
    std::string codigo_produto;
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


#endif