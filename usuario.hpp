#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <iostream>

class Estoque;
class Carrinho; 
class Usuario{
public:
    Usuario(const std::string login, const std::string senha, const std::string endereco,
            const std::string codigo_usuario, const std::string nome_usuario);
    virtual void trocar_senha();
    virtual void trocar_end();
    virtual void gerador_codigo();
    virtual ~Usuario();

protected:
    std::string login() const;
    std::string senha() const;
    std::string endereco() const;
    std::string nome_usuario() const;
};


class Cliente : public Usuario{
public:
    friend class Carrinho;
    Cliente(std::string login, std::string senha, std::string endereco, std::string codigo_usuario,
            std::string nome_usuario);
    void trocar_senha();
    void trocar_end();
    void gerador_codigo();

private:
    std::string login() const;
    std::string nome_usuario() const;
    std::string senha() const;
    std::string endereco() const;
};


class Loja : public Usuario{
public:
    friend class Estoque;
    Loja(std::string login, std::string senha, std::string endereco, std::string codigo_usuario, 
         std::string nome_usuario);
    void trocar_senha();
    void trocar_end();
    void gerador_cogido();

private:
    std::string login() const;
    std::string nome_usuario() const;
    std::string senha() const;
    std::string endereco() const;
};

#endif