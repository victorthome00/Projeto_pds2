#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "registro.hpp"

Registro r;

TEST_CASE ("Testando criptografia"){
    std::string text;
    text = "Senha18"; 
        CHECK(r.encrypit(text) == "Ugpjc3:");
    
    text = "Arr18";
        CHECK (r.encrypit(text) == "Ctt3:");

}

TEST_CASE ("Testando senha") {
//usando método encripty para verificar senha, já que a senha tem que passar por essa função;
std::string text;

    SUBCASE("Senha com menos de 4 algarismos"){
        text = "A18";
        CHECK_THROWS_AS (r.encrypit(text), std::underflow_error); 
    }

    SUBCASE ("Senha com menos de 2 dígitos"){
        text = "Ar1";
        CHECK_THROWS_AS (r.encrypit(text), std::exception);
    }

    SUBCASE ("Senha sem ao menos 1 letra maiúscula"){
        text = "a18";
        CHECK_THROWS_AS (r.encrypit(text), std::exception);
    }
}

