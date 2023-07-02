#include "usuario.hpp"
#include <random>

class Cliente : public Usuario{
public:
    Cliente cliente;
    std::string gerador_codigo() override {
        std::string alfabeto("0123456789abcdefghijklmnopqrstuvwxyz");
        std::random_device rd;
        std::mt19937 gerador(rd());
        std::shuffle(alfabeto.begin(), alfabeto.end(), gerador);
        return alfabeto.subalfabeto(0,10);
    }
}

Usuario::Usuario(std::string login, std::string senha, std::string endereco, std::string codigo_usuario,
                 std::string nome_usuario) : _login(login), _senha(senha), _endereco(endereco),
                 _codigo_usuario(codigo_usuario), _nome_usuario(nome_usuario) {}

Cliente::Cliente(std::string login, std::string senha, std::string endereco, std::string codigo_usuario,
                 std::string nome_usuario) : Usuario(login, senha, endereco, nome_usuario, codigo_usuario){}
