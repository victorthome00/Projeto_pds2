#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>

class Login {
public:
    bool autenticarCliente();
    bool autenticarLoja();
    std::string encrypit (std::string& senha);
};
#endif
