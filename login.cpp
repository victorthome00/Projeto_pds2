#include "login.hpp"
#include <iostream>
#include <fstream>
#include <vector>

bool Login::autenticarCliente(std::string nome, std::string senha)
{
    senha = encrypit(senha);
    std::cout << senha << std::endl;
    std::string linha;
    bool encontrada = false;
    
    std::ifstream arquivo("usuariosClientes.txt", std::ios::binary | std::ios::in);
    if (arquivo.is_open())
    {
        std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo;
        while (std::getline(arquivo, linha))
        {
            size_t pos = linha.find(nome);

            if (pos != std::string::npos)
            {
                encontrada = true;
                break;
            }
        }

        if (encontrada)
        {
            std::getline(arquivo, linha);
            {
                senhaArquivo = linha;
            }
        }

        if (senha == senhaArquivo)
        {
            arquivo.close();
            std::cout << "Login do cliente realizado com sucesso!" << std::endl;
            return true;
        }
    }
    arquivo.close();
    std::cout << "Falha na realizacao do login do cliente!" << std::endl;
    std::cout << '\n';

    return false;
}

bool Login::autenticarLoja(std::string nome, std::string senha)
{
    senha = encrypit(senha);
    std::string linha;
    bool encontrada = false;

    std::ifstream arquivo("usuariosLoja.txt", std::ios::binary | std::ios::in);
    if (arquivo.is_open())
    {
        std::string nomeArquivo, senhaArquivo, emailArquivo, cpfArquivo;
        while (std::getline(arquivo, linha))
        {
            size_t pos = linha.find(nome);

            if (pos != std::string::npos)
            {
                encontrada = true;
                break;
            }
        }

        if (encontrada)
        {
            std::getline(arquivo, linha);
            {
                senhaArquivo = linha;
            }
        }

        if (senha == senhaArquivo)
        {
            arquivo.close();
            std::cout << "Login da loja realizado com sucesso!" << std::endl;
            return true;
        }
    }
        arquivo.close();
        std::cout << "Falha na realização do login da loja!" << std::endl;
    
    return false;
}

std::string Login::encrypit(std::string &senha)
{
    for (int i = 0; (i < 100 && senha[i] != '\0'); i++)
    {
        senha[i] = senha[i] + 2;
    }
    return senha; // wddadad
}
