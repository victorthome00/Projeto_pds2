#ifndef CLASSES_H
#define CLASSES_H
#include <string>



class Produto{
public:
//adicionar imagem em produto 
    Produto(std::string nome_produto, float valor, int quantidade, 
             std::string descricao, std::string codigo_produto){
                this->_nome_produto = nome_produto;
                this->_valor = valor;
                this->_quantidade = quantidade;
                this->_descricao = descricao;
                this->_codigo_produto = codigo_produto;
             }
    
    void alterar_quantidade(std::string codigo, int &x, std::vector<Produto> &vetor);
    float alterar_valor(std::string codigo, float &valor_novo, std::vector<Produto> &vetor);
    float desconto(std::string codigo, float porcentagem, std::vector<Produto> &vetor);
private:
    std::string _nome_produto;
    float _valor;
    int _quantidade;
    std::string _descricao;
    std::string _codigo_produto;
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