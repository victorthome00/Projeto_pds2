#include "registro.hpp"
#include <iostream>
#include <fstream>

void Registro::cadastrarCliente() {
    std::string nome, senha, email, cpf, cep;;
    std::cout << "Digite o nome de usuário: ";
    std::cin >> nome;
        senha = validar_senha();
        std::cout << "Digite o email: ";
        std::cin >> email;
        std::cout << "Digite o cpf: ";
        std::cin >> cpf;
        std::cout << "Digite o cep: ";
        std::cin >> cep;

    std::ofstream arquivo("usuariosClientes.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << nome << " " << senha << " " << email << " " << cpf << " " << cep << std::endl;
        arquivo.close();
        std::cout << "Usuário cadastrado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

void Registro::cadastrarLoja() {
    std::string nome, senha, email, cep, cnpj;
    std::cout << "Digite o nome da Loja: ";
    std::cin >> nome;
        senha = validar_senha();
        std::cout << "Digite o email: ";
        std::cin >> email;
        std::cout << "Digite o cnpj: ";
        std::cin >> cnpj;
        std::cout << "Digite o cep: ";
        std::cin >> cep;
    
          std::ofstream arquivo("usuariosLoja.txt", std::ios::app);
          if (arquivo.is_open()) {
             arquivo << nome << " " << senha << " " << email << " " << cnpj << " " << cep << std::endl;
             arquivo.close();
             std::cout << "Usuário cadastrado com sucesso!" << std::endl;
     }    else {
             std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
    }


std::string Registro::validar_senha() {
    std::string senha;
    int contnumber;
    std::cout << "Digite Senha: ";

    while (true) {
     std::cin >> senha;
     contnumber = 0;
        for (char c : senha)    {
            if (std::isdigit (c)) contnumber++;
        }

        if (contnumber >= 2) {
            for (char c : senha){
                 if (isupper(c)) {
                  std::cout << "Senha Validada" << std::endl;
                  return senha;
                  break;
                }
            }
            std::cout << "Senha inválida, digite ao menos uma letra maiúscula" << std::endl;
    }    else {
        std::cout << "Senha inválida, digite ao menos dois dígitos" << std::endl;
    }
    }
}


