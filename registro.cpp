#include "registro.hpp"
#include <iostream>
#include <fstream>



void Registro::cadastrarCliente() {
    std::string nome, senha, email, cpf;
        nome = validar_usuario();
        senha = validar_senha();
        senha = encrypit(senha);
        std::cout << "Digite o email: ";
        std::cin >> email;
        cpf = validar_cpf();

    std::ofstream arquivo("usuariosClientes.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << nome << " " << senha << " " << email << " " << cpf << std::endl;
        arquivo.close();
        std::cout << "Usuário cadastrado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}


void Registro::cadastrarLoja() {
    std::string nome, senha, email, cnpj;
    nome = validar_loja();
    senha = validar_senha();
    senha = encrypit(senha);
    std::cout << "Digite o email: ";
    std::cin >> email;
    cnpj = validar_cnpj();

    std::ofstream arquivo("usuariosLoja.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << nome << " " << senha << " " << email << " " << cnpj << std::endl;
        arquivo.close();
        std::cout << "Usuário cadastrado com sucesso!" << std::endl;
    }    
    else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}


std::string Registro::validar_senha() {
    std::string senha;
    int contnumber;
    std::cout << "Digite uma senha válida: ";

    while (true) {
     std::cin >> senha;
     contnumber = 0;
        for (char c : senha)    {
            if (std::isdigit (c)) contnumber++;
        }

        if (contnumber >= 2) {
            for (char c : senha){
                 if (isupper(c)) {
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


std::string Registro::encrypit (std::string& senha) {
    for(int i = 0; (i < 100 && senha[i] != '\0'); i++){
        senha[i] = senha[i] + 2;
    }
    return senha;
}


std::string Registro::validar_cpf(){
  int i, j;
  std::string cpf;

  while (true) {
    i = 0;
    j = 0;
    std::cout << "Digite um CPF válido: ";
    std::cin >> cpf;

    for(char c : cpf){
        i++;

        if(std::isdigit(c)){
         j++;
        }
    }

    if (i == 11 && j == i) {
        
        return cpf;
        break;
    }
    std::cout << "CPF inválido, necessário ter 11 dígitos" << std::endl;
}

}


std::string Registro::validar_cnpj(){
  int i, j;
  std::string cnpj;

  while (true) {
    i = 0;
    j = 0;
    std::cout << "Digite um CNPJ válido: ";
    std::cin >> cnpj;

    for(char c : cnpj){
        i++;

        if(std::isdigit(c)){
         j++;
        }
    }

    if (i == 14 && j == i) {
        
        return cnpj;
        break;
    }
    std::cout << "CPF inválido, necessário ter 14 dígitos" << std::endl;
}
}

std::string Registro::validar_usuario() {
    std::string nome;
    int cont;

    while (true){
        std::ifstream arquivo("usuariosClientes.txt", std::ios::in);
        cont = 0;
        std::cout << "Digite um usuário: ";
        std::cin >> nome;
        if (arquivo.is_open()) {
        std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo;
        while (arquivo >> nomeArquivo >> senhaArquivo >> emailArquivo >> cpfArquivo) {
            if (nome == nomeArquivo) {
                ++cont;
            }
        }
        }
        if (cont == 0) {
            arquivo.close();
            return nome;
            break;
        }
        std::cout << "Usuário já existe" << std::endl;
        arquivo.close();
        }

    }

std::string Registro::validar_loja() {
    std::string nome;
    int cont;

    while (true){
        std::ifstream arquivo("usuariosLoja.txt", std::ios::in);
        cont = 0;
        std::cout << "Digite um usuário: ";
        std::cin >> nome;
        if (arquivo.is_open()) {
        std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo;
        while (arquivo >> nomeArquivo >> senhaArquivo >> emailArquivo >> cpfArquivo) {
            if (nome == nomeArquivo) {
                ++cont;
            }
        }
        }
        if (cont == 0) {
            arquivo.close();
            return nome;
            break;
        }
        std::cout << "Usuário já existe" << std::endl;
        arquivo.close();
    }
}
