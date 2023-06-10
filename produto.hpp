#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>

//essa declaração está aqui pra tornar ela amiga da classse produto
class estoque;
class Produto{
public:
//permite que a classe estoque tenha acesso à classe produto
    friend class Estoque;
//adicionar imagem em produto 
    void produto(std::string nome_produto, float valor, std::string descricao, std::string codigo_produto, int quantidade);
    void alterar_valor(float valor_novo);
    void desconto(float porcentagem);
    std::string get_codigo();
    std::string get_nome();
    float get_valor();
    std::string get_descricao();
    int get_quantidade();
private:
    std::string _nome_produto;
    float _valor;
    std::string _descricao;
    std::string _codigo_produto;
    int _quantidade;
};
class Estoque{
public:
    friend class Produto;
    bool incluir_estoque(Produto produto);
private:
    std::set<std::string, Produto>estoque_nome;
    std::map<float, Produto>estoque_valor;
    std::map<std::string, Produto>estoque_codigo;
    std::map<int, std::string>estoque_quantidade;
};

#endif