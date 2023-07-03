#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <iostream>



class Cliente{
public:
    void trocar_senha(std::string nova_senha);
    void trocar_end(std::string novo_end);
    void trocar_nome(std::string novo_nome);

private:
    std::string login() const;
    std::string nome_usuario() const;
    std::string senha() const;
    std::string endereco() const;
};

class Loja{
public:
    void trocar_senha(std::string nova_senha);
    void trocar_end(std::string novo_end);
    void trocar_nome(std::string novo_nome);

private:
    std::string login() const;
    std::string nome_usuario() const;
    std::string senha() const;
    std::string endereco() const;
};

void cliente_main();

void loja_main();

#endif