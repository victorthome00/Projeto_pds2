#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include <string>

class Registro {
public:
    void cadastrarCliente();
    void cadastrarLoja();
    std::string validar_senha();
    std::string encrypit (std::string& senha);
    std::string validar_cep();
    std::string validar_cpf();
    std::string validar_cnpj();
};


#endif
