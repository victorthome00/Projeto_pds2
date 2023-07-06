#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include <string>
#include <exception>

class Exception : public std::exception {
public:
  const char *what() const noexcept override;

private:
  std::string _message;

};

class Registro {
public:
    /// @brief Faz o cadastro do cliente no site.
    ///
    ///  Esse método armazena os dados coletados e validados pelas outras 
    /// funções da classe no arquivo txt. Realizando o cadastro do cliente.
    ///
    void cadastrarCliente();

    /// @brief Faz o cadastro da loja no site.
    ///
    ///  Como no método de cadastrarCliente, esse armazena os dados coletados e 
    /// validados pelas outras funções da classe no arquivo txt. Realizando o cadastro da loja.
    ///
    void cadastrarLoja();

    /// @brief Valida o registro da senha.
    ///
    ///  Esse método valida o registro da senha a partir da confirmação
    /// do cumprimento dos pré-requisitos: ter pelo menos uma letra maiúscula,
    /// ter ao menos dois digitos e no minimo quatro algarismos. Ao cumpri-los,
    /// a validação é completa, caso contrário será imprimido o motivo pelo qual
    /// não foi completa a validação.
    ///
    /// @return Retorna a senha validada.
    std::string validar_senha();

    /// @brief Faz uma encriptação da senha validada.
    ///
    ///  Criptografamos usando a criptografia de César que consiste na substituicao de
    /// um caractere pelo equivalente a três casas a frente na numeração de caractere (ASCII).
    /// Assim chegamos em uma nova string, a senha encriptografada, retornada pela função.
    ///
    /// @param senha Recebe a senha validada.
    /// @return Retorna a senha encriptografada.
    std::string encrypit (std::string& senha);

    /// @brief Valida o nome do cliente.
    ///
    ///  Confere se o nome do usuário sendo cadastrado já existe no arquivo.
    /// Caso exista é printado uma mensagem de erro e o arquivo é fechado,
    /// repetindo a função para receber um nome diferente.
    ///
    /// @return Retorna o nome do cliente validado.
    std::string validar_usuario();

    /// @brief Valida o nome da loja.
    ///
    ///  Confere se o nome da loja sendo cadastrada já existe no arquivo.
    /// Caso exista é printado uma mensagem de erro e o arquivo é fechado,
    /// repetindo a função para receber um nome diferente.
    ///
    /// @return Retorna o nome da loja validado.
    std::string validar_loja();

    /// @brief Valida o cpf inserido.
    ///
    ///  Confere se o CPF sendo cadastrado possui todos os
    /// onze digitos. Caso não os tenha, é imprimido uma mensagem 
    /// de erro e repete a função para a inserção de um novo CPF para validação.
    ///
    /// @return Retorna o CPF validado.
    std::string validar_cpf();

    /// @brief Valida o CNPJ inserido.
    ///
    ///  Confere se o CNPJ sendo cadastrado possui todos os
    /// quatorze digitos. Caso não os tenha, é imprimido uma mensagem 
    /// de erro e repete a função para a inserção de um novo CNPJ para validação.
    ///
    /// @return Retorna o CNPJ validado.
    std::string validar_cnpj();

    /// @brief Valida o CEP inserido.
    ///
    ///  Confere se o CEP sendo cadastrado possui todos os
    /// oito digitos. Caso não os tenha, é imprimido uma mensagem 
    /// de erro e repete a função para a inserção de um novo CEP para validação.
    ///
    /// @return Retorna o CEP validado.
    std::string validar_cep();
};


#endif
