#include "carrinho.cpp"
#include "login.cpp"
#include "produto.cpp"
#include "registro.cpp"
#include "usuario.cpp"
#include <iostream>

int main(){
    std::string comando,comando_auxiliar;
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

        std::cout << "ja possui cadastro?"<<std::endl;
        std::cin >> comando_auxiliar;
        //comando_auxiliar = trata_string(comando_auxiliar);
        if(comando_auxiliar == "sair"){
        exit(0);
        }
        if (comando_auxiliar == "sim" || comando_auxiliar == "s"){
            Login log;

                std::cout << "Digite o nome de usuario: ";
                std::cin >> nome;
                std::cout << "Digite a senha: ";
                std::cin >> senha;
                log.autenticarCliente(nome, senha);

        }
        if (comando_auxiliar == "não" || comando_auxiliar == "nao" || comando_auxiliar == "n"){
            Registro novo_cliente;
                novo_cliente.cadastrarCliente();
        }
        
        cliente_main(nome);
    }
    if(comando == "gerente"){

            std::cout<<"ja possui cadastro?"<<std::endl;
            std::cin >> comando_auxiliar;
            //comando_auxiliar = trata_string(comando_auxiliar);
            if(comando_auxiliar == "sair"){
            exit(0);
            }
            if (comando_auxiliar == "sim" || comando_auxiliar == "s"){
                Login log;
                
                    std::cout << "Digite o nome da loja: ";
                    std::cin >> nome;
                    std::cout << "Digite a senha: ";
                    std::cin >> senha;
                    log.autenticarLoja(nome, senha);
                
                
            }
            if(comando_auxiliar == "não" || comando_auxiliar == "n" || comando_auxiliar == "nao"){
                Registro novo_cliente;
                novo_cliente.cadastrarLoja();
            }
            
            loja_main(nome);
    }
    //if(comando != "gerente" || comando != "cliente"){
    //    std::cout << "Erro! Escolha somente entre 'gerente' ou 'cliente'!" << std::endl;
    //}

    return 0;
}
