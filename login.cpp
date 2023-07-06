#include "login.hpp"
#include <iostream>
#include <fstream>
#include <vector>

bool Login::autenticarCliente(std::string nome, std::string senha) {
    senha = encrypit(senha);
    std::string linha;
    std::ifstream arquivo("usuariosClientes.txt", std::ios::binary | std::ios::in);
    if (arquivo.is_open()) {
        std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo;
            while (getline(arquivo, linha)) {
                nomeArquivo = linha;
                getline(arquivo, linha);
                senhaArquivo = linha;
                getline(arquivo, linha);
                emailArquivo = linha;
                getline(arquivo, linha);
                cpfArquivo = linha;
                
                senhaArquivo.erase(0, senhaArquivo.find_first_not_of(" \t\r\n"));
            if (nome == nomeArquivo && senha == senhaArquivo) {
                arquivo.close();
                std::cout << "Login do cliente realizado com sucesso!" << std::endl;
                return true;
            }
            }
        arquivo.close();
        std::cout << "Falha na realizacao do login do cliente!" << std::endl;
        std::cout << '\n';
    }
    return false;
}

bool Login::autenticarLoja(std::string nome, std::string senha){
    senha = encrypit(senha);
    std::string linha;

    //int i = 0;
    std::ifstream arquivo("usuariosLoja.txt", std::ios::binary | std::ios::in);
    if (arquivo.is_open()) {
        std::string nomeArquivo, senhaArquivo, emailArquivo, cnpjArquivo, cepArquivo;
            while (getline(arquivo, linha)) {
                nomeArquivo = linha;
                getline(arquivo, linha);
                senhaArquivo = linha;
                getline(arquivo, linha);
                emailArquivo = linha;
                getline(arquivo, linha);
                cnpjArquivo = linha;
                getline(arquivo, linha);
                cepArquivo = linha;
                
                senhaArquivo.erase(0, senhaArquivo.find_first_not_of(" \t\r\n"));
                 
            if (nome == nomeArquivo && senha == senhaArquivo) {
                arquivo.close();
                std::cout << "Login da loja realizado com sucesso!" << std::endl;
                return true;
            }
            }
    arquivo.close();
    std::cout << "Falha na realização do login do cliente!" << std::endl;
    }
    return false;
}

std::string Login::encrypit (std::string& senha) {
    for(int i = 0; (i < 100 && senha[i] != '\0'); i++){
        senha[i] = senha[i] + 2;
    }
    return senha;
}
