#include "login.hpp"
#include <iostream>
#include <fstream>

bool Login::autenticarCliente() {
    std::string nome, senha;
    std::cout << "Digite o nome de usuário: ";
    std::cin >> nome;
    std::cout << "Digite a senha: ";
    std::cin >> senha;
    senha = encrypit(senha);

    std::ifstream arquivo("usuariosCliente.txt", std::ios::binary | std::ios::in);
     if (arquivo.is_open()) {
        std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo, cepArquivo;
        while (arquivo >> nomeArquivo >> senhaArquivo >> emailArquivo >> cpfArquivo >> cepArquivo) {
            if (nome == nomeArquivo && senha == senhaArquivo) {
                arquivo.close();
                std::cout << "Login do cliente realizado com sucesso!" << std::endl;
                return true;
                }
        
            }
        }
        arquivo.close();
    
    std::cout << "Falha na realização do login do cliente!" << std::endl;
    return false;
}

bool Login::autenticarLoja() {
    std::string nome, senha;
    std::cout << "Digite o nome da loja: ";
    std::cin >> nome;
    std::cout << "Digite a senha: ";
    std::cin >> senha;
    senha = encrypit(senha);

    std::ifstream arquivo("usuariosLojas.txt");
    if (arquivo.is_open()) {
        std::string nomeArquivo, senhaArquivo, emailArquivo, cnpjArquivo, cepArquivo;
        while (arquivo >> nomeArquivo >> senhaArquivo >> emailArquivo >> cnpjArquivo >> cepArquivo) {
            if (nome == nomeArquivo && senha == senhaArquivo) {
                arquivo.close();
                std::cout << "Login da loja realizado com sucesso!" << std::endl;
                return true;
            }
        }
        arquivo.close();
    }
    std::cout << "Falha na realização do login do cliente!" << std::endl;
    return false;
}

std::string Login::encrypit (std::string& senha) {
         for(int i = 0; (i < 100 && senha[i] != '\0'); i++)
            senha[i] = senha[i] + 2; //the key for encryption is 3 that is added to ASCII value
    return senha;
    }
