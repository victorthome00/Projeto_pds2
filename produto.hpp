#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>

//essa declaração está aqui pra tornar ela amiga da classse produto
class Estoque;
class Produto{
public:
//permite que a classe estoque tenha acesso à classe produto
    friend class Estoque;
//adicionar imagem em produto 
    Produto(std::string nome_produto, float valor, std::string descricao, std::string codigo_produto, int quantidade);
    Produto();
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
    friend class Carrinho_de_compra;
    bool incluir_estoque(Produto produto);
    bool remover_produto(const std::string& codigo);
    bool exibir_estoque_nome();
    bool exibir_estoque_valor();
    bool exibir_estoque_codigo();
    bool exibir_estoque_qunatidade();
    bool exibir_produto_nome(std::string nome);
    bool exibir_produto_codigo(std::string codigo);
protected:
    class _comparaProduto{
        public:
        bool operator()(const Produto &p_a,const Produto &p_b){
            return p_a._nome_produto<p_b._nome_produto;
        }
    };
    //map pq cada nome deve ser único e ordenado por nome
    std::map<std::string, Produto>estoque_nome;
    //multmap pq podem existir vários produtos com o mesmo preço
    std::multimap<float, Produto>estoque_valor;
    //map pq cada código deve ser único e ordenado por códgio
    std::map<std::string, Produto>estoque_codigo;
    //multimap pq podem existir vários intens com a mesma quantidade de unidades
    std::multimap<int, Produto>estoque_quantidade;

};

#endif
