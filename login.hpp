#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>

class Login {
public:
    bool autenticarCliente(std::string nome, std::string senha);
    bool autenticarLoja(std::string nome, std::string senha);
    std::string encrypit (std::string& senha);
};
#endif
