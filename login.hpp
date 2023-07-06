#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>

class Login {
public:
    /// @brief Esse método autentica o login do cliente.
    ///
    ///  A função recebe um nome ja cadastrado e assim recebe uma senha vinculada ao nome.
    /// Ela verifica com o banco de usuários.txt se o nome dado equivale com a senha inserida.
    /// Caso esse cenário se confirme retorna true, validando o acesso; caso contrário false,
    /// printando 'erro na autenticação' e recomeça o processo.
    ///
    /// @param nome É o nome inserido pelo usuário.
    /// @param senha É a senha vinculada ao nome inserido.
    /// @return Retorna True caso a validação ocorra. False caso o nome ou a senha estejam em desacordo com o txt.
    bool autenticarCliente(std::string nome, std::string senha);

    /// @brief Esse método autentica o login da loja.
    ///
    ///  Assim como a função de autenticação do login, essa função recebe um nome que já deve estar cadrastrado
    /// e uma senha vinculada ao mesmo. Ela verifica com o banco de usuários.txt se o nome dado equivale com a senha inserida.
    /// Caso esse cenário se confirme retorna true, validando o acesso; caso contrário false,
    /// printando 'erro na autenticação' e recomeça o processo.
    ///
    /// @param nome É o nome inserido pelo gerente.
    /// @param senha É a senha vinculada ao nome inserido.
    /// @return Retorna True caso a validação ocorra. False caso o nome ou a senha estejam em desacordo com o txt.
    bool autenticarLoja(std::string nome, std::string senha);

    /// @brief Faz a encriptação da senha colocada.
    ///
    ///  Com a finalidade de comparar a senha inserida com a senha que foi armazenada no arquivo de txt
    /// (senha já criptografada), criptografamos usando a criptografia de César que consiste na substituição 
    /// de um caractere pelo equivalente a três casas a frente na numeração de caractere (ASCII).
    /// Assim chegamos em uma nova string, a senha encriptografada, retornada pela função.
    ///
    /// @param senha Recebe a senha inserida anteriormente.
    /// @return Retorna a senha encriptografada.
    std::string encrypit (std::string& senha);
};
#endif
