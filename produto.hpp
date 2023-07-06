#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>

class Estoque;
/// @brief A classe produto é resoponsável por gerenciar os produtos da loja.
class Produto{      
public:
    friend class Estoque;
        Produto(std::string nome_produto, float valor, std::string descricao, std::string codigo_produto, int quantidade){
        _nome_produto = nome_produto;
        _valor = valor;
        _descricao = descricao;
        _codigo_produto = codigo_produto;
        _quantidade = quantidade;
        }
        Produto() {
        _nome_produto = "";
        _valor = 0.0;
        _descricao = "";
        _codigo_produto = "";
        _quantidade = 0;
        }

        /// @brief Adiciona a quantidade referente a cada objeto de produto.
        ///
        ///  Essa função soma uma quantidade a um produto,
        /// por meio do parametro 'a'.
        ///
        /// @param a É a quantidade que será somada a um produto.
        void adicionar_quantidade(int a);

        /// @brief Remove uma quantidade do produto.
        ///
        ///  É passado uma quantide na função, referente
        /// a quantidade a ser retirada. Caso essa quantidade seja
        /// maior que a disponível, a quantidade se tornará 0, caso
        /// contrário, será quantidade -=a.
        ///
        /// @param a É a quantidade a ser removida.
        void remover_quantidade(int a);

        /// @brief É apenas uma função para atribuir o valor para um produto.
        ///
        /// @param valor_novo É o valor que se tornará o novo valor do produto.
        void alterar_valor(float valor_novo);

        /// @brief Aplica um desconto ao valor do pedido.
        ///
        ///  Essa função altera o valor do produto com base no desconto.
        /// Ele retira 'porcentagem' do valor original.
        ///
        /// @param porcentagem É a porcentagem de desconto a ser aplicada.
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

/// @brief É a classe que cuida das questões relacionadas ao estoque da loja.
class Estoque{   
public:
    friend class Produto;
    friend class Carrinho_de_compra;
        /// @brief Adiciona um produto específico ao estoque.
        ///
        ///  É passado um produto como entada da função, que é 
        /// adicionado ao estoque.
        ///
        /// @param produto é o produto adicionado ao estoque.
        ///
        /// @return Se o produto foi adicionado corretamente. 
        bool incluir_estoque(Produto produto);

        /// @brief Remove um produto do estoque.
        ///
        ///  Essa função percorre o estoque até achar o produto
        /// com o código equivalente ao passado na função, e o remove.
        /// se o produto com esse código não estiver no estoque, ele retorna
        /// uma mensagem de erro e retorna falso.
        ///
        /// @param codigo O código do produto a ser removido.
        ///
        /// @return Se o produto foi removido corretamente.
        bool remover_produto(const std::string& codigo);

        /// @brief Exibe o estoque mapeado por nome.
        /// @return Verdadeiro se tiver algo no estoque.
        bool exibir_estoque_nome();

        /// @brief Exibe o estoque mapeado por valor.
        /// @return Verdadeiro se tiver algo no estoque.
        bool exibir_estoque_valor();
        
        /// @brief Exibe o estoque mapeado por codigo.
        /// @return Verdadeiro se tiver algo no estoque.
        bool exibir_estoque_codigo();

        /// @brief Exibe o estoque mapeado por quantidade.
        /// @return Verdadeiro se tiver algo no estoque.
        bool exibir_estoque_quantidade();

        /// @brief Função para exibir um produto específico do estoque.
        ///
        ///  Essa função procura por um produto no estoque com o nome
        /// referente ao passado na função. Caso ele exita, é mostrado
        /// as informações de produto.
        ///
        /// @param nome É o nome do produto que se deseja vizualizar.
        /// @return Verdadeiro caso haja esse produto no estoque.
        bool exibir_produto_nome(std::string nome);

        /// @brief Função para exibir um produto específico do estoque.
        ///
        ///  Essa função procura por um produto no estoque com o código
        /// referente ao passado na função. Caso ele exita, é mostrado
        /// as informações de produto.  
        /// 
        /// @param codigo É o código do produto que se deseja vizualizar.
        /// @return Verdadeiro caso haja esse produto no estoque.
        bool exibir_produto_codigo(std::string codigo);
protected:
    /// @brief Classe para comparar os produtos do estoque.
    class _comparaProduto{
        public:
        bool operator()(const Produto &p_a,const Produto &p_b){
            return p_a._nome_produto<p_b._nome_produto;
        }
    };
    std::map<std::string, Produto>estoque_nome;
    
    std::multimap<float, Produto>estoque_valor;
    
    std::map<std::string, Produto>estoque_codigo;
    
    std::multimap<int, Produto>estoque_quantidade;

};

#endif
