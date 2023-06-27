#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include <utility>
#include <map>

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