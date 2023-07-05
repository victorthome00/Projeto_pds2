#include "carrinho.cpp"
#include "login.cpp"
#include "produto.cpp"
#include "registro.cpp"
#include "usuario.cpp"
#include <iostream>

int main(){
    std::string comando,comando_auxiliar;
    do{
    std::cout << "Digite 'sair' a qualquer momento para encerrar a sessao" << std::endl;
    std::cout << "Digite 'cliente' caso deseje entrar como cliente" << "\n" << "Digite 'gerente' para gerenciar seus produtos disponiveis" << std::endl;
    std::cin >> comando;
    std::cin.ignore();
    std::string nome, senha;
    //comando = trata_string(comando);
    if(comando == "sair"){
        exit(0);
    }
    if(comando == "cliente"){
        do{
        std::cout << "ja possui cadastro?"<<std::endl;
        std::cin >> comando_auxiliar;
        //comando_auxiliar = trata_string(comando_auxiliar);
        if(comando_auxiliar == "sair"){
        exit(0);
        }
        if (comando_auxiliar == "sim" || comando_auxiliar == "s"){
            Login log;
            do{
                std::cout << "Digite o nome de usuario: ";
                std::cin >> nome;
                std::cout << "Digite a senha: ";
                std::cin >> senha;
                log.autenticarCliente(nome, senha);
            } while (!log.autenticarCliente(nome, senha));
        }
        }while(comando_auxiliar != "sim" || comando_auxiliar != "s" || comando_auxiliar != "não" || comando_auxiliar != "n" || comando_auxiliar != "nao");
        cliente_main(nome);
    }
    if(comando == "gerente"){
        do{
            std::cout<<"ja possui cadastro?"<<std::endl;
            std::cin >> comando_auxiliar;
            //comando_auxiliar = trata_string(comando_auxiliar);
            if(comando_auxiliar == "sair"){
            exit(0);
            }
            if (comando_auxiliar == "sim" || comando_auxiliar == "s"){
                Login log;
                do{
                    std::cout << "Digite o nome da loja: ";
                    std::cin >> nome;
                    std::cout << "Digite a senha: ";
                    std::cin >> senha;
                    log.autenticarLoja(nome, senha);
                } while (!log.autenticarLoja(nome, senha));
                
            }
            if(comando_auxiliar == "não" || comando_auxiliar == "n" || comando_auxiliar == "nao"){
                Registro novo_cliente;
                novo_cliente.cadastrarLoja();
            }
            }while(comando_auxiliar != "sim" || comando_auxiliar != "s" || comando_auxiliar != "não" || comando_auxiliar != "n" || comando_auxiliar != "nao");
            loja_main(nome);
    }
    if(comando != "gerente" || comando != "cliente"){
        std::cout << "Erro! Escolha somente entre 'gerente' ou 'cliente'!" << std::endl;
    }
    }while(comando != "cliente" || comando != "gerente");
    return 0;
}
