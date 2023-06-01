#include "classes.hpp"
#include <string>

class Produtos
{
public:
    // adicionar imagem em produto
    Produtos(std::string nome_produto, float valor, int quantidade,
             std::string descricao, std::string codigo_produto);

    void alterar_quantidade(std::string codigo, int x);
    float alterar_valor(float valor_novo, std::string codigo);
    float desconto(float valor, float porcentagem);
};

// adicionar produtos ao usuario e alterar filhas
class Usuario
{
public:
    Usuario(std::string login, std::string senha, std::string endereco,
            std::string codigo_usuario);

    std::string login() const;
    std::string senha() const;
    virtual std::string endereco() const;
    virtual ~Usuario();
};

class Cliente : public Usuario
{
public:
    Cliente(std::string login, std::string senha, std::string endereco,
            std::string codigo_usuario);

private:
};

class Loja : public Usuario
{
public:
    Loja(std::string login, std::string senha, std::string endereco,
         std::string codigo_usuario);
};
