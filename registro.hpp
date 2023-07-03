#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include <string>
#include <exception>

class Exception : public std::exception {
public:
  Exception(const std::string &message);
  
  const char *what() const noexcept override;

private:
  std::string _message;

};

class Registro {
public:
    void cadastrarCliente();
    void cadastrarLoja();
    std::string validar_senha();
    std::string encrypit (std::string& senha);
    std::string validar_usuario();
    std::string validar_loja();
    std::string validar_cpf();
    std::string validar_cnpj();
};


#endif
