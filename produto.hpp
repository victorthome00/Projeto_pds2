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
    //map pq cada nome deve ser único e ordenado por nome
    std::map<std::string, Produto>estoque_nome;
    //multmap pq podem existir vários produtos com o mesmo preço
    std::multimap<float, Produto>estoque_valor;
    //map pq cada código deve ser único e ordenado por códgio
    std::map<std::string, Produto>estoque_codigo;
    //multimap pq podem existir vários intens com a mesma quantidade de unidades
    std::multimap<int, Produto>estoque_quantidade;

    std::map<std::string, Produto>::iterator it_nome = estoque_nome.begin();
    std::multimap<float, Produto>::iterator it_valor = estoque_valor.begin();
    std::map<std::string, Produto>::iterator it_codigo = estoque_codigo.begin();
    std::multimap<int, Produto>::iterator it_quantidade = estoque_quantidade.begin();
};

#endif