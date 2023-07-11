#include "carrinho.hpp"
#include "login.hpp"
#include "produto.hpp"
#include "registro.hpp"
#include "usuario.hpp"
#include <iostream>

int main(){
    std::string comando,comando_auxiliar;
   // do{
    std::cout << "Digite 'sair' a qualquer momento para encerrar a sessao" << std::endl;
    std::cout << "Digite 'cliente' caso deseje entrar como cliente" << "\n" << "Digite 'gerente' para gerenciar seus produtos disponiveis" << std::endl;
    std::cin >> comando;
    std::cin.ignore();
    std::string nome;
    std::string senha;
    //comando = trata_string(comando);
    if(comando == "sair"){
        exit(0);
    }
    if(comando == "cliente"){

        while(true){
            std::cout<<"ja possui cadastro? (sim/nao)"<<std::endl;
            std::cin >> comando_auxiliar;

            if(comando_auxiliar == "sair"){
            exit(0);
            }

            if (comando_auxiliar == "sim" || comando_auxiliar == "s"){
                Login log;

                while(true){
                    std::cout << "Digite o nome de usuario: " << std::endl;
                    std::cin >>nome;
                    std::cout << "Digite a senha: " << std::endl;
                    std::cin >>senha;

                    if(log.autenticarCliente(nome,senha)){
                        break;
                    }
                    std::cout << "Erro na autenticacao" << '\n' << std::endl;
                    
                }
                std::cout<<"Autenticacao concluida"<<std::endl;
                std::cout <<'\n';
                cliente_main(nome);
            }
            if(comando_auxiliar == "não" || comando_auxiliar == "n" || comando_auxiliar == "nao"){
                Registro novo_cliente;
                novo_cliente.cadastrarCliente();

                Login log;
                    while(true){
                    std::cout << "Faca o login para a confirmação da conta.\n";
                    std::cout << "Digite o nome de usuario: " << std::endl;
                    std::cin >>nome;
                    std::cout << "Digite a senha: " << std::endl;
                    std::cin >>senha;

                    if(log.autenticarCliente(nome,senha)){
                        break;
                    }
                    std::cout << "Erro na autenticacao" << '\n' << std::endl;
                    
                }
                std::cout<<"Autenticacao concluida"<<std::endl;
                std::cout <<'\n';
                cliente_main(nome);

            }
            break;
    }
            
    
    
}
    if(comando == "gerente"){

        while(true){
            std::cout<<"ja possui cadastro? (sim/nao)"<<std::endl;
            std::cin >> comando_auxiliar;

            if(comando_auxiliar == "sair"){
            exit(0);
            }

            if (comando_auxiliar == "sim" || comando_auxiliar == "s"){
                Login log;

                while(true){
                    std::cout << "Digite o nome da loja: ";
                    std::cin >> nome;
                    std::cout << "Digite a senha: ";
                    std::cin >> senha;

                        if(log.autenticarLoja(nome, senha)){
                            break;
                        }
                    std::cout << "Erro na autenticacao" <<std::endl;
                }
                std::cout<<"Autenticação concluida"<<std::endl;
                std::cout <<'\n';
                loja_main(nome);
            }
            if(comando_auxiliar == "não" || comando_auxiliar == "n" || comando_auxiliar == "nao"){
                Registro novo_cliente;
                novo_cliente.cadastrarLoja();

                Login log;
                     while(true){
                    std::cout << "Faca o login para a confirmação da conta.\n";
                    std::cout << "Digite o nome da loja: ";
                    std::cin >> nome;
                    std::cout << "Digite a senha: ";
                    std::cin >> senha;

                        if(log.autenticarLoja(nome, senha)){
                            break;
                        }
                    std::cout << "Erro na autenticacao" <<std::endl;
                }
                std::cout<<"Autenticação concluida"<<std::endl;
                std::cout <<'\n';
                loja_main(nome);

            }
            break;
    }
            
    
    return 0;
}
}