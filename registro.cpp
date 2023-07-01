#include "registro.hpp"
#include <iostream>
#include <fstream>

void Registro::cadastrarCliente() {
    std::string nome, senha, email, cpf, cep;;
    std::cout << "Digite o nome de usuário: ";
    std::cin >> nome;
        senha = validar_senha();
        senha = encrypit(senha);
        std::cout << "Digite o email: ";
        std::cin >> email;
        cpf = validar_cpf();
        cep = validar_cep();

    std::ofstream arquivo("usuariosCliente.txt", std::ios::app);
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
        senha = encrypit(senha);
        std::cout << "Digite o email: ";
        std::cin >> email;
        cnpj = validar_cnpj();
        cep = validar_cep();
    
          std::ofstream arquivo("usuariosLojas.txt", std::ios::app);
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
    std::cout << "Digite uma senha válidas: ";

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
         for(int i = 0; (i < 100 && senha[i] != '\0'); i++)
            senha[i] = senha[i] + 2;

    return senha;
}


std::string Registro::validar_cep(){
  int i, j;
  std::string cep;

  while (true) {
    i = 0;
    j = 0;
    std::cout << "Digite um CEP válido: ";
    std::cin >> cep;

    for(char c : cep){
        i++;

        if(std::isdigit(c)){
         j++;
        }
    }

    if (i == 8 && j == i) {
        
        return cep;
        break;
    }
    std::cout << "CEP inválido, necessário ter 8 dígitos" << std::endl;
 }

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