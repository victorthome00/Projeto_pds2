#include "usuario.hpp"

Usuario::Usuario(std::string login, std::string senha, std::string endereco, std::string codigo_usuario,
                 std::string nome_usuario) : _login(login), _senha(senha), _endereco(endereco),
                 _codigo_usuario(codigo_usuario), _nome_usuario(nome_usuario) {}


Cliente::Cliente(std::string login, std::string senha, std::string endereco, std::string codigo_usuario,
                     std::string nome_usuario) : Usuario(login, senha, endereco, nome_usuario, codigo_usuario){}